#include <iostream>
#include "UsefulFunctions.h"

using namespace std;

int main(){
  int sum=0;
  for(int n=1; n<=100; n++){
    for(int k=1;k<=n/2;k++){
      if(UsefulFunctions::n_choose_k<long>(n,k)>1000000){
        sum+=n-2*k+1;
        break;
      }
    }
  }
  cout << sum << endl;
  return 0;
}
