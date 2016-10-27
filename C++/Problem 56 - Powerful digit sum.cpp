#include <iostream>
#include <boost/lexical_cast.hpp>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/range/adaptor/transformed.hpp>
#include <boost/range/numeric.hpp>
#include <algorithm>

int main(){
  int max_sum=0;
  for(int a=1; a<100; ++a){
    boost::multiprecision::cpp_int n=a;
    for(int b=1; b<100; ++b){
      n*=a;
      max_sum=std::max(max_sum, boost::accumulate(boost::lexical_cast<std::string>(n) | boost::adaptors::transformed([](char c){return c-'0';}),0,[](int a, char b){return a+b;}));
    }
  }
  std::cout << max_sum << std::endl;
}
