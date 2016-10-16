using System;
using System.Linq;
using System.Collections.Generic;

public class Problem52{
  private static bool Check(long num){
    var list=new List<long>();
    var chars=num.ToString().ToCharArray();
    for(int i=1; i<=6; i++){
      list.Add(num*i);
    }
    return !list.Select(n=>n.ToString().ToCharArray()).Any(c=>! new HashSet<char>(c).SetEquals(chars));
  }
  private static List<long> BuildList(List<long> rest, long builded, long yet){
    if(yet==0){
      return new List<long>{builded};
    }
    return rest.Select(digit=>BuildList(rest.Except(new List<long>{digit}).ToList(), builded*10+digit, yet-1)).SelectMany(n=>n).ToList();
  }
  public static void Main(){
    int digits=0;
     while(!BuildList(new List<long>{1,2,3,4,5,6,7,8,9}, 0, ++digits).Where(c=>c<Math.Pow(10,digits)/6).Where(n=>Check(n)).Select(n=>{Console.WriteLine(n); return n;}).Any()){}
  }
}
