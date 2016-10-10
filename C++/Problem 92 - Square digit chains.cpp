#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>

auto sqr_sum(unsigned long num)->unsigned long{
  std::string str_num=std::to_string(num);
  return std::accumulate(str_num.begin(), str_num.end(), 0UL, [](auto sum, auto num){
    return sum+=(num-'0')*(num-'0');
  });
}

auto main()->int{
  unsigned long eighty_nine = 1;
  std::map<unsigned long, int> chains{{89, 1},{1, -1}};
  for(unsigned long j=2; j<10000000; j++){
    unsigned long i=j;
    unsigned long chain;
    std::vector<unsigned long> nums{i};
    while(1){
      chain=chains[i];
      if(chain!=0){
        for(auto num : nums){
	  chains[num]=chain;
	}
        if(chain==1){
          eighty_nine+=nums.size()-1;
        }
	break;
      }
      nums.push_back(i);
      i=sqr_sum(i);
    }
  }
  std::cout << eighty_nine << std::endl;
  return 0;
}
