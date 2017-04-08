#include <iostream>
#include <cmath>

double circleArea(double n, double Xn)
{
	double a = Xn/n;
	double b = 0.5 - Xn;
	double alpha = std::asin(std::sqrt(a * a + b * b));
	return - 0.25 * alpha + a * b / 2 + 0.125 * std::sin(2 * alpha);
}
double totalArea(double n)
{
	double Xn = (n * n + n - std::sqrt(2 * std::pow(n, 3)))/(2 * ( n * n + 1));
	return 0.5 * Xn * Xn / n + circleArea(n, Xn);
}
int main()
{
	double L_section = 2.0 * totalArea(1);
	int n = 15;
	while(totalArea(static_cast<double>(++n)) / L_section > 0.001){}
	std::cout << n << std::endl;
	return 0;
}
