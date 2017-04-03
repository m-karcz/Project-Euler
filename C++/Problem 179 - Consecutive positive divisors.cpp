#include <iostream>
#include <unordered_map>
#include <map>
#include <list>
#include <vector>
#include <cmath>
#include <algorithm>

struct Primes
{
	Primes(int bound)
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
		std::cout << "end of generating" << std::endl;
	}
	std::list<int> list;
};


void proceed(std::vector<int>& amountOfDivisors, long value, long max, std::list<int>::iterator it, std::list<int>::iterator end, std::map<int, int>& divisors)
{
	for(;value * (*it) <= max && it != end; ++it)
	{
		long newValue = value * (*it);
		divisors[*it]++;
		amountOfDivisors[newValue] = std::accumulate(divisors.begin(), divisors.end(), 1, [](int sum, const std::pair<int, int>& pair){ return sum * (1 + pair.second); });
		proceed(amountOfDivisors, newValue, max, it, end, divisors);
		divisors[*it]--;
		if(divisors[*it] == 0)
			divisors.erase(*it);
	}
}

int main()
{
	const int max = 10'000'000;
	Primes primes(max);
	std::vector<int> amountOfDivisors(max, 0);
	std::cout << amountOfDivisors.size() << std::endl;
	int consecutives = 0;
	std::map<int, int> divisors;
	proceed(amountOfDivisors, 1, max, primes.list.begin(), primes.list.end(), divisors);
	for(std::size_t i = 3; i < amountOfDivisors.size(); ++i)
		if(amountOfDivisors[i - 1] == amountOfDivisors[i])
			consecutives++;
	std::cout << consecutives << std::endl;

}
