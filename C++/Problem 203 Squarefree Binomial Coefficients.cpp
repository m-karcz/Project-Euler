#include "Sieve.hpp"
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <cmath>

template<typename T>
std::set<T> getDistinctCoefficients(T level)
{
	if(level < 2)
		return {1};
	else
	{
		std::set<T> coefficients{1};
		std::vector<T> line{1,1};
		for(int actualLevel = 3; actualLevel <= level; actualLevel++)
		{
			std::vector<T> nextLine{1};
			nextLine.reserve(actualLevel);
			for(int i = 1; i < line.size(); i++)
					nextLine.push_back(line[i-1]+line[i]);
			nextLine.push_back(1);
			line = nextLine;
			coefficients.insert(line.cbegin() + 1, line.cend() -1);
		}
		return coefficients;
	}
}

int main()
{
	auto coefficients = getDistinctCoefficients(51L);
	long sum = 0;
	auto i = 0;
	SimplePrimes<long> primes(std::sqrt(*coefficients.rbegin())+1);
	for(const auto coeff : coefficients)
	{
		auto isOk = true;
		auto coeffCpy = coeff;
		for(const auto prime : primes.list)
		{
			if(coeffCpy < prime)
				break;
			if(coeffCpy % prime == 0)
			{
				coeffCpy /= prime;
				if(coeffCpy % prime == 0)
				{
					isOk = false;
					break;
				}	
			}
		}
		if(isOk)
			sum += coeff;
	}
	std::cout << sum << std::endl;
}
