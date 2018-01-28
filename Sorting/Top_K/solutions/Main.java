import java.util.TreeSet;

public class Main {
	static int[] topK(int[] arr, int k) {
		TreeSet<Integer> tree = new TreeSet<Integer>();
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
