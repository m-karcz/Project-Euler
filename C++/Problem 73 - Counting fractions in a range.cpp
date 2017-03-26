#include <iostream>
#include <set>
#include <unordered_set>

struct Fraction
{
	Fraction(int numerator, int denominator) : numerator(numerator), denominator(denominator) {}
	int numerator;
	int denominator;
	bool operator<(const Fraction& rhs) const
	{
		return numerator*rhs.denominator < rhs.numerator*denominator;
	}
};

int main()
{
	std::set<Fraction> fractions{Fraction(1,2), Fraction(1,3)};
	for(int d=1; d <= 12000; d++)
		for(int n=d/3; n < d/2; n++)
		{
			fractions.emplace(n,d);
		}

	std::cout << fractions.size()-2 << std::endl;
	return 0;
}
