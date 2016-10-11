using System;
using System.Linq;
using System.Collections.Generic;

namespace ProjectEuler{
  public class BigNum{
    public static List<int> Add(List<List<int>> addends){
      int maxCount=addends.Select(num=>num.Count()).ToList().Max();
      var sum=new List<int>();
      int carry=0;
      for(int i=0; i<maxCount; i++){
        foreach(var addend in addends){
          if(i<addend.Count()){
            carry+=addend[i];
          }
        }
        sum.Add(carry%10);
        carry=carry/10;
      }
      while(carry>0){
        sum.Add(carry%10);
        carry=carry/10;
      }
      return sum;
    }
    public static List<int> Multiply(List<int> factor1, int factor2){
      return Multiply(factor1, factor2.ToString().ToCharArray().Reverse().Select(c=>c-'0').ToList());
    }
    public static List<int> Multiply(List<int> factor1, List<int> factor2){
      var toSum=new List<List<int>>();
      for(int i=0; i<factor2.Count(); i++){
        var toAdd=MultiplyByDigit(factor1, factor2[i]);
        toAdd.InsertRange(0, Enumerable.Repeat(0,i).ToList());
        toSum.Add(toAdd);
      }
      return Add(toSum);
    }
    private static List<int> MultiplyByDigit(List<int> factor, int digit){
      int carry=0;
      var product=new List<int>();
      foreach(var f in factor){
        carry+=f*digit;
        product.Add(carry%10);
        carry=carry/10;
      }
      while(carry>0){
        product.Add(carry%10);
        carry=carry/10;
      }
      return product;
    }
  }
}
