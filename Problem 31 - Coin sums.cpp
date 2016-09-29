#include <iostream>
#include <array>


int comb=0;
std::array<int,8> coins{200,100,50,20,10,5,2,1};

void count(int rest, int lastIndex){
	if(rest<=0){
		rest==0 && comb++;
		return;
	}
	for(int i=lastIndex; i<8; i++){
		count(rest-coins[i], i);
	}
	return;
}

auto main()->int{
	count(200,0);
	std::cout << comb << std::endl;
	return 0;
}
