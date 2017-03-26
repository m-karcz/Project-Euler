#include <iostream>
#include <list>
#include <unordered_set>
#include <vector>
#include <type_traits>
#include <cmath>
#include <chrono>

template<typename T>
class BetterPrimes
{
public:
	BetterPrimes(int n)
	{
		static_assert(std::is_integral<T>::value, "not integral type for BetterPrimes!");
		std::vector<bool> sieve(n);
		for(std::size_t i=2; i < n/2; i++)
		{
			for(std::size_t x=2*i; x < n; x+=i)
			{
				sieve[x]=true;
			}
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
	std::list<T> list;
	std::unordered_set<T> set;
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

int truncate(int a, int b)
{
	return stoi(std::to_string(a)+std::to_string(b));
}

bool check(BetterPrimes<int>& primes, const std::initializer_list<int>& values, int new_one)
{
	for(int value : values)
		if(!primes.is_prime(truncate(value, new_one)) || !primes.is_prime(truncate(new_one, value)))
			return false;
	return true;	
}

int main()
{
	using namespace std::chrono;
	auto start_time=high_resolution_clock::now();
	BetterPrimes<int> primes(1000);
	bool found=false;
	auto it1=next(next(next(primes.list.begin())));
	while(!found)
	{
		if(it1==primes.list.end())
		{
			--it1;
			primes.get_next();
			++it1;
		}
		for(auto it2=primes.list.begin(); it2!=it1; ++it2)
			if(check(primes, {*it1}, *it2))
				for(auto it3=next(it2); it3!=it1; ++it3)
					if(check(primes, {*it1, *it2}, *it3))
						for(auto it4=next(it3); it4!=it1; ++it4)
							if(check(primes, {*it1, *it2, *it3}, *it4))
							for(auto it5=next(it4); it5!=it1; ++it5)
								if(check(primes, {*it1, *it2, *it3, *it4}, *it5))
								{
									std::cout << "Primes: " << *it1 << " " << *it2 << " " << *it3 << " " << *it4 << " " << *it5 << std::endl;
									std::cout << "Sum: " << *it1 + *it2 + *it3 + *it4 + *it5 << std::endl;
									std::cout << "Time: " << duration_cast<seconds>(high_resolution_clock::now()-start_time).count() << std::endl;
									return 0;
								}

		++it1;
	}
}
