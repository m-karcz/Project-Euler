#include <iostream>
#include <boost/lexical_cast.hpp>
#include <string>
#include <algorithm>

template<typename T>
bool is_bouncy(T num){
  auto str_num=boost::lexical_cast<std::string>(num);
  bool increasing=true, decreasing=true;
  for(auto it=str_num.begin(); std::next(it) != str_num.end(); ++it){
    auto res=*std::next(it)-(*it);
    if(res>0){
      decreasing=false;
    }else if(res<0){
      increasing=false;
    }
    if(!(decreasing || increasing)){
      return true;
    }
  }
  return false;
}

int main(){
  double numerator=0, denominator=99;
  int n=99;
  while(numerator/denominator<99){
    denominator++;
    n++;
    if(is_bouncy(n)){
      numerator+=100;
    }
  }
  std::cout << n << std::endl;
}
