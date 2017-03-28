import java.io.*;
import java.util.*;

public class ArrayProduct{
	public static int[] arrayProduct(int[] inputArray){
		if(inputArray == null || inputArray.length == 0) return inputArray;
		int[] productArray = new int[inputArray.length];
		int leftProduct = 1;
		for(int currentIndex = 0; currentIndex < inputArray.length; currentIndex++){
			productArray[currentIndex] = leftProduct;
			leftProduct *= inputArray[currentIndex];
		}
		int rightProduct = 1;
		for(int currentIndex = inputArray.length-1; currentIndex >= 0; currentIndex--){
			productArray[currentIndex] *= rightProduct;
			rightProduct *= inputArray[currentIndex];
		}
		return productArray;
	}

	public static void main(String[] args){
		Scanner scanner = new Scanner(System.in);
		int numberOfArrayElements = scanner.nextInt();
		int[] inputArray = new int[numberOfArrayElements];
		for(int currentIndex = 0; currentIndex < numberOfArrayElements; currentIndex++){
			inputArray[currentIndex] = scanner.nextInt();
		}

		int[] productArray = arrayProduct(inputArray);

		for(int currentIndex = 0; currentIndex < productArray.length; currentIndex++){
			System.out.print(productArray[currentIndex]+" ");
		}
		System.out.println();
	}
}
