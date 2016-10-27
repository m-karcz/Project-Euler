#include <iostream>
#include <map>
#include <utility>
#include <string>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/lexical_cast.hpp>

int main(){
  std::map<std::string,std::pair<int,std::string>> cubes;
  int n=1;
  while(++n){
    std::string sorted_digits = boost::lexical_cast<std::string>(boost::multiprecision::cpp_int(n)*n*n);
    std::sort(std::begin(sorted_digits),std::end(sorted_digits),[](char a, char b){return a>b;});
    if(cubes[sorted_digits].first){
      int check=++cubes[sorted_digits].first;
      if(check==5){
        std::cout << cubes[sorted_digits].second << std::endl;
        break;
      }
    }else{
      cubes[sorted_digits]=std::make_pair(1,boost::lexical_cast<std::string>(boost::multiprecision::cpp_int(n)*n*n));
    }
  }
  return 0;
}
