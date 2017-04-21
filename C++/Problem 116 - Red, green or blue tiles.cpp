#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>

int main()
{
	constexpr int max = 50;
	long long sum = 0;
	for(int length : {2, 3, 4})
	{
		std::list<long long> fib(length, 1);
		for(auto i = length; i <= max; i++)
		{
			fib.front() = fib.front() + fib.back();
			std::rotate(fib.begin(), ++fib.begin(), fib.end());
		}
		sum += (fib.back() - 1);
	}
	std::cout << sum << std::endl;
}
