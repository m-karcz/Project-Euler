using System;
using System.Collections.Generic;

public class Problem16{
  public static void Main(){
    List<int> digits=new List<int>();
    digits.Add(2);
    for(int i=1; i<1000; i++){
      List<int> newDigits=new List<int>();
      int carry=0;
      foreach(int digit in digits){
        carry+=digit*2;
        newDigits.Add(carry%10);
        carry=carry/10;
      }
      if(carry>0){
        newDigits.Add(carry);
      }
      digits=newDigits;
    }
    int sum=0;
    foreach(int digit in digits){
      sum+=digit;
    }
    Console.WriteLine(sum);
  }
}
