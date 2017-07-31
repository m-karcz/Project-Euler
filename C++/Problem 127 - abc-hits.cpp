#include <set>
#include <algorithm>
#include <vector>
#include <algorithm>
#include <iostream>
#include <numeric>

struct Primes
{
	Primes(int bound)
	{
		std::vector<bool> sieve(bound, true);
		int prime = 0;
		sieve[0] = false;
		sieve[1] = false;
		while(prime < sieve.size())
		{
			if(sieve[prime])
			{
				list.push_back(prime);
				for(int multiplier = 2 * prime; multiplier < sieve.size(); multiplier += prime)
					sieve[multiplier] = false;
			}
			prime++;
		}
	}
	std::vector<int> list;
};

struct Problem
{
	Problem() : c_max{120000}, primes{c_max}
	{}
	void Solve()
	{
		prime_factors.emplace_back(std::set<int>{});
		prime_factors.emplace_back(std::set<int>{});
		for(int n = 2; n < c_max; n++)
		{
			int i = n;
			prime_factors.emplace_back(std::set<int>{});
			for(auto prime = primes.list.begin(); i > 1; ++prime)
			{
				while(i % (*prime) == 0)
				{
					prime_factors[n].insert(*prime);
					i /= (*prime);
				}
				
			}
		}
		rads.reserve(c_max);
		rads.push_back(1);
		rads.push_back(1);

		for(int i = 2; i < c_max; i++)
			rads.push_back(rad(i));

		int c_sum = 0;

		int b_max = c_max - 3;

		for(long long b = 2; b < b_max; b++)
		{
			for(long long a = 1; a < b && a + b < c_max; a++)
			{
				auto c = a + b;
				if(isRelativelyPrime(a,b))
					if(rads[a]*rads[b]*rads[c] < c)
						if(isRelativelyPrime(a,c))
							if(isRelativelyPrime(b,c))
									c_sum += c;
			}
		}

		std::cout << c_sum << std::endl;
	}
	int c_max;
	Primes primes;
	std::vector<std::set<int>> prime_factors;
	std::vector<long long> rads;
	bool isRelativelyPrime(int a, int b)
	{
		std::vector<int> intersection;
		std::set_intersection(
				prime_factors[a].cbegin(),
				prime_factors[a].cend(),
				prime_factors[b].cbegin(),
				prime_factors[b].cend(),
				std::back_inserter(intersection)
				);
		return intersection.empty();
	}
	int rad(int n)
	{
		return std::accumulate(prime_factors[n].cbegin(), prime_factors[n].cend(), 1, std::multiplies<int>());
	}

};

int main()
{
	Problem pr;
	pr.Solve();
}
