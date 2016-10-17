#include <cmath>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main(){
  ifstream input;
  input.open("txt/Problem99.txt");
  string line;
  char comma;
  int max_index=0, index=0, base, exponent;
  double max_value=0;
  while(getline(input,line)){
    index++;
    stringstream(line) >> base >> comma >> exponent;
    if(exponent*log(base)>max_value){
      max_value=exponent*log(base);
      max_index=index;
    }
  }
  input.close();
  cout << max_index << endl;
}
