#include <iostream>

int Laminae(int left, int n)
{
	return (n < 3 || left - 4 * n + 4 < 0) ? 0 : (1 + Laminae(left - 4 * n + 4, n - 2));
}

int main()
{
	int sum = 0;
	constexpr int max = 1'000'000;
	int n = 3;
	while(true)
	{
		auto laminaes = Laminae(max, n++);
		sum += laminaes;
		if(laminaes == 0)
			break;
	}
	std::cout << sum << std::endl;
}
