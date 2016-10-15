using System;
using System.Linq;
using System.Collections.Generic;

public class Problem36{
  private static bool checkIfPalindrome(string num){
    return num.Equals(new string(num.ToCharArray().AsEnumerable().Reverse().ToArray()));
  }
  public static void Main(){
    Console.WriteLine(
      Enumerable.Range(1,1000000).Where(num=>checkIfPalindrome(Convert.ToString(num,10))&&checkIfPalindrome(Convert.ToString(num,2))).ToList().Sum()
    );
  }
}
