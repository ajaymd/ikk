/**
	Problem descrption:


Implement a power function to raise a double to an int power, including negative powers.
 
e.g. pow(double d, int p) should give 'd' raised to power 'p'.
 
Of course, please don't use in-built methods like pow(). Idea is to implement that using recursion.
 
 
Solution: http://stackoverflow.com/questions/101439/the-most-efficient-way-to-implement-an-integer-based-power-function-powint-int
 
Suggested time: 10 minutes to do a brute-force and 15 with a trick that optimizes it.
 
Note: In HackerRank, Double is simulated with "float".


*/
import java.io.*;
import java.util.*;

public class DoublePower{

	public static double pow(double baseValue, int exponentValue){
		if(exponentValue < 0){
			exponentValue *= -1; // make exponent positive
			baseValue = 1.0 / baseValue; // take the inverse value of base
		}
		double resultValue=1.0;
		while(exponentValue > 0){
			if(exponentValue % 2 ==1) resultValue *= baseValue; // when exponent is odd number
			baseValue *= baseValue;
			exponentValue /= 2;
		}
		return resultValue;
	}

	public static void main(String[] args){
		Scanner scanner = new Scanner(System.in);
		double baseValue = scanner.nextFloat();
		int exponentValue = scanner.nextInt();
		double resultValue = pow(baseValue, exponentValue);
		System.out.println(resultValue);
	}
}
/*
	Time compelxity: log(N) where N is the exponent value
	Space compelxity: O(1)
*/
