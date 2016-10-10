using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

public class Problem13{
  public static void Main(){
    var resultArr=File.ReadAllLines("txt/Problem13.txt").Select(line=>line.ToCharArray().Select(c=>c-'0').Reverse().ToList()).ToList().Aggregate(Enumerable.Repeat(0,50).ToList(),(res,num)=>num.Select((digit,i)=>res[i]+=digit).ToList());
    List<int> result=new List<int>();
    int carry=0;
    foreach(var num in resultArr){
      carry+=num;
      result.Add(carry%10);
      carry=carry/10;
    }
    while(carry!=0){
      result.Add(carry%10);
      carry=carry/10;
    }
    result.Reverse();
    Console.WriteLine(result.Take(10).Aggregate("",(str,digit)=>str+=digit.ToString()));
  }
}
