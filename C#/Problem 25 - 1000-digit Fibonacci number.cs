using System;
using System.Linq;
using System.Collections.Generic;
using ProjectEuler;

public class Problem25{
  public static void Main(){
    var Fminus1=new List<int>{1};
    var Fminus2=new List<int>{1};
    int i=2;
    while(Fminus1.Count()<1000){
      i++;
      Swap(ref Fminus1,ref Fminus2);
      Fminus1=BigNum.Add(new List<List<int>>{Fminus1, Fminus2});
    }
    Console.WriteLine(i);
  }
  static void Swap<T>(ref T lhs, ref T rhs)
  {
    T temp;
    temp = lhs;
    lhs = rhs;
    rhs = temp;
  }
}
