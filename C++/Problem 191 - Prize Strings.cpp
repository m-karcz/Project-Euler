#include <iostream>

long long PrizeStrings(int day, int absencesInRow, bool alreadyLate)
{
	return absencesInRow == 3 ? 0 : day == 30 ? 1 : (PrizeStrings(day + 1, 0, alreadyLate) + PrizeStrings(day + 1, absencesInRow + 1, alreadyLate) + (alreadyLate ? 0 : PrizeStrings(day+1, 0, true)));
}

int main()
{
	std::cout << PrizeStrings(0, 0, false) << std::endl;
}
