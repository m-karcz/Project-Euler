#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main(){
  auto t1=high_resolution_clock::now();
  long sum=0;
  for(long n=1; n<=1000; n++){
    auto product=n;
    for(int i=1; i<n; i++){
      (product*=n)%=10000000000;
    }
    (sum+=product)%=10000000000;
  }
  cout << sum << endl;
  auto t2=high_resolution_clock::now();
  //functional, same result
  vector<long> nums(1000);
  iota(begin(nums),end(nums),1);
  cout << ([=](vector<long> exp){return accumulate(begin(exp),end(exp),0L,[=](long a, long b){return (a+b)%10000000000;});})(accumulate(begin(nums),end(nums),vector<long>(),[=](vector<long> vect, long num){vect.push_back(([=](vector<long> v){return accumulate(begin(v),end(v),1L,[=](long product, long num){return (product*num)%10000000000;});})(([](auto num){vector<long> vect(num); fill(begin(vect),end(vect),num); return vect;})(num))); return vect;})) << endl;
  auto t3=high_resolution_clock::now();
  cout << duration_cast<microseconds>(t2-t1).count() << endl;
  cout << duration_cast<microseconds>(t3-t2).count() << endl;
}
