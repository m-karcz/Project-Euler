using System;
using System.Linq;
using System.Collections.Generic;
using ProjectEuler;

public class Problem35{
  public static void Main(){
    PrimeGen tempPrimes=new PrimeGen();
    while(tempPrimes.GeneratePrime()<1000000){}
    var primes=new HashSet<int>(tempPrimes.list);
    var Rotate=new Func<List<char>, int, int>((list,howMany)=>{var l=new List<char>(list); for(int i=0; i<howMany; i++){char first=l.First(); l.RemoveAt(0); l.Add(first);} return Int32.Parse(new string(l.ToArray()));});
    var Num2List=new Func<int, List<char>>(num=>num.ToString().ToCharArray().ToList());
    var Check=new Func<int,bool>(num=>Enumerable.Range(1,num.ToString().Length).Select(i=>primes.Contains(Rotate(Num2List(num),i))).All(n=>n));
    int quantity=0;
    for(int i=1; i<1000000; i++){
      if(primes.Contains(i)){
        if(Check(i)){
          quantity++;
        }
      }
    }
    Console.WriteLine(quantity);
  }
}
