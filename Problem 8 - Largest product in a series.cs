using System;
using System.IO;
using System.Linq;
using System.Collections.Generic;

public class Problem8{
  public static void Main(){
    List<int> nums=System.IO.File.ReadAllText("txt/Problem8.txt").Replace("\n",String.Empty).ToCharArray().Select(num=>num-'0').ToList();
    long max=0;
    int factorAmount=13;
    foreach(var num in Enumerable.Range(0, 1000-factorAmount)){
      max=Math.Max(max, nums.GetRange(num,factorAmount).Aggregate(1L,(a,b)=>a*b));
    }
    Console.WriteLine(max);
  }
}
