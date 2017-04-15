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
