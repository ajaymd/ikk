
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
		for (int tc = 10; tc < 20; tc++) {
			out = new PrintWriter(new File("input" + tc + ".txt"));
			int n = 10 - rd.nextInt(10);
			out.println(n);
			for (int i = 0; i < n; i++) {
				out.println(rd.nextInt((int)10)+1);
			}
			out.close();
			out = new PrintWriter(new File("output" + tc + ".txt"));
			out.close();
		}
	}

	// ---------------------My Code Ends Here------------------------

	static long modulo(long a, long b, long c) {
		long x = 1;
		long y = a;
		while (b > 0) {
			if (b % 2 == 1) {
				x = (x * y) % c;
			}
			y = (y * y) % c; // squaring the base
			b /= 2;
		}
		return x % c;
	}

	static class Pair implements Comparable<Pair> {
		long x;
		int y;

		Pair(long xx, int yy) {
			x = xx;
			y = yy;
		}

		public String toString() {
			return "[x=" + this.x + ", y=" + this.y + "]";
		}

		@Override
		public int compareTo(Pair o) {
			if (Long.compare(this.x, o.x) != 0)
				return -Long.compare(this.x, o.x);
			else
				return -Long.compare(this.y, o.y);
		}
	}

	static int[] solve1(int[] arr) {
		int ptr = 0;
		for (int i = 0; i < arr.length; i++) {
			if (arr[i] % 2 == 0) {
				int tmp = arr[ptr];
				arr[ptr] = arr[i];
				arr[i] = tmp;
				while (ptr < arr.length && arr[ptr] % 2 == 0) {
					ptr++;
				}
			}
		}
		return arr;
	}

	static int[] solve(int[] arr) {
		int ans[] = new int[arr.length];
		int ptr = 0;
		for (int i = 0; i < arr.length; i++) {
			if (arr[i] % 2 == 0)
				ans[ptr++] = arr[i];
		}
		for (int i = 0; i < arr.length; i++) {
			if (arr[i] % 2 == 1)
				ans[ptr++] = arr[i];
		}
		return ans;
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
