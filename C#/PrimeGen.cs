using System;
using System.Collections.Generic;

namespace ProjectEuler{
  public class PrimeGen{
    public List<int> list=new List<int>{2,3,5};
    public int GeneratePrime(){
        int cand=list.Last();
        while(true){
      cand+=2;
      if(cand%5==0){
        continue;
      }
      int sqrtCand=(int)Math.Sqrt(cand)+1;
      bool ok=true;
      for(int i=0; list[i]<sqrtCand; i++){
        if(cand/list[i]*list[i]==cand){
          ok=false;
          break;
        }
      }
      list.Add(cand);
      return cand; 
  }
}
