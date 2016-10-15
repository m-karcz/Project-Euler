using System;
using System.Linq;
using System.Collections.Generic;

public class Problem43{
  private static List<long> GeneratePandigital(long builded, List<long> digits){
    return digits.Any() ? digits.Select(digit=>GeneratePandigital(builded*10+digit, digits.Except(new List<long>{digit}).ToList())).SelectMany(s=>s).ToList() : new List<long>{builded};
  }
  public static void Main(){
    Console.WriteLine(
      GeneratePandigital(0,new List<long>{0,1,2,3,4,5,6,7,8,9}).Select(num=>num.ToString()
                                                                               .ToCharArray()
                                                                               .Select(c=>c-'0'))
                                                                               .Select(list=>{var newList=list.ToList(); if(newList.Count()<10){newList.Insert(0,0);} return newList;})
                                                               .Where(num=>(num.ElementAt(1)*100+num.ElementAt(2)*10+num.ElementAt(3))%2==0)
                                                               .Where(num=>(num.ElementAt(2)*100+num.ElementAt(3)*10+num.ElementAt(4))%3==0)
                                                               .Where(num=>(num.ElementAt(3)*100+num.ElementAt(4)*10+num.ElementAt(5))%5==0)
                                                               .Where(num=>(num.ElementAt(4)*100+num.ElementAt(5)*10+num.ElementAt(6))%7==0)
                                                               .Where(num=>(num.ElementAt(5)*100+num.ElementAt(6)*10+num.ElementAt(7))%11==0)
                                                               .Where(num=>(num.ElementAt(6)*100+num.ElementAt(7)*10+num.ElementAt(8))%13==0)
                                                               .Where(num=>(num.ElementAt(7)*100+num.ElementAt(8)*10+num.ElementAt(9))%17==0)
                                                               .Select(list=>list.Aggregate(0L,(num,digit)=>{return (num+digit)*10;}))
                                                               .Sum()/10
                                                               
    ); 
  }
}
