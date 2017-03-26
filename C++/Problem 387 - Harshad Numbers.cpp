#include <iostream>
#include <vector>
#include <list>
#include <cmath>
#include <algorithm>


struct PrimeChecker
{
public:
	PrimeChecker(long long maxPrime);
	bool isPrime(long long n) const;
private:
	std::list<long long> primes;
};

long long getDigitSum(long long n)
{
	long long digitSum = 0;
	while(n > 0)
	{
		digitSum += n % 10;
		n /= 10;
	}
	return digitSum;
}

bool isHarshad(long long n)
{
	return n % getDigitSum(n) == 0;
}

bool isStrong(long long n, const PrimeChecker& checker)
{
	return checker.isPrime(n / getDigitSum(n));
}


int main()
{
	const long long max = 100'000'000'000'000;
	int maxDepth = std::log10(max);
	long long sum = 0;
	PrimeChecker checker(max);
	std::list<long long> harshads(9);
	std::iota(harshads.begin(), harshads.end(), 1);
	int depth=1;		
	while(depth++ < maxDepth)
	{
		std::list<long long> newHarshads;
		for(long long harshad : harshads)
		{
			bool strongFlag = isStrong(harshad, checker);
			for(long long digit = 0; digit < 10; digit++)
			{
				auto candidate = harshad * 10 + digit;
				if(isHarshad(candidate))
					newHarshads.push_back(candidate);
				else
					if(depth > 2 && strongFlag)
						if(checker.isPrime(candidate))
							sum+=candidate;	
			}
		}
		harshads=newHarshads;
	}
	std::cout << sum << std::endl;

	return 0;
}

PrimeChecker::PrimeChecker(long long maxPrime)
{
	std::vector<bool> sieve(std::sqrt(maxPrime)+1, true);
	std::size_t index = 2;
	while(index < sieve.size())
	{
		for(std::size_t i = index * 2; i < sieve.size(); i += index)
			sieve[i] = false;				
		do
			index++;
		while(!sieve[index]);
	}
	for(std::size_t i = 2; i < sieve.size(); i++)
		if(sieve[i])
			primes.push_back(i);
}

bool PrimeChecker::isPrime(long long n) const
{
	return std::all_of(primes.begin(), std::upper_bound(primes.begin(), primes.end(), std::sqrt(n)), [=](long long prime){ return n % prime != 0;});
}
