#include <iostream>
#include <cmath>
#include <string>
#include <boost/lexical_cast.hpp>
#include <boost/multiprecision/cpp_int.hpp>

int main(){
  int upper_bound=1, matching=0;;
  auto log9=log(9), log10=log(10);
  for(;upper_bound*log9>(upper_bound-1)*log10;upper_bound++){}
  for(int i=0; i<upper_bound; i++){
    for(boost::multiprecision::uint1024_t n=1;n<10;n++){
      auto nn=n;
      for(int k=i; k>0; k--){
        nn*=n;
      }
      if(boost::lexical_cast<std::string>(nn).length()==i+1){
        matching++;
      }
      if(boost::lexical_cast<std::string>(nn).length()>i+1){
        break;
      }
    }
  }
  std::cout << "Matching numbers: " << matching << std::endl;
  return 0;
}
