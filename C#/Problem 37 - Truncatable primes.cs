using System;
using System.Linq;
using System.Collections.Generic;
using ProjectEuler;

public class Problem37{
  private static bool checkLeft(int num){
    while(num>primes.list.Last()){primes.GeneratePrime();}
    return primes.list.Contains(num) && (num>10 ? checkLeft(Int32.Parse(num.ToString().Substring(1))) : true);
  }
  private static bool checkRight(int num){
    while(num>primes.list.Last()){primes.GeneratePrime();}
    return num==0 || primes.list.Contains(num) && checkRight(num/10);
  }
  private static PrimeGen primes=new PrimeGen();
  public static void Main(){
    List<List<int>> generatedRight=new List<List<int>>();
    int generated=0;
    List<int> toAdd=new List<int>{1,2,3,5,7,9};
    generatedRight.Add(new List<int>(toAdd));
    int sum=0;
    for(int i=0; generated<11; i++){
      generatedRight.Add(generatedRight[i].Select(n=>toAdd.Select(d=>n*10+d)).SelectMany(n=>n).Where(n=>checkRight(n)).ToList());
      foreach(var cand in generatedRight[i+1]){
        if(checkLeft(cand)){
          sum+=cand;
          generated++;
        }
      }
    }
    Console.WriteLine(sum);
  }
}
