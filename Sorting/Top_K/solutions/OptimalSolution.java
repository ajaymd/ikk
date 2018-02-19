import java.util.TreeSet;

public class OptimalSolution {
    /*
     * Time Complexity: O(N*log(K))
     * Space Complexity: O(K)
     */
	static int[] topK(int[] arr, int k) {
        // TreeSet will maintain set of elements in a sorted fashion
		TreeSet<Integer> tree = new TreeSet<Integer>();
        /*
        We will add all elements to the sorted set and when size of the set increases over 
        required size K, we will remove the smallest element
        */
		for (int x : arr) {
			tree.add(x);
			if (tree.size() > k) {
				tree.pollFirst();
			}
		}
		int ans[] = new int[tree.size()];
		int ptr = 0;
		for (int x : tree) {
			ans[ptr++] = x;
		}
		return ans;
	}
}
