using System;
using System.Linq;
using System.Collections.Generic;
using ProjectEuler;

public class Problem26{
  public static void Main(){
    PrimeGen primes=new PrimeGen();
    while(primes.GeneratePrime()<1000){};
    primes.list.Remove(primes.list.Last());
    primes.list.RemoveAll(p=>new int[]{2,3,5}.Contains(p));
    int maxCycle=0;
    int maxPrime=0;
    foreach(var prime in primes.list){
      int digits=prime.ToString().Length;
      int divisor=(int)Math.Pow(10,digits)-1;
      while(divisor!=0){
        divisor=(divisor*10+9)%prime;
        digits++;
      }
      if(digits>maxCycle){
        maxCycle=digits;
        maxPrime=prime;
      }
    }
    Console.WriteLine(maxPrime);
  }
}
