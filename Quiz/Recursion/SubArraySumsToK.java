package coursework;

import java.util.Stack;

/**
 * Given Inputs:
 * 
 * 1. An array of integers 2. Target K
 * 
 * Required Output: Boolean true or false, whether there is a group of
 * integers (may or may not be contiguous) in the input, that sums to K.
 * e.g.
 * Sum({2, 4, 8}, 6) → true
 * Sum({2, -4, 8}, 1) → false
 * Sum({2, 4, 8}, 14) → true
 * Sum({2, 4, 8}, 9) → false
 * 
 */

public class SubArraySumsToK {
	
	int[] data = null;
	Stack<Integer> sums = null;
	int sumInStack = 0;
	
	public SubArraySumsToK(int[] data) {
		sums = new Stack<Integer>();
		this.data = data;
	}

	private boolean sumsToK(int k) {
		if ((data == null) || (data.length == 0)) {
			return false;
		}
		
		return sumsToK(k, 0, data.length);
	}
	
	private boolean sumsToK(int k, int from, int to) {
		
		if (sumInStack == k) {
			return true;
		}

		boolean sumsToK = false;

		for (int index = from; index < to; index++) {

			if (sumInStack + data[index] <= k) {
				sums.push(data[index]);
				sumInStack += data[index];
				
				sumsToK = sumsToK(k, index + 1, to);
				sumInStack -= sums.pop();
				
				if (sumsToK) {
					break;
				}
			}
		}
		
		return sumsToK;
	}
	
	public static void main(String[] args) {
		System.out.println("Sum({2, 4, 8}, 6) = " +
			new SubArraySumsToK(new int[]{ 2, 4, 8 }).sumsToK(6));
		
		System.out.println("Sum({2, -4, 8}, 1) = " +
			new SubArraySumsToK(new int[]{ 2, -4, 8 }).sumsToK(1));
		
		System.out.println("Sum({2, 4, 8}, 14) = " +
			new SubArraySumsToK(new int[]{ 2, 4, 8 }).sumsToK(14));
		
		System.out.println("Sum({2, 4, 8}, 9) = " +
			new SubArraySumsToK(new int[]{ 2, 4, 8 }).sumsToK(9));
	}
}
