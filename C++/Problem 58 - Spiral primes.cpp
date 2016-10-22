#include <iostream>
#include <cmath>
#include "PrimeGen.h"
#include <chrono>

int main(){
  auto t1=std::chrono::high_resolution_clock::now();
  PrimeGen<long> primes;
  double numerator=0, denominator=1;
  long num=1, side=2, sqrt_num;
  bool is_prime;
  for(; numerator/denominator>0.1 || numerator==0; side+=2){
    for(int i=0; i<4; i++){
      denominator++;
      is_prime=true;
      num+=side;
      sqrt_num=sqrt(num)+1;
      while(primes.generate_next()<sqrt_num){}
      for(auto it=primes.begin(); *it<=sqrt_num; ++it){
        if(num/(*it)*(*it)==num){
          is_prime=false;
          break;
        }
      }
      if(is_prime){
        numerator++;
      }
    }
  }
  std::cout << "Size of side: " << side-1 << "    " << numerator << "/" << denominator << std::endl;
  std::cout << "Took: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()-t1).count() << "ms" << std::endl;
}
