#include <iostream>
#include <vector>

int main()
{
	constexpr std::size_t size = 50;
	std::vector<long long> values(size+5, 0);
	values[0] = 1;
	for(std::size_t i = 0; i < size; i++)
		for(std::size_t j : {1,2,3,4})
			values[i+j] += values[i];
	std::cout << values[size] << std::endl;

}

