#include "PrimeGen.h"
#include <iostream>
#include <list>
#include <cmath>
#include <numeric>
#include <boost/range/numeric.hpp>
#include <boost/range/adaptors.hpp>

int main()
{
	int M=1000000;
	double max_value=0;
	int max_n=0;
	PrimeGen<int> primes;
	while(primes.generate_next() < M+1)
	{}
	for(int n=2; n<=M; n++)
	{
		std::list<double> primes_dividing_n;
		int bound=n;
		for(auto it=primes.begin(); it!=primes.end() && *it<=bound; ++it)
		{
			if(n/(*it)*(*it)==n)
			{
				primes_dividing_n.push_back(*it);
				bound/=*it;
			}
		}
		double value = boost::accumulate(primes_dividing_n | boost::adaptors::transformed([](double p){ return p/(p-1); }), 1.0, std::multiplies<double>());
		if(value > max_value)
		{
			max_value=value;
			max_n=n;
		}
		
	}
	std::cout << max_n << std::endl;
	std::cout << max_value << std::endl;
	return 0;
}
