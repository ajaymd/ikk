import java.util.PriorityQueue;

public class Main {
	static int[] mergeArrays(int[][] arr) {
		PriorityQueue<Pair> pq = new PriorityQueue<>();
		int k = arr.length;
		int n = arr[0].length;
		for (int i = 0; i < k; i++) {
			pq.add(new Pair(arr[i][0], i, 0));
		}
		int ans[] = new int[n * k];
		int ptr = 0;
		while (ptr < n * k) {
			Pair rem = pq.poll();
			ans[ptr++] = rem.x;
			if (rem.z + 1 < n) {
				pq.add(new Pair(arr[rem.y][rem.z + 1], rem.y, rem.z + 1));
			}
		}
		return ans;
	}

	static class Pair implements Comparable<Pair> {
		int x;
		int y;
		int z;

		Pair(int xx, int yy, int zz) {
			x = xx;
			y = yy;
			z = zz;
		}

		public String toString() {
			return "[x=" + this.x + ", y=" + this.y + "]";
		}

		@Override
		public int compareTo(Pair o) {
			return Long.compare(this.x, o.x);
		}
	}

}
