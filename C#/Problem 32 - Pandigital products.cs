using System;
using System.Linq;
using System.Collections.Generic;

public class Problem32{
  public static void Main(){
    Pandigital pandigital=new Pandigital();
    for(int i=1; i<50000; i++){
      for(int j=i; j<50000; j++){
        int product=i*j;
        if((product.ToString()+i.ToString()+j.ToString()).Length>9){
          break;
        }
        pandigital.checkPandigitality(i.ToString(), j.ToString(), product.ToString());
      }
    }
    Console.WriteLine(pandigital.GetProductSum());
  }
  private class Pandigital{
    public void checkPandigitality(string mul1, string mul2, string product){
      if(pandigitals.Contains(product)){
        return;
      }
      string pan=product+mul1+mul2;
      if(pan.Length!=9){
        return;
      }
      if(new HashSet<char>(pan.ToCharArray().ToList()).SetEquals(new List<char>{'1','2','3','4','5','6','7','8','9'})){
        pandigitals.Add(product);
      }
      return;
    }
    private List<string> pandigitals=new List<string>();
    public int GetProductSum(){
      return pandigitals.Select(s=>Int32.Parse(s)).Sum();
    }
  }
}
