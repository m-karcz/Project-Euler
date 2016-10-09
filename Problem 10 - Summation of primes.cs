using System;
using System.Collections.Generic;
using System.Linq;

public class Problem10{
  private static long GeneratePrime(){
    long cand=primes.Last();
    while(true){
      cand+=2;
      if(cand%5==0){
        continue;
      }
      long sqrtCand=(long)Math.Sqrt(cand)+1;
      bool ok=true;
      for(int i=0; primes[i]<sqrtCand; i++){
        if(cand/primes[i]*primes[i]==cand){
          ok=false;
          break;
        }
      }
      if(ok){
        if(cand<2000000){
          primes.Add(cand);
        }
        return cand;
      }
    }
  }
  private static List<long> primes=new List<long>{2,3,5};
  public static void Main(){
    while(GeneratePrime()<2000000){};
    Console.WriteLine(primes.Sum());
  }
}
