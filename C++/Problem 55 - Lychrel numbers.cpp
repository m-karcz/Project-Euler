#include <iostream>
#include <string>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/range/adaptors.hpp>


int main(){
  int lychrels=0;
  for(int n=1; n<10000; n++){
    boost::multiprecision::cpp_int big_n=n;
    for(int i=0;;i++){
      auto big_n2=big_n;
      while(*(boost::lexical_cast<std::string>(big_n2).rbegin())=='0'){
        big_n2/=10;
      }
      auto reversed=boost::lexical_cast<boost::multiprecision::cpp_int>(boost::lexical_cast<std::string>(big_n2) | boost::adaptors::reversed);
      if(reversed==big_n && i!=0){
        break;
      }
      if(i>50){
        lychrels++;
        break;
      }
      big_n=big_n+reversed;
    }
  }
  std::cout << "Lychrels: " << lychrels << std::endl;
  return 0;
}
