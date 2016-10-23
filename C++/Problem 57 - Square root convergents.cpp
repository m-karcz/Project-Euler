#include <iostream>
#include <vector>
#include <string>

class BigFraction{
public:
  BigFraction(int n, int d){
    numerator.push_back(n);
    denominator.push_back(d);
  } 
  std::vector<int> numerator;
  std::vector<int> denominator;
};

void next(BigFraction& f){
  std::vector<int> num;
  std::vector<int> den;
  int carry=0;
  for(int i=0; i<f.numerator.size(); i++){
    carry+=f.numerator[i]+((i<f.denominator.size())?(2*f.denominator[i]):(0));
    num.emplace_back(carry%10);
    carry/=10;
  }
  while(carry>0){
    num.emplace_back(carry%10);
    carry/=10;
  }
  for(int i=0; i<f.numerator.size(); i++){
    carry+=f.numerator[i]+(i<f.denominator.size()?f.denominator[i]:0);
    den.emplace_back(carry%10);
    carry/=10;
  }
  while(carry>0){
    den.emplace_back(carry%10);
    carry/=10;
  }
  f.numerator=move(num);
  f.denominator=move(den);
  return;
}

int main(){
  BigFraction f(3,2);
  int sum=0;
  for(int i=1; i<=1000; i++){
    if(f.numerator.size()>f.denominator.size()){
      ++sum;
    }
    next(f);
  }
  std::cout << sum << std::endl;
}

