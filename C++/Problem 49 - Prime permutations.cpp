#include <iostream>
#include "PrimeGen.h"
#include "UsefulFunctions.h"

using namespace std;

int main(){
  PrimeGen<int> primes;
  while(primes.generate_next()<10000){}
  auto first_below_1k=primes.begin();
  auto last_below_1k=primes.begin();
  while(*last_below_1k<1000){
    last_below_1k++;
  }
  last_below_1k--;
  primes.remove(first_below_1k, last_below_1k);
  for(auto middle=next(primes.begin()); middle!=primes.end(); middle++){
    for(auto lower=primes.begin(); distance(lower, middle)>0; lower++){
      if(UsefulFunctions::check_num_permutation(*middle, *lower)){
        auto higher=find(middle, primes.end(), 2*(*middle)-(*lower));
        if(UsefulFunctions::check_num_permutation(*middle,*higher)){
          if(higher!=primes.end()){
            cout << *lower << *middle << *higher << endl;
            break;
          }
        }
      }
    }
  }
  return 0;
}


