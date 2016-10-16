#include <iostream>
#include <algorithm>
#include <list>

struct Num_al{
  virtual long generate(void)=0;
  long last=0;
protected:
  long n=1;
};

struct Triangular : Num_al{
  long generate(void) override{
    n++;
    return last=n*(n+1)/2; 
  }
};

struct Pentagonal : Num_al{
  long generate(void) override{
    n++;
    return last=n*(3*n-1)/2;
  }
};

struct Hexagonal : Num_al{
  long generate(void) override{
    n++;
    return last=n*(2*n-1);
  }
};

int main(){
  Triangular t;
  Pentagonal p;
  Hexagonal h;
  std::list<Num_al*> tab{&t,&p,&h};
  for(auto n : tab){
    n->generate();
  }
  long max;
  while(true){
    max=std::max({t.last,p.last,h.last});
    for(auto n : tab){
      while(n->last<max){
        n->generate();
      }
    }
    if(max==40755){
      t.generate();
    }
    if((t.last==max) && (p.last==max) && (h.last==max)){
      break;
    }
  }
  std::cout << t.last << std::endl;
}
