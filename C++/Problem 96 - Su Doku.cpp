#include <iostream>
#include <list>
#include <vector>
#include <array>
#include <numeric>
#include <fstream>

struct Candidate
{
	Candidate(int x, int y): x(x), y(y) {}
	std::size_t x;
	std::size_t y;
	std::vector<int> possibilities;
	std::size_t proceed=0;
	int get_proceed() const;
};

class Sudoku
{
public:
	Sudoku(const std::array<std::string, 9>& input);
	int proceed();
	void print();
private:
	std::array<std::array<int, 9>, 9> grid;
	std::vector<Candidate> candidates;
	std::size_t index=0;
	bool check(const Candidate& candidate);
};


int main()
{	
	std::ifstream input;
	input.open("txt/Problem96.txt");
	std::array<std::string, 9> grid;
	int sum=0;
	std::string gridnum;
	while(std::getline(input, gridnum))
	{	
		for(std::size_t y=0; y<9; y++)
		{
			std::getline(input, grid[y]);
		}
		Sudoku sudoku(grid);
		sum+=sudoku.proceed();
	}
	std::cout << sum << std::endl;
	return 0;
}

int Candidate::get_proceed() const
{
	return possibilities[proceed];
}

Sudoku::Sudoku(const std::array<std::string, 9>& input)
{
	for(std::size_t y=0; y<9; y++)
	{
		for(std::size_t x=0; x<9; x++)
		{
			int num=input[y][x]-'0';
			grid[y][x]=num;
			if(num==0)
			{
				candidates.emplace_back(x, y);
			}
		}
	}
	std::list<int> one_to_nine(9);
	std::iota(one_to_nine.begin(), one_to_nine.end(), 1);
	for(Candidate& candidate : candidates)
	{
		std::list<int> left_possibilities(one_to_nine.begin(), one_to_nine.end());
		for(std::size_t y=0; y<9; y++)
		{
			left_possibilities.remove(grid[y][candidate.x]);
		}
		for(std::size_t x=0; x<9; x++)
		{
			left_possibilities.remove(grid[candidate.y][x]);
		}
		for(std::size_t xi=0, xoff=(candidate.x/3)*3; xi<3; xi++)
		{
			for(std::size_t yi=0, yoff=(candidate.y/3)*3; yi<3; yi++)
			{
				left_possibilities.remove(grid[yoff+yi][xoff+xi]);
			}
		}
		candidate.possibilities=std::vector<int>(left_possibilities.begin(), left_possibilities.end());
	}
}

int Sudoku::proceed()
{
	while(index<candidates.size())
	{
		Candidate& candidate=candidates[index];
		if(candidate.proceed>=candidate.possibilities.size())
		{
			grid[candidate.y][candidate.x]=0;		
			index--;
			candidate.proceed=0;
			continue;
		}
		if(check(candidate))
		{
			grid[candidate.y][candidate.x]=candidate.get_proceed();
			index++;
		}
		candidate.proceed++;
	}
	return 100*grid[0][0]+10*grid[0][1]+grid[0][2];
}

bool Sudoku::check(const Candidate& candidate)
{
	const int value=candidate.get_proceed();
	for(std::size_t y=0; y<9; y++)
	{
		if(value==grid[y][candidate.x])
		{
			return false;
		}		
	}
	for(std::size_t x=0; x<9; x++)
	{
		if(value==grid[candidate.y][x])
		{
			return false;
		}
	}
	for(std::size_t yi=0, yoff=(candidate.y/3)*3; yi<3; yi++)
	{
		for(std::size_t xi=0, xoff=(candidate.x/3)*3; xi<3; xi++)
		{
			if(value==grid[yoff+yi][xoff+xi])
			{
				return false;
			}
		}
	}
	return true;
}

void Sudoku::print()
{
	std::cout << std::endl;
	for(auto& line : grid)
	{
		for(auto& value : line)
		{
			std::cout << value;
		}
		std::cout << std::endl;
	}
	return;
}

