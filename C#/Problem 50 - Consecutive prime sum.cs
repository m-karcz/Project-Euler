using System;
using System.Linq;
using System.Collections.Generic;
using ProjectEuler;

public class Problem50{
  public static void Main(){
    PrimeGen primes=new PrimeGen();
    int sum=0;
    while(sum<1000000){
      sum+=primes.GeneratePrime();
    }
    int firstOver1k=primes.list.FirstOrDefault(p=>p>1000);
    List<int> primesBelow1k=primes.list.Where(p=>p<=firstOver1k).ToList();
    while(true){
      bool isPrime=true;
      sum-=primes.list.Last();
      primes.list.RemoveAt(primes.list.Count()-1);
      foreach(int prime in primesBelow1k){
        if(sum/prime*prime==sum){
          isPrime=false;
          break;
        }
      }
      if(isPrime){
        break;
      }
    }
    Console.WriteLine(sum);
  }
}

