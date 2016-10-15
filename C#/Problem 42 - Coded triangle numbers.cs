using System;
using System.IO;
using System.Linq;
using System.Collections.Generic;
using System.Text.RegularExpressions;

public class Problem42{
  public static void Main(){
    Console.WriteLine(
      File.ReadAllText("txt/Problem42.txt")
          .Split(',')
          .Select(s=>new Regex(@"\w+").Match(s)
                                      .Value
                                      .ToCharArray()
                                      .Select(c=>c-'A'+1).Sum())
          .Where(n=>{int i=1; while(i*(i+1)/2<n){i++;} return i*(i+1)/2==n;})
          .Count()
    ); 
  }
}
