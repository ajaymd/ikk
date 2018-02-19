public class OptimalSolution {
	static int[] solve(int[] arr) {
		int n = arr.length;
		/*
		Initialize left pointer to the start of the array and right pointer to the end of the 
		array
		*/
		int left = 0, right = n - 1;
		// Move the pointers till they cross each other 
		while (right >= left) {
			if (arr[right] % 2 == 0) {
				int tmp = arr[right];
				arr[right] = arr[left];
				arr[left] = tmp;
				/*
				left will always be increased and all values to the left of the left pointer will
				be even
				*/
				left++;
			} else {
				/*
				right will always be decreased and all values to the right of the right pointer 
				will be odd
				*/
				right--;
			}
		}
		/*
		 * Our solution is in-place solution, as we are making changes in the input array
		 * Time Complexity: O(n)
		 * Space Complexity: O(1) 
		 */
		return arr;
	}
}
