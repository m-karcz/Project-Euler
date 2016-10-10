#include <iostream>
#include <vector>
#include <cmath>

struct Prime{
  int generatePrime(void){
    int cand=primes.back();
    int sqrt_cand=sqrt(cand)+1;
    while(true){
      cand+=2;
      bool ok=true;
      for(auto i=0; primes[i]<sqrt_cand; i++){
         int div=cand/primes[i];
         if(div*primes[i]){
           ok=false;
          break;
        }
      }
      if(ok){
        primes.push_back(cand);
        return cand;
      }
    }
  }
  std::vector<int> primes{2,3,5};
};

auto main()->int{
  auto sum=10LL;
  Prime primes;
  while(primes.generatePrime()<10){
    sum+=primes.primes.back();
  }
  std::cout << sum << std::endl;
  return 0;
}
