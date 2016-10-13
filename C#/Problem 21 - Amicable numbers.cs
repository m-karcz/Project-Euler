using System;
using System.Collections.Generic;
using System.Linq;

public class Problem21{
  public static void Main(){
    var amicables=new HashSet<int>();
    for(int n=1; n<10000; n++){
      int sum=0;
      for(int m=1; m<n; m++){
        if(n/m*m==n){
          sum+=m;
        }
      } 
      if(sum==n){
        continue;
      }
      int sum2=0;
      for(int d=1; d<sum; d++){
        if(sum/d*d==sum){
          sum2+=d;
        }
      }
      if(sum2==n){
        if(sum2<10000){
          amicables.Add(sum2);
        }
        if(n<10000){
          amicables.Add(n);
        }
      }
    }
    Console.WriteLine(amicables.Sum());
  }
}
