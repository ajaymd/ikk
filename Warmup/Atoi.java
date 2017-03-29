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
