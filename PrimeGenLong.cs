using System;
using System.Collections.Generic;
using System.Linq;

namespace ProjectEuler{
  public class PrimeGenLong{
    public List<long> list=new List<long>{2,3,5};
    public long GeneratePrime(){
      long cand=list.Last();
      while(true){
        cand+=2;
        if(cand%5==0){
          continue;
        }
        long sqrtCand=(long)Math.Sqrt(cand)+1;
        bool ok=true;
        for(int i=0; list[i]<sqrtCand; i++){
          if(cand/list[i]*list[i]==cand){
            ok=false;
            break;
          }
        }
        if(ok){
          list.Add(cand);
          return cand; 
        }
      }
    }
  }
}
