#include <iostream>
#include <map>

struct Hyperexp
{
	static void Init()
	{
		long long N = 1777;
		//1250000 checked earlier when 8 digits wrap
		for(long long i = 1; i <= 1250000; i++)
		{
			exp2result[i] = N;
			N = (N * 1777) % 100'000'000LL;
		}
	}
	static std::map<long long, long long> exp2result;
	static long long getResultFromExp(long long n)
	{
		return exp2result[n % 1250000];
	}
	static long long Compute(int pot)
	{
		Init();
		long long result = 1777;
		for(int i = 1; i <= pot; i++)
			result = getResultFromExp(result);
		return result;
	}
};

std::map<long long, long long> Hyperexp::exp2result;

int main()
{
	std::cout << Hyperexp::Compute(1855) << std::endl;
}
