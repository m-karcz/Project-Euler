using System;

public class Problem6
{
  public static void Main()
  {
    long one=0, two=5050*5050;
    for(int i=1; i<=100; i++){
      one+=i*i;
    }
    Console.WriteLine(two-one);
  }
}
