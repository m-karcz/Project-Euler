using System;
using System.Linq;
using System.IO;
using System.Collections.Generic;

public class Problem11{
  public static void Main(){
    List<List<int>> grid=File.ReadAllLines("txt/Problem11.txt").ToList().Select(line=>line.Split(' ').Select(num=>Int32.Parse(num)).ToList()).ToList();
    int max=0;
    int size=20;
    int[][] coeff=new int[4][];
    coeff[0]=new int[]{0,3,0,1,0}; //horizontally
    coeff[1]=new int[]{0,0,3,0,1}; //vertically
    coeff[2]=new int[]{0,3,3,1,1}; //diagonally \
    coeff[3]=new int[]{3,0,3,-1,1};//diagonally /
    foreach(var c in coeff){
      for(int x=c[0]; x<size-c[1]; x++){
        for(int y=0; y<size-c[2]; y++){
          max=Math.Max(max,Enumerable.Range(0,4).Aggregate(1,(product,i)=>product*grid[x+c[3]*i][y+c[4]*i]));
        }
      }
    }
    Console.WriteLine(max);
  }
}
