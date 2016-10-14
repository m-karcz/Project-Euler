using System;
using System.Linq;
using System.Collections.Generic;

public class Problem29{
  public static void Main(){
    Console.WriteLine(
      Enumerable.Range(2,100-2+1)
        .Select(n=>{
          for(int d=2; d<Math.Sqrt(n)+1; d++){
            if(n/d*d==n){
              int nn=n, i=0;
              while(nn>1){
                if(nn%d!=0){
                  break;
                }
                nn/=d;
                i++;
              }
              if(nn==1){
                return Tuple.Create(d,i);
              }
            }
          }
          return Tuple.Create(n,1);
        })
        .Select(pair=>Enumerable.Range(2,100-2+1)
          .Select(pow=>Tuple.Create(pair.Item1,pair.Item2*pow)))
        .SelectMany(p=>p)
        .ToList()
        .Distinct()
        .Count()
    );
  }
}
