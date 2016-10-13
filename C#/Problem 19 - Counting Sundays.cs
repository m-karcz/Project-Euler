using System;
using System.Collections.Generic;
using System.Linq;

public class Problem19{
  public static int Days(int month, int year){
    switch(month){
      case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        return 31;
      case 4: case 6: case 9: case 11:
        return 30;
      case 2:
        return (year%4==0 && (year%100!=0 || year%400==0)) ? 29 : 28;
      default:
        Console.WriteLine("wrong month!");
        return -1;
    }
  }
  public static void Main(){
    int day=0;
    int sundays=0;
    for(int month=1; month<=12; month++){
      day=(day+Days(month, 1900))%7;
    }
    for(int year=1901; year<=2000; year++){
      for(int month=1; month<=12; month++){
       if((day=(day+Days(month,year))%7)==6){
          sundays++; 
       }
      }
    }
    Console.WriteLine(sundays);
  }
}
