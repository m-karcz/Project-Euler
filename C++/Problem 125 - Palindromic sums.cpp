#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <string>
#include <set>

bool isPalindromic(long long n)
{
	auto str = std::to_string(n);
	std::reverse(str.begin(), str.end());
	return str == std::to_string(n);
}

int main()
{
	constexpr long long maxSqr = 100'000'000;
	std::vector<long long> lut;
	long long sum = 0;
	std::set<long long> taken;
	for(long long i = 0; (i-1)*(i-1) < maxSqr; i++)
		lut.push_back(i*i);
	for(long long nn = 1; lut[nn] < maxSqr; nn++)
	{
		long long n = lut[nn];
		for(long long i = nn+1;; i++)
		{
			n += lut[i];
			if(n >= maxSqr)
				break;
			if(isPalindromic(n))
				if(taken.find(n) == taken.end())
				{
					sum += n;
					taken.insert(n);
				}
		}
	}
	std::cout << sum << std::endl;
}
