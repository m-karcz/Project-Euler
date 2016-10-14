using System;
using System.Linq;
using System.Collections.Generic;

public class Problem24{
  public static bool Loop(List<int> builded){
    if(builded.Count()==10){
      whichPermutation++;
      if(whichPermutation==1000000){
        foreach(var digit in builded){
          Console.Write(digit);
        }
        Console.WriteLine();
        return true;
      }else{
        return false;
      }
    }
    foreach(var digit in nums.Except(builded)){
      var newBuilded=new List<int>(builded);
      newBuilded.Add(digit);
      if(Loop(newBuilded)){
        return true;
      }
    }
    return false;
  }
  private static int whichPermutation=0;
  private static List<int> nums=new List<int>{0,1,2,3,4,5,6,7,8,9};
  public static void Main(){
    Loop(new List<int>());
  }
}
