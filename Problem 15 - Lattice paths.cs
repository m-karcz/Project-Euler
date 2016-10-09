using System;

public class Problem15{
  public static void Main(){
    int size=21;
    long[,] grid=new long[size,size];
    for(int x=0; x<grid.GetLength(0); x++){
      grid[x,grid.GetLength(1)-1]=1;
    }
    for(int y=grid.GetLength(1)-2; y>=0; y--){
      grid[grid.GetLength(0)-1,y]=1;
      for(int x=grid.GetLength(0)-2; x>=0; x--){
        grid[x,y]=grid[x+1,y]+grid[x,y+1];
      }
    }
    Console.WriteLine(grid[0,0]);
  }
}
