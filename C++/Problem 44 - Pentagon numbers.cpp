#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main() {
  set<long> pentagonals{1,5,12};
  bool found=false;
  for(long n=4;;n++){
    long p=n*(3*n-1)/2;
    for(auto it=begin(pentagonals); it!=end(pentagonals) && *it<p/2; ++it){
      long pk=p-(*it);
      long pj=pk-(*it);
      if(find(begin(pentagonals),end(pentagonals),pj)!=end(pentagonals)){
        if(find(begin(pentagonals),end(pentagonals),pk)!=end(pentagonals)){
          cout << pk << endl;
          cout << pj << endl;
          cout << *it << endl;
          found = true;
          break;
        }
      }
    }
    if(found){
      break;
    }
    pentagonals.insert(p);
  }
}
