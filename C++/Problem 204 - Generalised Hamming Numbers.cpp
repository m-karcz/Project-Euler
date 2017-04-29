#include <iostream>

int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

long long Hammings(long long num, auto begin, auto end)
{
	if(num > 1'000'000'000LL)
		return 0;
	long long sum = 1;
	for(auto it = begin; it != end; ++it)
		sum += Hammings(num * (*it), it, end);
	return sum;
}

int main()
{
	std::cout << Hammings(1, std::begin(primes), std::end(primes)) << std::endl;
}
