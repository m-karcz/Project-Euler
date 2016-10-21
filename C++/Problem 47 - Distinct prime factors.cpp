#include <iostream>
#include "PrimeGen.h"
#include <list>

using namespace std;

int main(){
  PrimeGen<long> primes;
  list<long> cands;
  long cand=10, cand_copy;
  const int consecutive=4;
  while(cands.size()<consecutive){
    cand_copy=++cand;
    int factors=0;
    if(primes.last()<cand){
      while(primes.generate_next()<cand){}
    }
    for(auto it=begin(primes.vect); it!=end(primes.vect); it++){
      if(cand_copy/(*it)*(*it)==cand_copy){
        factors++;
        while(cand_copy/(*it)*(*it)==cand_copy){
          cand_copy/=*it;
        }
      }
      if(factors>consecutive){
        cands.clear();
        break;
      }
      if(cand_copy==1){break;}
    }
    if(factors==consecutive){
      cands.emplace_back(cand);
    }else{
      cands.clear();
    }
  }
  cout << *begin(cands) << endl;
}

