#include <iostream>
#include <vector>

std::vector<long long> GetPrimes(int bound)
{
	std::vector<bool> sieve(bound, true);
	sieve[0] = false;
	sieve[1] = false;
	size_t prime = 0;
	std::vector<long long> primes;
	while(prime < sieve.size())
	{
		if(sieve[prime])
		{	
			primes.push_back(prime);
			for(int n = 2 * prime; n < sieve.size(); n += prime)
				sieve[n] = false;
		}
		++prime;
	}
	return primes;

}

int main()
{
	const int bound = 100'000'000;
	const auto primes = GetPrimes(bound);
	int semiprimes = 0;
	for(auto p1 = primes.cbegin(); p1 != primes.cend(); ++p1)
		for(auto p2 = p1; p2 != primes.cend() && ((*p1)*(*p2) < bound); ++p2, ++semiprimes)
			;
	std::cout << semiprimes << std::endl;
}
