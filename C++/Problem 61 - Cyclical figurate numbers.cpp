#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <array>
#include <set>

std::vector<int> generate(std::function<int(int)> func)
{
	std::vector<int> vect;
	int n=1;
	while(func(n) < 1000)
		n++;
	while(true)
	{
		int value=func(n++);
		if(value < 10000)
			vect.push_back(value);
		else
			return vect;
	}
}


int main()
{
	std::array<std::vector<int>, 6> polygonals;
	std::array<std::size_t, 6> indexes{0,1,2,3,4,5};
	polygonals[0]=generate([](int n){return n*(n+1)/2;});
	polygonals[1]=generate([](int n){return n*n;});
	polygonals[2]=generate([](int n){return n*(3*n-1)/2;});
	polygonals[3]=generate([](int n){return n*(2*n-1);});
	polygonals[4]=generate([](int n){return n*(5*n-3)/2;});
	polygonals[5]=generate([](int n){return n*(3*n-2);});
	do
	{
		for(auto it3=polygonals[indexes[0]].begin(); it3!=polygonals[indexes[0]].end(); ++it3)
		{
			auto it4end=std::upper_bound(polygonals[indexes[1]].begin(), polygonals[indexes[1]].end(), ((*it3)%100)*100+99);
			for(auto it4=std::lower_bound(polygonals[indexes[1]].begin(), polygonals[indexes[1]].end(), ((*it3)%100)*100); it4!=it4end; ++it4)
			{
				auto it5end=std::upper_bound(polygonals[indexes[2]].begin(), polygonals[indexes[2]].end(), ((*it4)%100)*100+99);
				for(auto it5=std::lower_bound(polygonals[indexes[2]].begin(), polygonals[indexes[2]].end(), ((*it4)%100)*100); it5!=it5end; ++it5)
				{
					auto it6end=std::upper_bound(polygonals[indexes[3]].begin(), polygonals[indexes[3]].end(), ((*it5)%100)*100+99);
					for(auto it6=std::lower_bound(polygonals[indexes[3]].begin(), polygonals[indexes[3]].end(), ((*it5)%100)*100); it6!=it6end; ++it6)
					{
						auto it7end=std::upper_bound(polygonals[indexes[4]].begin(), polygonals[indexes[4]].end(), ((*it6)%100)*100+99);
						for(auto it7=std::lower_bound(polygonals[indexes[4]].begin(), polygonals[indexes[4]].end(), ((*it6)%100)*100); it7!=it7end; ++it7)
						{
							auto it8end=std::upper_bound(polygonals[indexes[5]].begin(), polygonals[indexes[5]].end(), ((*it7)%100)*100+99);
							for(auto it8=std::lower_bound(polygonals[indexes[5]].begin(), polygonals[indexes[5]].end(), ((*it7)%100)*100); it8!=it8end; ++it8)
							{
								if(*it3 / 100==*it8 % 100)
								{
									std::set<int> uniques{*it3, *it4, *it5, *it6, *it7, *it8};
									if(uniques.size()==6)
									{
										std::cout << *it3 << " " << *it4 << " " << *it5 << " " << *it6 << " " << *it7 << " " << *it8 << std::endl;
										std::cout << "Sum: " << *it3 + *it4 + *it5 + *it6 + *it7 + *it8 << std::endl;
										return 0;
									}
								}
							}
						}
					}
				}
			}
		}
	}while(std::next_permutation(indexes.begin(), indexes.end()));
}
