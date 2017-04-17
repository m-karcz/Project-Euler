#include <iostream>
#include "Sieve.hpp"
#include <utility>
#include <algorithm>

int main()
{
	std::vector<std::pair<int, int>> radicals;
	const std::size_t cap = 100'000;
	SimplePrimes<int> primes(cap);
	radicals.reserve(cap);
	radicals.push_back({1,1});
	for(int i = 2; i <= cap; i++)
	{
		int n = i, total = 1;
		for(auto it = primes.list.begin(); *it <= n; ++it)
		{
			if(n % *it == 0)
			{
				total *= *it;
				while(n % *it == 0)
					n /= *it;
			}
		}
		radicals.push_back({i,total});
	}
	std::sort(radicals.begin(), radicals.end(), [](auto&& a, auto&& b){
		return a.second < b.second ? true : a.second == b.second ? a.first < b.first : false;
	});
	std::cout << radicals[9999].first << std::endl;
	return 0;
}
