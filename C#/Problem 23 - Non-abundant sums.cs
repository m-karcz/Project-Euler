using System;
using System.Collections.Generic;
using System.Linq;

public class Problem23{
  public static void Main(){
    var nonAbundant=Enumerable.Range(1,28124).ToList();
    var abundants=new List<int>();
    var abundantsSums=new HashSet<int>();
    for(int n=11; n<28124; n++){
      int div=0;
      for(int d=1; d<n; d++){
        if(n/d*d==n){
          div+=d;
        }
      }
      if(div>n){
        abundants.Add(n);
      }
    }
    var count=abundants.Count();
    for(int i=0; i<count; i++){
      for(int j=i; j<count; j++){
        int sum=abundants[i]+abundants[j];
        if(sum<28130){
          abundantsSums.Add(sum);
        }
      }
    }
    foreach(var sum in abundantsSums){
      nonAbundant.Remove(sum);
    }
    Console.WriteLine(nonAbundant.Sum());
  }
}
