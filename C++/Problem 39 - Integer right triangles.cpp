#include <iostream>
#include <cmath>
#include <array>
#include <algorithm>

auto main()->int{
	int max_amount=0;
	int max_p=0;
	for(int p=1; p<=1000; p++){
		int amount=0;
		for(int a=1; a<=p/3; a++){
			for(int b=a; b<=p/2; b++){
				if((a*a+b*b)==((p-a-b)*(p-a-b))){
					amount++;	
				}
			}
		}
		if(amount>max_amount){
			max_amount=amount;
			max_p=p;
		}
	}
	std::cout << max_p << std::endl;
	return 0;
}
