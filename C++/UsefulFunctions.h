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
  
};

bool UsefulFunctions::check_num_permutation(int a, int b){
  auto str_a=std::to_string(a);
  auto str_b=std::to_string(b);
  std::sort(begin(str_a),end(str_a));
  std::sort(begin(str_b),end(str_b));
  return str_a==str_b;
}
