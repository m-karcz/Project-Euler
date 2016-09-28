#include <iostream>
#include <list>
#include <cmath>

auto main() -> int {
  std::list<long long> primes{2,3,5};
  long long cand=5;
  while(primes.size()<10001){
    cand+=2;
    if(!(cand%5)){
      continue;
    }
    long long sqrt_cand=sqrt(cand)+1;
    bool ok=true;
    for(auto it=begin(primes); it!=end(primes) && *it<sqrt_cand; ++it){
      if(cand/(*it)*(*it)==cand){
        ok=false;
        break;
      }
    }
    if(ok){
      primes.emplace_back(cand);
    }
  }
  std::cout<<primes.back() << std::endl;
  return 0;
}
