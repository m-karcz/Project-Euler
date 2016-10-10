using System;
using System.IO;
using System.Linq;

public class Problem345{
  public static void Main(){
    int[][] matrix=System.IO.File.ReadAllLines("Problem 345 - Matrix Sum.txt").Select(line=>line.Split(' ').Select(str=>-Int32.Parse(str)).ToArray()).ToArray();
    long sum=0;
    for(int y=0; y<matrix.Count(); y++){
      int min=matrix[y].Min();
      for(int x=0; x<matrix[y].Count(); x++){
        matrix[x][y]=matrix[x][y]-min;
        sum+=Math.Abs(min);
      }
    }
    
  }
}
