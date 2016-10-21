#pragma once

#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>

class UsefulFunctions{
public:
  static bool check_num_permutation(int a, int b);
  template <typename T>
  static T factorial(T n);
  template <typename T>
  static T n_choose_k(T n, T k); 
};

bool UsefulFunctions::check_num_permutation(int a, int b){
  auto str_a=std::to_string(a);
  auto str_b=std::to_string(b);
  std::sort(begin(str_a),end(str_a));
  std::sort(begin(str_b),end(str_b));
  return str_a==str_b;
}

template <typename T>
T UsefulFunctions::factorial(T n){
  T result=1;
  for(int i=2; i<=n; i++){
    result*=i;
  }
  return result;
}

template <typename T>
T UsefulFunctions::n_choose_k(T n, T k){
  T result=1;
  T n_k=n-k; 
  if(n_k<k){
    std::swap(n_k,k);
  }
  for(T i=n_k+1; i<=n; i++){
    result*=i;
  }
  for(T i=k; i>1; i--){
    result/=i;
  }
  return result;
}
