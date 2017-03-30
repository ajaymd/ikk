/**
 ************************ PROBLEM DESCRIPTION ***************************
 Given an array of numbers, nums, return an array of numbers products, where products[i]is the product of all nums[j], j != i.

Input : [1, 2, 3, 4, 5]
Output: [(2*3*4*5), (1*3*4*5), (1*2*4*5), (1*2*3*5), (1*2*3*4)]
      = [120, 60, 40, 30, 24]
You must do this in O(N) time, and constant space, without using division. Usage of products array is not considered extra space.

Without using division is the key constraint to remember.
*/

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

/**
 * Time complexity: O(N)
 * Space complexity: O(N)
*/
