#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <cmath>

using namespace std;

auto main()->int32_t{
  set<long> primes{2,3,5};
  long num=7;
  while(true){
    bool found=false;
    bool is_prime=true;
    long sqrt_num=sqrt(num)+1;
    for(auto it=primes.begin(); *it<sqrt_num; it++){
      if(num/(*it)*(*it)==num){
        is_prime=false;
        break;
      }
    }
    if(is_prime){
      primes.emplace(num);
      num+=2;
      continue;
    }
    for(auto it=primes.begin(); it!=primes.end(); it++){
      if((pow((long)sqrt((num-(*it))/2),2)*2+(*it))==num){
        found=true;
        break;
      }
    }
    if(!found){
      break;
    }
    num+=2;
  }
  cout << num << endl;
  return 0;
}
