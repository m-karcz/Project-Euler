#include <iostream>
#include <unordered_set>
#include <list>
#include <vector>
#include <algorithm>
#include <cmath>


template<typename T>
class BetterPrimes
{
public:
	BetterPrimes(int n)
	{
		static_assert(std::is_integral<T>::value, "not integral type for BetterPrimes!");
		std::vector<bool> sieve(n);
		for(std::size_t i=2; i < n/2;)
		{
			for(std::size_t x=i * 2; x < n; x+=i)
			{
				sieve[x]=true;
			}
			i++;
			for(;sieve[i];i++){}
		}
		for(std::size_t i=2; i < sieve.size(); i++)
		{
			if(!sieve[i])
			{
				list.push_back(i);
				set.insert(i);
			}
		}
	}
	bool is_prime(T n)
	{
		while(n > list.back())
			get_next();
		return set.find(n)!=set.end();
	}
	std::list<T> list{2,3,5,7};
	std::unordered_set<T> set{2,3,5,7};
	auto get_next()
	{
		T candidate=list.back();
		while(true)
		{
			candidate+=2;
			if(candidate%5==0)
				continue;
			T sqrt_cand = static_cast<T>(std::sqrt(candidate))+1;
			bool is_ok=true;
			for(auto it=list.begin(); *it < sqrt_cand; ++it)
				if(static_cast<T>(candidate/(*it))*(*it)==candidate)
				{
					is_ok=false;
					break;
				}
			if(!is_ok)
				continue;
			else
			{
				list.push_back(candidate);
				set.insert(candidate);
				return candidate;
			}
		}
	}
};

int main()
{
	long long sum=1;
	const long long max_num=100000000;
	BetterPrimes<long long> primes(max_num+1);
	std::cout << "end of generating primes" << std::endl;
	for(long long n=2; n < max_num; n+=2)
	{
		long long sqrt_n = static_cast<long long>(std::sqrt(n));
		bool is_prime=true;
		for(long long d1=1; d1 < sqrt_n+1; d1++)
		{
			long long d2=n/d1;
			if(d1*d2==n)
			{
				if(!primes.is_prime(d1+d2))
				{
					is_prime=false;
					break;
				}
			}
		}
		if(is_prime)
			sum+=n;
	}
	std::cout << "Sum: " << sum << std::endl;
	return 0;
}
