using System;
using System.Linq;
using System.Collections.Generic;
using ProjectEuler;

public class Problem41{
  private static bool buildPandigital(int builded, List<int> rest){
    if(!rest.Any()){
      if(CheckIfPrime(builded)){
        Console.WriteLine(builded);
        return true;
      }
      return false;
    }
    builded*=10;
    foreach(int digit in rest){
      if(buildPandigital(builded+digit, rest.Except(new List<int>{digit}).ToList())){
        return true;
      }
    }
    return false;
  }
  private static bool CheckIfPrime(int toCheck){
    foreach(var prime in primes.list){
      if(prime>toCheck){return true;}
      if((toCheck/prime)*prime==toCheck){
        return false;
      }
    }
    return true;
  }
  private static PrimeGen primes=new PrimeGen();
  public static void Main(){
    var sqr=Math.Sqrt(987654321)+100;
    while(primes.GeneratePrime()<sqr){}
    Console.WriteLine('-');
    int j=9;
    List<int> digits;
    do{
      digits=new List<int>();
      for(int i=j--; i>0; i--){
        digits.Add(i);
      }  
    }while(!buildPandigital(0, digits));
  }
}
