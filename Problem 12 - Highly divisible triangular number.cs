using System;
using ProjectEuler;
using System.Collections.Generic;
using System.Linq;

public class Problem12{
  public static void Main(){
    PrimeGenLong primes=new PrimeGenLong();
    long num=1;
    long addend=2;
    while(true){
      num+=addend++;
      long n=num;
      var primeFactors=new Dictionary<long,int>();
      for(int i=0; i<primes.list.Count() && n>1; i++){
        if(n/primes.list[i]*primes.list[i]==n){
          primeFactors.Add(primes.list[i],1);
          while(n/primes.list[i]*primes.list[i]==n){
            primeFactors[primes.list[i]]++;
            n=n/primes.list[i];
          }
        }
      }
      while(n>1){
        long newPrime=primes.GeneratePrime();
        if(n/newPrime*newPrime==n){
          primeFactors.Add(newPrime,1);
          while(n/newPrime*newPrime==n){
            primeFactors[newPrime]++;
            n=n/newPrime;
          }
        }
      }
      if(primeFactors.Aggregate(1,(product,x)=>(product*x.Value))>500){
        Console.WriteLine(num);
        return;  
      }
    }
  }
}
