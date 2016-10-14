using System;
using System.Linq;
using System.Collections.Generic;

public class Problem30{
  public static void Main(){
    Console.WriteLine(
      //2000000 because 1999999>6*9^5 but 199999<5*9^5
      Enumerable.Range(2,2000000).Select(n=>Tuple.Create(n,n.ToString().ToCharArray().Select(c=>Math.Pow(c-'0',5)).Sum())).Where(p=>p.Item1==p.Item2).Select(p=>p.Item1).Sum()
    );
  }
}
