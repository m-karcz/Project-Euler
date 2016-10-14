using System;
using System.Linq;
using System.Collections.Generic;

public class Problem34{
  public static void Main(){
    var factorials=new Dictionary<int,int>{{0,1},{1,1}};
    for(int i=2; i<10; i++){
      factorials.Add(i,i*factorials[i-1]);
    }
    int sum=0;
    var isCurious=new Func<int,bool>(num=>num==num.ToString().ToCharArray().Select(c=>factorials[c-'0']).Sum());
    //bound is set to 3000000 cuz 9999999>3000000>7*9!
    for(int i=3; i<3000000; i++){
      if(isCurious(i)){
        sum+=i;
      }
    }
    Console.WriteLine(sum);
  }
}
