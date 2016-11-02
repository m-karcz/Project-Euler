public class Problem71{
  public static void main(String[] args){
    int max_numerator=2;
    int max_denominator=7;
    for(int denominator=1; denominator<=1000000; denominator++){
      if(max_numerator*denominator<(denominator*3/7-1)*max_denominator){
        max_numerator=denominator*3/7-1;
        max_denominator=denominator;
      }
    }
    System.out.println(max_numerator);
  }
}
