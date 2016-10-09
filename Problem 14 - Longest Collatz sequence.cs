using System;
using System.Collections.Generic;
using System.Linq;

public class Problem14{
  private static void Collatz(long n){
    if(!paths.ContainsKey(n)){
      Collatz(n%2==0 ? n/2 : (3*n+1));
      paths[n]=1+paths[n%2==0 ? n/2 : (3*n+1)];
    }
  }
  private static Dictionary<long,long> paths = new Dictionary<long,long>(); 
  public static void Main(){
    paths[1]=1;
    for(long i=2; i<=1000000; i++){
      Collatz(i);
    }
    Console.WriteLine(paths.OrderBy(d=>d.Key).Skip(0).Take(1000000).ToDictionary(k=>k.Key, v=>v.Value).Aggregate((l,r)=>l.Value > r.Value ? l : r).Key);
  }
}
