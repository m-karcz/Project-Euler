using System;
using System.Linq;
using System.Collections.Generic;

public class Problem33{
  private class Fraction{
    public int num{get;set;}
    public int den{get;set;}
    public Fraction(int _num, int _den){num=_num; den=_den;}
    public bool Equals(Fraction other){
      return this.num*other.den==other.num*this.den;
    }
  }
  public static void Main(){
    List<Fraction> fracts=new List<Fraction>();
    var GetReduced=new Func<Fraction,List<Fraction>>(fr=>{
      var result=new List<Fraction>();
      if(fr.num/10==fr.den/10){
        result.Add(new Fraction(fr.num%10,fr.den%10));
      }
      if(fr.num/10==fr.den%10){
        result.Add(new Fraction(fr.num%10,fr.den/10));
      }
      if(fr.num%10==fr.den/10){
        result.Add(new Fraction(fr.num/10,fr.den%10));
      }
      if(fr.num%10==fr.den%10){
        result.Add(new Fraction(fr.num/10,fr.den/10));
      }
      return result;
    });
    for(int num=10; num<100; num++){
      for(int den=num; den<100; den++){
        if(num%10==0 || den%10==0){continue;}
        var cand=new Fraction(num,den);
        GetReduced(cand).Where(fr=>num<den && fr.Equals(cand)).ToList().ForEach(fr=>fracts.Add(fr));
      }
    }
    var product=fracts.Aggregate(new Fraction(1,1),(prod,fract)=>{prod.num*=fract.num;prod.den*=fract.den;return prod;});
    for(int i=2; i<=product.num; i++){
      while(product.num/i*i==product.num && product.den/i*i==product.den){
        product.num/=i;
        product.den/=i;
      }
    }
    Console.WriteLine(product.den);
  }
}
