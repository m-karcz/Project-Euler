using System;
using System.Collections.Generic;
using System.Linq;
using ProjectEuler;

public class Problem20{
  public static void Main(){
    List<int> product=new List<int>{1};
    for(int i=1; i<=100; i++){
      product=BigNum.Multiply(product,i);
    }
    Console.WriteLine(product.Sum());
  }
}
