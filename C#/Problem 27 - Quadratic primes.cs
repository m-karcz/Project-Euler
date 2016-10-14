using System;
using System.Linq;
using System.Collections.Generic;
using ProjectEuler;

public class Problem27{
  public static void Main(){
    int product=0;
    int maxAmount=0;
    PrimeGen primes=new PrimeGen();
    for(int a=-999; a<1000; a++){
      for(int b=-1000; b<=1000; b++){
        int amount=0;
        int n=0;
        int res=0;
        do{
          res=n*n+a*n+b;
          while(res>primes.list.Last()){
            primes.GeneratePrime();
          }
          n++;
          if(primes.list.Contains(res)){
            amount++;
          }else{
            break;
          }
        }while(true);
        if(amount>maxAmount){
          maxAmount=amount;
          product=a*b;
        }
      }
    }
    Console.WriteLine(product);
  }
}
