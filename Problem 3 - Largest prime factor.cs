using System;
using System.Collections.Generic;
using System.Linq;

public class Problem3{
  public static void Main(){
    long num=600851475143;
    int biggest=0;
    foreach(int prime in Primes){
      while(num/prime*prime==num){
        num=num/prime;
        biggest=prime;
      }
    }
    while(num>1){
      int prime=generatePrime();
      while(num/prime*prime==num){
        num=num/prime;
        biggest=prime;
      }
    }
    Console.WriteLine(biggest);
    return;
  }
  static List<int> Primes = new List<int>{2,3,5};
  static int generatePrime(){
    int cand=Primes.Last();
    while(true){
      cand+=2;
      double sqrtCand=Math.Sqrt(cand)+1;
      bool ok = true;
      for(int i=0; Primes[i]<sqrtCand; i++){
        if(!(ok=cand/Primes[i]*Primes[i]!=cand)){
          break;
        }
      }
      if(ok){
        Primes.Add(cand);
        return cand;
      }
    } 
  }
};
