#include <iostream>
#include <array>
#include <vector>
#include <list>
#include <numeric>
#include <map>
#include <unordered_map>
#include <boost/range/algorithm.hpp>
#include <boost/range/numeric.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/range/adaptors.hpp>
#include <chrono>

int get_factorial(int i)
{
	constexpr int tab[10]{1,1,2,6,24,120,720,5040,40320,362880};
	return tab[i];
}

int main()
{
	int max=1000000;
	std::unordered_map<int, int> loops;
	loops[169]=3;
	loops[363601]=3;
	loops[1454]=3;
	loops[871]=2;
	loops[872]=2;
	loops[45361]=2;
	loops[45362]=2;
	loops[0]=2;
	loops[1]=1;
	loops[2]=1;
	int sum=0;
	for(int i=3; i<1000000; i++)
	{
		std::list<int> to_put;
		int value=i;
		int path=-1;
		while(loops.find(value)==loops.end())
		{
			to_put.push_back(value);
			int new_value=boost::accumulate(std::to_string(value) | boost::adaptors::transformed([](char c)->int{return get_factorial( c - '0');}),0);
			if(new_value==value)
			{
				loops[value]=1;
				path=2;
				to_put.pop_back();
				break;
			}
			else
			{
				value=new_value;
			}
		}
		if(path==-1)
			path=loops[value]+1;
		for(auto it=to_put.rbegin(); it!=to_put.rend(); ++it, ++path)
		{
			loops[*it]=path;
			if(path==60 && *it<1000000)
				sum++;
		}
	}
	std::cout << sum << std::endl;
}
