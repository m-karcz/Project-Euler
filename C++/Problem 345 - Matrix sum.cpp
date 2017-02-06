#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <list>
#include <boost/algorithm/string.hpp>
#include <boost/range/adaptors.hpp>
#include <boost/range/algorithm.hpp>
#include <boost/range/irange.hpp>
#include <typeinfo>
#include <limits>

enum class Cost
{
	Max,
	Min
};

enum class Reduce
{
	FirstRow,
	FirstColumn
};


template<Cost C, Reduce R>
class HungarianMethod
{
	struct Element
	{
		Element(const std::string& value) : value(std::stoi(value)) {}
		Element(int value) : value(value) {}
		int value;
		bool mark=false;
	};


	struct XY
	{
		XY(int x, int y):x(x),y(y){}
		int x;
		int y;
	};
	template <typename T>
	using grid_type=std::vector<std::vector<T>>;
public:
	HungarianMethod(const std::string& input);
	void print();
	void proceed();
	int get_cost()
	{
		return std::accumulate(assigned.begin(), assigned.end(), 0, [this](auto& sum, auto& point){ return sum+initial_grid[point.y][point.x]; });
	}
private:
	void reduce();
	void reverse();
	void prepare();
	void reduce_rows();
	void reduce_cols();
	int mark_zeroes();
	void prepare_cross();
	void reduce_after_crossing(int difference);
	grid_type<Element> grid;
	grid_type<int> initial_grid;
	grid_type<int> cross;
	std::list<int> unmarked_cols;
	std::list<int> unmarked_rows;
	int size;
	std::list<XY> assigned;
};

template<Cost C, Reduce R>
HungarianMethod<C, R>::HungarianMethod(const std::string& input)
{
	std::vector<std::string> lines;
	boost::split(lines, input, boost::is_any_of("\n"), boost::token_compress_on);
	size=lines.size();
	for(auto& line : lines)
	{
		std::vector<std::string> str_numbers;
		boost::split(str_numbers, line, boost::is_any_of(" "), boost::token_compress_on);
		grid.emplace_back(std::accumulate(str_numbers.begin(), str_numbers.end(), std::vector<Element>{}, [](std::vector<Element> vect, std::string str)
			{
				vect.emplace_back(str);
				return vect;	
			}));
		cross.emplace_back(std::vector<int>(size));
	}
	for(auto& line : grid)
	{
		std::vector<int> values;
		for(auto& el : line)
		{
			values.emplace_back(el.value);
		}
		initial_grid.emplace_back(std::move(values));
	}
	
}

template<Cost C, Reduce R>
void HungarianMethod<C,R>::reduce_rows()
{
	for(auto& row : grid)
	{
		int min_val=std::min_element(row.begin(), row.end(), [](const Element& e1, const Element& e2){ return e1.value < e2.value; })->value;
		for(Element& el : row)
			el.value-=min_val;
	}
}

template<Cost C, Reduce R>
void HungarianMethod<C, R>::reduce_cols()
{
	for(int x : boost::irange(0, size))
	{
		int min_val=(*std::min_element(grid.begin(), grid.end(), [x](std::vector<Element>& v1, std::vector<Element>& v2){ return v1[x].value < v2[x].value; }))[x].value;
		for(std::vector<Element>& col : grid)
			col[x].value-=min_val;
	}
}

template<Cost C, Reduce R>
void HungarianMethod<C, R>::print()
{
	
	for(auto& line : grid)
	{
		for(auto& el : line)
		{
			std::cout << (el.mark ? "*" : std::to_string(el.value)) << "\t";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl << std::endl;
}

template<Cost C, Reduce R>
int HungarianMethod<C, R>::mark_zeroes()
{
	int marked=0;
	unmarked_rows=std::list<int>(grid.size());
	unmarked_cols=std::list<int>(grid.size());
	std::iota(unmarked_rows.begin(), unmarked_rows.end(), 0);
	std::iota(unmarked_cols.begin(), unmarked_cols.end(), 0);
	bool marked_anything=true;
	while(marked_anything && marked!=grid.size())
	{
		marked_anything=false;
		std::list<XY> to_remove;
		for(int y : unmarked_rows)
		{
			std::list<int> zeroes;
			for(int x : unmarked_cols)
			{
				if(grid[y][x].value==0)
				{
					zeroes.push_back(x);
				}
			}
			if(zeroes.size()==1)
			{
				marked_anything=true;
				marked++;
				grid[y][zeroes.front()].mark=true;
				to_remove.emplace_back(zeroes.front(), y);
				break;
			}
		}
		if(!marked_anything)
		{
			for(int x : unmarked_cols)
			{
				std::list<int> zeroes;
				for(int y : unmarked_rows)
				{
					if(grid[y][x].value==0)
					{
						zeroes.push_back(y);
					}
				}
				if(zeroes.size()==1)
				{
					marked_anything=true;
					marked++;
					grid[zeroes.front()][x].mark=true;
				to_remove.emplace_back(x, zeroes.front());
				break;
				}
			}
		}
		for(XY point : to_remove)
		{
			unmarked_cols.remove(point.x);
			unmarked_rows.remove(point.y);
		}
		
	}
	return marked;
}

template<Cost C, Reduce R>
void HungarianMethod<C, R>::prepare_cross()
{
	for(auto& line : cross)
	{
		for(int& val : line)
		{
			val=-1;
		}
	}
	std::vector<bool> marked_rows(grid.size());
	std::vector<bool> marked_cols(grid.size());
	std::fill(marked_rows.begin(), marked_rows.end(), false);
	std::fill(marked_cols.begin(), marked_cols.end(), false);
	bool changed=true;
	while(changed)
	{
		changed=false;
		for(int y : boost::irange(0, size))
		{
			bool found_marked=false;
			bool found_zero=false;
			for(int x : boost::irange(0, size))
			{
				if(marked_cols[x]==false && grid[y][x].mark==true)
				{
					found_marked=true;
					break;
				}
				if(marked_cols[x]==false && grid[y][x].value==0)
				{
					found_zero=true;
				}
			}
			if(found_marked==false && found_zero)
			{
				marked_rows[y]=true;
				changed=true;
				std::list<int> cols_to_mark;
				for(int x : boost::irange(0, size))
				{
					if(grid[y][x].value==0)
					{
						grid[y][x].mark=true;
						if(marked_cols[x]==false)
							cols_to_mark.push_back(x);
					}
				}
				
				for(int x : cols_to_mark)
				{
					marked_cols[x]=true;
					for(int y : boost::irange(0, size))
					{
						if(grid[y][x].mark==true)
						{
							marked_rows[y]=true;
						}
					}
				}
			}
			if(changed)
				break;
		}
	}
	for(int y : boost::irange(0, size))
	{
		for(int x : boost::irange(0, size))
		{
			if(marked_rows[y]==false)
			{
				cross[y][x]++;
			}
			if(marked_cols[x]==true)
			{
				cross[y][x]++;
			}
		}
	}
}

template<Cost C, Reduce R>
void HungarianMethod<C, R>::reduce_after_crossing(int difference)
{
	int min_val=std::numeric_limits<int>::max();
	for(int y : boost::irange(0, size))
	{
		for(int x : boost::irange(0, size))
		{
			if(cross[y][x]==-1)
			{
				min_val=std::min(min_val, grid[y][x].value);	
			}
		}
	}
	for(int y : boost::irange(0, size))
	{
		for(int x : boost::irange(0, size))
		{
			grid[y][x].value+=cross[y][x]*difference*min_val;
			grid[y][x].mark=false;
		}
	}
	
}

template<Cost C, Reduce R>
void HungarianMethod<C, R>::proceed()
{
	prepare();
	while(true)
	{
		reduce();
		int marked=mark_zeroes();
		if(marked==size)
		{
			for(int y : boost::irange(0, size))
				for(int x : boost::irange(0, size))
					if(grid[y][x].mark)
						assigned.emplace_back(x,y);
			return;
		}
		prepare_cross();
		reduce_after_crossing(size-marked);
	}
}

template<Cost C, Reduce R>
void HungarianMethod<C, R>::reverse()
{
	for(auto& line : grid)
	{
		int max_val=std::max_element(line.begin(), line.end(), [](const auto& a, const auto& b){ return a.value < b.value;})->value;
		for(auto& el : line)
		{
			el.value = max_val-el.value;
		}
	}
}


template<>
void HungarianMethod<Cost::Max, Reduce::FirstColumn>::prepare()
{
	reverse();
}

template<>
void HungarianMethod<Cost::Max, Reduce::FirstRow>::prepare()
{
	reverse();
}

template<>
void HungarianMethod<Cost::Min, Reduce::FirstColumn>::prepare()
{
}
	
template<>
void HungarianMethod<Cost::Min, Reduce::FirstRow>::prepare()
{
}
template<>
void HungarianMethod<Cost::Max, Reduce::FirstColumn>::reduce()
{
	reduce_cols();
	reduce_rows();
}

template<>
void HungarianMethod<Cost::Min, Reduce::FirstColumn>::reduce()
{
	reduce_cols();
	reduce_rows();
}

template<>
void HungarianMethod<Cost::Max, Reduce::FirstRow>::reduce()
{
	reduce_rows();
	reduce_cols();	
}

template<>
void HungarianMethod<Cost::Min, Reduce::FirstRow>::reduce()
{
	reduce_rows();
	reduce_cols();	
}

int main()
{
	HungarianMethod<Cost::Max, Reduce::FirstColumn> hung(R"(7 53 183 439 863 497 383 563 79 973 287 63 343 169 583
627 343 773 959 943 767 473 103 699 303 957 703 583 639 913
447 283 463 29 23 487 463 993 119 883 327 493 423 159 743
217 623 3 399 853 407 103 983 89 463 290 516 212 462 350
960 376 682 962 300 780 486 502 912 800 250 346 172 812 350
870 456 192 162 593 473 915  45 989 873 823 965 425 329 803
973 965 905 919 133 673 665 235 509 613 673 815 165 992 326
322 148 972 962 286 255 941 541 265 323 925 281 601 95 973
445 721 11 525 473 65 511 164 138 672 18 428 154 448 848
414 456 310 312 798 104 566 520 302 248 694 976 430 392 198
184 829 373 181 631 101 969 613 840 740 778 458 284 760 390
821 461 843 513 17 901 711 993 293 157 274 94 192 156 574
34 124 4 878 450 476 712 914 838 669 875 299 823 329 699
815 559 813 459 522 788 168 586 966 232 308 833 251 631 107
813 883 451 509 615 77 281 613 459 205 380 274 302 35 805)");
	hung.proceed();
	std::cout << hung.get_cost() << std::endl;
	return 0;
}
