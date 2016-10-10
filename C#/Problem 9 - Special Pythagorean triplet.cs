using System;
using System.Linq;

public class Problem9{
  public static int Pythagorean(){
    for(int a=1; a<300; a++){
      for(int b=a; b<500; b++){
        if(a*a+b*b==(1000-a-b)*(1000-a-b)){
          return a*b*(1000-a-b);
        }
      }
    }
    return 0;
  }
  public static void Main(){
    Console.WriteLine(Pythagorean());
  }
}
