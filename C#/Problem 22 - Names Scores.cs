using System;
using System.IO;
using System.Linq;
using System.Collections.Generic;
using System.Text.RegularExpressions;

public class Problem22{
  public static void Main(){
      Console.WriteLine(
        File.ReadAllText("txt/Problem22.txt")
            .Split(',')
            .Select(s=>new Regex(@"\w+").Match(s).Value)
            .OrderBy(s=>s)
            .Select((s,i)=>s.ToCharArray()
                            .Select(c=>(c-'A'+1)*(i+1)).Sum())
            .Sum());
  }
}
