#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <algorithm>

auto check(std::string str){
  return str[2]=='2' && str[4]=='3' && str[6]=='4' && str[8]=='5' && str[10]=='6' && str[12]=='7' && str[14]=='8' && str[16]=='9';
}

auto multiply(long _num)->std::string{
  std::string str_num=std::to_string(_num);
  std::vector<int> num;
  std::for_each(str_num.rbegin(), str_num.rend(), [&](auto char_num){
    num.push_back(char_num-'0');
  });
  std::size_t size=num.size();
  std::vector<std::vector<int>> mply;
  mply.reserve(size);
  for(std::size_t i=0; i<size; i++){
    std::vector<int> temp(i);
    for(std::size_t j=0; j<size; j++){
      temp.push_back(num[i]*num[j]);
    }
    mply.push_back(temp);
  }
  auto width=mply.back().size();
  auto height=mply.size();
  std::string result="";
  int carry=0;
  for(auto i=0; i<width; i++){
    for(auto j=0; j<height; j++){
      if(i<mply[j].size()){
        carry+=mply[j][i];
      }
    }
    result+=std::to_string(carry%10);
    carry=carry/10;
  }
  while(carry>0){
    result+=std::to_string(carry%10);
    carry=carry/10;
  }
  std::reverse(begin(result), end(result));
  return result;
}

auto main()->int{
  long num=10000000010;
  while(!check(multiply(num))){
    num+=10;
    if(num%1000000==30){
      std::cout << num << std::endl;
    }
    if(num>15000000000){
      std::cout << "dupa" << std::endl;
      break;
    }
  }
  std::cout << num << std::endl;
  std::cout << multiply(num) << std::endl;
  return 0;
} 
