package Array_Product.solutions; /**
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

import java.util.*;

public class optimal_solution {

    // -------------------- START ----------------------

    public static int[] arrayProduct(int[] inputArray) {
        // Check if input array is null or is empty
        if (inputArray == null || inputArray.length == 0) return inputArray;

        // Size of output array is same as that of input array
        int[] productArray = new int[inputArray.length];

        // For finding value of productArray[i], product of all inputArray elements other than ith element is nothing but
        // (product of all inputArray[j], 0<=j<=(i-1)) * (product of all inputArray[j], (i+1)<=j<=(inputArray.length-1))
        // i.e. (inputArray[0]*inputArray[1]*...*inputArray[i-1]) *
        //                                          (inputArray[i+1]*inputArray[i+2]*...*inputArray[inputArray.length-1])

        int leftProduct = 1;

        // Filling productArray, such that productArray[i] contains product of all elements inputArray[j], 0<=j<=(i-1)
        for (int currentIndex = 0; currentIndex < inputArray.length; currentIndex++) {
            productArray[currentIndex] = leftProduct;       // Here, leftProduct contains product of all elements
                                                            // inputArray[j], 0<=j<=(currentIndex-1)
            leftProduct *= inputArray[currentIndex];        // After this updation, leftProduct contains product of all
                                                            // elements inputArray[j], 0<=j<=currentIndex
        }

        int rightProduct = 1;

        // Updating productArray, such that productArray[i] contains new value
        // ((productArray[i]) * (product of all elements inputArray[j], 0<=j<=(i-1)))
        for (int currentIndex = inputArray.length - 1; currentIndex >= 0; currentIndex--) {
            productArray[currentIndex] *= rightProduct;     // Here, rightProduct contains product of all elements
                                                            // inputArray[j], (currentIndex+1)<=j<=(inputArray.length-1)
            rightProduct *= inputArray[currentIndex];       // after this updation, rightProduct contains product of all
                                                        // elements inputArray[j], currentIndex<=j<=(inputArray.length-1)
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
 * Time complexity: O(N)
 * Space complexity: O(N)
 */
