using System;
using System.Collections.Generic;
using System.Linq;

public class Problem17{
  public static void Main(){
    var numStr=new Dictionary<int,string>();
    numStr.Add(0, "");
    numStr.Add(1, "one");
    numStr.Add(2, "two");
    numStr.Add(3, "three");
    numStr.Add(4, "four");
    numStr.Add(5, "five");
    numStr.Add(6, "six");
    numStr.Add(7, "seven");
    numStr.Add(8, "eight");
    numStr.Add(9, "nine");
    numStr.Add(10, "ten");
    numStr.Add(11, "eleven");
    numStr.Add(12, "twelve");
    numStr.Add(13, "thirteen");
    numStr.Add(14, "fourteen");
    numStr.Add(15, "fifteen");
    for(int i=16; i<20; i++){
      numStr.Add(i, numStr[i%10]+"teen");
    }
    numStr[18]="eighteen";
    numStr.Add(20, "twenty");
    numStr.Add(30, "thirty");
    numStr.Add(40, "forty");
    numStr.Add(50, "fifty");
    for(int i=60; i<100; i+=10){
      numStr.Add(i, numStr[i/10]+"ty");
    }
    numStr[80]="eighty";
    numStr.Add(100, "onehundred");
    for(int i=200; i<1000; i+=100){
      numStr.Add(i, numStr[i/100]+"hundred");
    }
    long sum=0;
    for(int i=1; i<1000; i++){
      sum+=numStr[i/100*100].Length;
      if(i%100!=0 && i>100){
        sum+=3;
      }
      if(i%100>=20){
         sum+=numStr[(i%100)/10*10].Length;
         sum+=numStr[i%10].Length;
      }else if(i%100>=10){
         sum+=numStr[i%100].Length;
      }else if(i%100<10){
         sum+=numStr[i%10].Length;
      }
    }
    sum+="onethousand".Length;
    Console.WriteLine(sum);
  }
}
