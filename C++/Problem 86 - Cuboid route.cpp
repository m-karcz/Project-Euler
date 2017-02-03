#include <iostream>
#include <cmath>

int main()
{
	int sum=0;
	double integral_part;
	for(double x=1;; x++)
		for(double y=1; y<=x; y++)
			for(double z=1; z<=y; z++)
				if(std::modf(std::sqrt(x*x+(y+z)*(y+z)), &integral_part)<0.000001F)
				{
					sum++;
					if(sum>1000000)
					{
						std::cout << x << std::endl;
						return 0;
					}				
				}
	return 0;
}
