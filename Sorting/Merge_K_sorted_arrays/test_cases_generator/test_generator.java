
import java.io.*;
import java.math.*;
import java.util.*;

public class A {

	InputReader in;
	PrintWriter out;

	A() throws IOException {
		in = new InputReader(System.in);
		out = new PrintWriter(System.out);
		// in = new InputReader(new FileInputStream("input_codejam.txt"));
		// out = new PrintWriter(new File("output_codejam.txt"));
		solve();
		out.close();
	}

	public static void main(String args[]) {
		new Thread(null, new Runnable() {
			public void run() {
				try {
					new A();
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		}, "1", 1 << 26).start();
	}

	// --------------------My Code Starts Here----------------------
	long mod = (long) 1e9 + 7;
	double eps = 1e-4;

	public void solve() throws IOException {
		Random rd = new Random();
		for (int tc = 15; tc < 30; tc++) {
			out = new PrintWriter(new File("input" + tc + ".txt"));
			int k = 500 - rd.nextInt(100);
			int n = 500 - rd.nextInt(300);
			out.println(k);
			out.println(n);
			int arr[][] = new int[k][n];
			for (int i = 0; i < k; i++) {
				int prev = 0;
				for (int j = 0; j < n; j++) {
					prev = prev + rd.nextInt(3000);
					arr[i][j] = prev;
					out.println(prev);
				}
			}
			out.close();
			out = new PrintWriter(new File("output" + tc + ".txt"));
			int ans[] = mergeArrays(arr);
			for (int x : ans) {
				out.println(x);
			}
			out.close();
		}
	}

	// ---------------------My Code Ends Here------------------------
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
			if (Long.compare(this.x, o.x) != 0)
				return Long.compare(this.x, o.x);
			else
				return Long.compare(this.y, o.y);
		}
	}

	public static void debug(Object... o) {
		System.out.println(Arrays.deepToString(o));
	}

	static final class InputReader {
		private final InputStream stream;
		private final byte[] buf = new byte[1024];
		private int curChar;
		private int numChars;

		public InputReader(InputStream stream) {
			this.stream = stream;
		}

		private int read() throws IOException {
			if (curChar >= numChars) {
				curChar = 0;
				numChars = stream.read(buf);
				if (numChars <= 0)
					return -1;
			}
			return buf[curChar++];
		}

		public final int nextInt() throws IOException {
			return (int) nextLong();
		}

		public final long nextLong() throws IOException {
			int c = read();
			while (isSpaceChar(c)) {
				c = read();
				if (c == -1)
					throw new IOException();
			}
			boolean negative = false;
			if (c == '-') {
				negative = true;
				c = read();
			}
			long res = 0;
			do {
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res *= 10;
				res += (c - '0');
				c = read();
			} while (!isSpaceChar(c));
			return negative ? (-res) : (res);
		}

		public final int[] readIntBrray(int size) throws IOException {
			int[] arr = new int[size];
			for (int i = 0; i < size; i++)
				arr[i] = nextInt();
			return arr;
		}

		public final String next() throws IOException {
			int c = read();
			while (isSpaceChar(c))
				c = read();
			StringBuilder res = new StringBuilder();
			do {
				res.append((char) c);
				c = read();
			} while (!isSpaceChar(c));
			return res.toString();
		}

		public final String nextLine() throws IOException {
			int c = read();
			while (isSpaceChar(c))
				c = read();
			StringBuilder res = new StringBuilder();
			do {
				res.append((char) c);
				c = read();
			} while (c != '\n' && c != -1);
			return res.toString();
		}

		private boolean isSpaceChar(int c) {
			return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
		}
	}
}
