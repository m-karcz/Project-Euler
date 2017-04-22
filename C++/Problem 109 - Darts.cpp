#include <iostream>
#include <list>
#include <utility>
#include <algorithm>
#include <numeric>
#include <set>

int main()
{
	std::list<int> singles(20);
	std::iota(singles.begin(), singles.end(), 1);
	std::list<int> doubles;
	std::list<int> triples;
	for(auto i : singles)
	{
		doubles.push_back(2*i);
		triples.push_back(3*i);
	}
	singles.push_back(25);
	doubles.push_back(50);
	std::list<int> allPossibilities;
	for(auto i : singles)
		allPossibilities.push_back(i);
	for(auto i : doubles)
		allPossibilities.push_back(i);
	for(auto i : triples)
		allPossibilities.push_back(i);
	std::size_t under100 = doubles.size();
	for(auto d : doubles)
		for(auto b = allPossibilities.begin(); b != allPossibilities.end(); ++b)
		{
			for(auto c = b; c != allPossibilities.end(); ++c)
				if(d + *b + *c < 100)
					under100++;
			if(*b + d < 100)
				under100++;
		}
	std::cout << under100 << std::endl;
	
}
