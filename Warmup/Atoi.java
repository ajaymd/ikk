/**
 * **************** PROBLEM DSCRIPTION **********************
 * Convert a string to an integer.

atoi() first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, it takes an optional plus or minus sign, followed by as many numerical digits as possible and interprets them as numerical value.

The string can contain additional characters after those that form the integral numbers, which are ignored and have no effect on the behavior of this function.
If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty, or it contains only whitespace characters, then no conversion is performed.

If no valid conversion is performed, a zero value is returned.

e.g.
"-3924x8fc" = -3924
"c++" = 0
"++1" = 0


Solution:  Aim for a linear order solution with constant space.

Estimated time given in a real interview: 15 minutes
*/

import java.io.*;
import java.util.*;

public class Atoi{
	public static int atoi(String inputString){
		if(inputString == null || inputString.isEmpty()) return 0;
		inputString = inputString.trim();
		if(inputString.isEmpty()) return 0;
		int startIndex = 0;
		boolean isNegative = false;
		if(inputString.charAt(startIndex) == '+'){
			startIndex++;
		}
		else if(inputString.charAt(startIndex) == '-'){
			startIndex++;
			isNegative = true;
		}
		int resultedNumberSoFar = 0;
		for(int currentIndex = startIndex; currentIndex < inputString.length(); currentIndex++){
			if(Character.isDigit(inputString.charAt(currentIndex))){
				resultedNumberSoFar = resultedNumberSoFar * 10 + (inputString.charAt(currentIndex) - '0');
			}
			else
				break;
		}
		if( isNegative ){
			resultedNumberSoFar *= -1;
		}
		return resultedNumberSoFar;
	}
	public static void main(String[] args){
		Scanner scanner = new Scanner(System.in);
		String inputString = scanner.nextLine();
		int result = atoi(inputString);
		System.out.println(result);
	}
}
/**
 * Time complexity: O(N)
 * Space complexity: O(1)
*/
