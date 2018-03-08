package Array_Product.solutions;
/**
 * *********************** PROBLEM DESCRIPTION ***************************
 * Given an array of numbers, nums, return an array of numbers products, where products[i]is the product of all nums[j],
 * j != i.
 * <p>
 * Input : [1, 2, 3, 4, 5]
 * Output: [(2*3*4*5), (1*3*4*5), (1*2*4*5), (1*2*3*5), (1*2*3*4)]
 * = [120, 60, 40, 30, 24]
 * You must do this in O(N) time, and constant space, without using division. Usage of products array is not considered
 * extra space.
 * <p>
 * Without using division is the key constraint to remember.
 */

import java.util.Scanner;

public class brute_force {

    // -------------------- START ----------------------

    public static int[] arrayProduct(int[] inputArray) {
        // Check if input array is null or is empty
        if (inputArray == null || inputArray.length == 0) return inputArray;

        // Size of output array is same as that of input array
        int[] productArray = new int[inputArray.length];

        for (int currentIndex = 0; currentIndex < inputArray.length; currentIndex++) {
            productArray[currentIndex] = 1;
            for (int iterator = 0; iterator < inputArray.length; iterator++) {
                if (iterator != currentIndex) {
                    productArray[currentIndex] *= inputArray[iterator];
                }
            }
        }

        return productArray;
    }

    // -------------------- END ----------------------

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int numberOfArrayElements = scanner.nextInt();
        int[] inputArray = new int[numberOfArrayElements];
        for (int currentIndex = 0; currentIndex < numberOfArrayElements; currentIndex++) {
            inputArray[currentIndex] = scanner.nextInt();
        }

        int[] productArray = arrayProduct(inputArray);

        for (int currentIndex = 0; currentIndex < productArray.length; currentIndex++) {
            System.out.println(productArray[currentIndex] + " ");
        }
        System.out.println();
    }
}

/**
 * Time complexity: O(N*N)
 * Space complexity: O(N)
 */
