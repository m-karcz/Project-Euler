using System;

public class Problem76{
  static int sum=0;
  static void divide(int last, int rest){
    if(rest==0){
      sum++;
      return;
    }
    for(int i=last; i>0; i--){
      if(i<=rest){
        divide(i, rest-i);
      }
    }
    return;
  }
  public static void Main(){
    divide(99, 100);
    Console.WriteLine(sum);
    return;
  }
}
