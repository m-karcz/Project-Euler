#include <iostream>
#include <numeric>
#include <algorithm>
#include <vector>

auto main() -> int {
  std::vector<int> numbers(999);
  std::iota(numbers.begin(),numbers.end(),1);
  std::cout << std::accumulate(numbers.begin(), numbers.end(), 0, [](auto sum, auto num){return ((!(num%3) || !(num%5)) ? sum+num : sum);}) << std::endl;
  return 0;
}
