using System;
using System.Linq;
using System.Collections.Generic;

public class Problem38{
  private static string Concatenate(int num){
    string result="";
    for(int i=1; result.Length<9; i++){
      result+=(num*i).ToString();
    }
    return result;
  }
  private static List<char> allDigits=new List<char>{'1','2','3','4','5','6','7','8','9'};
  public static void Main(){
    Console.WriteLine(
      Enumerable.Range(1,10000).Select(n=>Concatenate(n)).Where(s=>s.Length==9).Where(s=>new HashSet<char>(s.ToCharArray().ToList()).SetEquals(allDigits)).Select(s=>Int32.Parse(s)).Max()
    );
  }
}
