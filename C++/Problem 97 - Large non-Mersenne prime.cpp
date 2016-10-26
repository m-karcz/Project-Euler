#include <iostream>

int main(){
  long result=1;
  for(int i=0; i<7830457; i++){
    (result*=2)%=10000000000;
  }
  result*=28433;
  result+=1;
  result%=10000000000;
  std::cout << result << std::endl;
}
