#pragma once
#include <iostream>
#include <list>
#include <unordered_set>
#include <vector>
#include <type_traits>

template<typename T, typename = std::enable_if_t<std::is_integral<T>::value>>
struct SimplePrimes
{
	SimplePrimes(T bound)
	{
		std::vector<bool> sieve(bound, true);
		std::size_t index = 2;
		while(index < sieve.size() / 2)
		{
			for(std::size_t i = index * 2; i < sieve.size(); i += index)
				sieve[i] = false;
			while(!sieve[++index]){}
		}
		for(std::size_t i = 2; i < sieve.size(); i++)
			if(sieve[i])
				list.push_back(i);
	}
	std::list<T> list;
};


