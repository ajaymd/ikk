public class Main {
	static int[] solve(int[] arr) {
		int n = arr.length;
		int left = 0, right = n - 1;
		while (right >= left) {
			if (arr[right] % 2 == 0) {
				int tmp = arr[right];
				arr[right] = arr[left];
				arr[left] = tmp;
				left++;
			} else {
				right--;
			}
		}
		return arr;
	}
}
