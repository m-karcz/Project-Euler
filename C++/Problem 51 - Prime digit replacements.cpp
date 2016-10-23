#include <iostream>
#include "PrimeGen.h"
#include <algorithm>
#include <cmath>
#include <boost/range/adaptor/transformed.hpp>
#include <boost/range/adaptor/reversed.hpp>
#include <boost/range/irange.hpp>
#include <boost/algorithm/string/replace.hpp>
#include <boost/algorithm/string/predicate.hpp>

using namespace std;

class Base11{
public:
  Base11(int n);
  operator vector<int>() const;
  bool is_trivial(void) const;
private:
  string num;
};

bool check_if_prime(int num, PrimeGen<int>& primes){
  int sqrt_n=sqrt(num)+1;
  for(auto it=primes.begin(); *it<sqrt_n; ++it){
    if(num/(*it)*(*it)==num){
      return false;
    }
  }
  return true;
}

int main(){
  PrimeGen<int> primes;
  bool found=false;
  const int how_many_primes=8;
  for(int digits=2; !found; ++digits){
    int max=pow(11,digits);
    int sqrt_max=sqrt(max)+2;
    while(primes.generate_next()<sqrt_max);
    for(int num=pow(11,digits-1); num<max; ++num){
      Base11 pattern(num);
      if(pattern.is_trivial()){
        continue;
      }
      int num_of_primes=0;
      for(auto& n : (vector<int>)pattern){
        if(to_string(n).size()<digits){
          continue;
        }
        if(check_if_prime(n, primes)){
          num_of_primes++;
        }
      }
      if(num_of_primes==how_many_primes){
        for(auto& n : (vector<int>)pattern){
          if(to_string(n).size()<digits){
            continue;
          }
          if(check_if_prime(n,primes)){
            cout << n << endl;
            return 0;
          }
        } 
      }
    }
  }
}

Base11::Base11(int n){
  while(n>0){
    num+=(n%11+'0');
    n/=11;
  }
}

Base11::operator vector<int>() const{
  auto r=boost::irange(0,10) | boost::adaptors::transformed([this](auto n){return boost::algorithm::replace_all_copy(num, ":", to_string(n));}) | boost::adaptors::transformed([](auto s){reverse(s.begin(),s.end()); return stoi(s);});
	return vector<int>(r.begin(),r.end());  
}

bool Base11::is_trivial(void) const{
  return !boost::algorithm::contains(num, ":");
}
