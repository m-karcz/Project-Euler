using System;

public class Problem2{
  public static void Main(){
    long first=1, second=2, temp=0;
    long sum=0;
    while(second<4000000L){
      if((second%2)==0){
        sum+=second;
      }
      temp=first;
      first=second;
      second=temp+first;
    }
    Console.WriteLine(sum);
  }
}
