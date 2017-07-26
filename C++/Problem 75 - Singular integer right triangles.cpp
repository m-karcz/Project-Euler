#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	constexpr long L = 1'500'000;
	std::vector<std::uint8_t> triangles(L+1, 0);
	bool not_overflow = true;
	for(long m = 2; not_overflow ;m++)
	{
		not_overflow = false;
		for(long n = 1; n < m; n++)
		{
			auto length = 2 * m * (m + n);
			if(length > L)
				break;
			not_overflow = true;
			if((m - n) % 2 == 1 && std::__gcd(m, n) == 1)
				for(auto total_length = length; total_length <= L; total_length += length)
					triangles[total_length]++;
		}
	}
	std::cout << std::count(triangles.cbegin(), triangles.cend(), 1) << std::endl;
}
