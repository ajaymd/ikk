package coursework;

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

public class ArraySubsetSumsToK {
	
	int[] data = null;
	
	public ArraySubsetSumsToK(int[] data) {
		this.data = data;
	}

	private boolean sumsToK(int k) {
		if ((data == null) || (data.length == 0)) {
			return false;
		}
		
		if (k == 0) {
			System.out.println("Sum to zero not supported; always matches.");
		}
		
		return sumsToK(data, data.length, k);
	}
	
	private boolean sumsToK(int[] array, int count, int sum) {
		
		if (sum == 0) {
		     return true;
		}
		
		if (count == 0) {
			return false;
		}
		 
		return
			sumsToK(array, count-1, sum) ||
			sumsToK(array, count-1, (sum - array[count-1]));
	}
	
	public static void main(String[] args) {
		System.out.println("Sum({2, 4, 8}, 6) = " +
			new ArraySubsetSumsToK(new int[]{ 2, 4, 8 }).sumsToK(6));
		
		System.out.println("Sum({2, -4, 8}, 2) = " +
			new ArraySubsetSumsToK(new int[]{ 2, -4, 8 }).sumsToK(2));
		
		System.out.println("Sum({2, -4, 8}, 1) = " +
			new ArraySubsetSumsToK(new int[]{ 2, -4, 8 }).sumsToK(1));
		
		System.out.println("Sum({2, 4, 8}, 14) = " +
			new ArraySubsetSumsToK(new int[]{ 2, 4, 8 }).sumsToK(14));
		
		System.out.println("Sum({2, 4, 8}, 9) = " +
			new ArraySubsetSumsToK(new int[]{ 2, 4, 8 }).sumsToK(9));
		
		System.out.println("Sum({2, -4, 8}, 6) = " +
			new ArraySubsetSumsToK(new int[]{ 2, -4, 8 }).sumsToK(6));
		
		System.out.println("Sum({2, -8, 8}, 0) = " +
			new ArraySubsetSumsToK(new int[]{ 2, -8, 8 }).sumsToK(0));

		System.out.println("Sum({2, -8, 7}, 0) = " +
			new ArraySubsetSumsToK(new int[]{ 2, -8, 7 }).sumsToK(0));
		
		System.out.println("Sum({-2, -4, 8}, -6) = " +
			new ArraySubsetSumsToK(new int[]{ -2, -4, 8 }).sumsToK(6));
	}
}
