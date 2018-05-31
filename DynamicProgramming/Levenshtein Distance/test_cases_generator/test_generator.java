
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
        for (int tc = 29; tc < 30; tc++) {
            out = new PrintWriter(new File("input" + makeNumber(tc) + ".txt"));
            int n = 1000 - rd.nextInt(1);
            int m = 1000 - rd.nextInt(1);
            String a = generateString(rd, n);
            String b = generateString(rd, m);
            out.println(a);
            out.println(b);
            out.close();
            out = new PrintWriter(new File("output" + makeNumber(tc) + ".txt"));
            out.println(levenshteinDistance(a, b));
            out.close();
        }
    }

    // ---------------------My Code Ends Here------------------------
    /*
     * Space Complexity: O(length(strWord1)*length(strWord2)) 
     * Time Complexity: O(length(strWord1)*length(strWord2))
     */
    static int levenshteinDistance(String strWord1, String strWord2) {
        char a[] = strWord1.toCharArray();
        char b[] = strWord2.toCharArray();
        int n = a.length;
        int m = b.length;

        // Fill all values in table with a maximum value
        int dp[][] = new int[n + 1][m + 1];
        for (int i = 0; i <= n; i++) {
            Arrays.fill(dp[i], n + m);
        }
        dp[0][0] = 0;
        for (int i = 1; i <= n; i++) {
            // If second string is empty, only option is to
            // remove all characters of second string
            dp[i][0] = i;
        }
        for (int i = 1; i <= m; i++) {
            // If first string is empty, only option is to
            // isnert all characters of second string
            dp[0][i] = i;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (a[i - 1] == b[j - 1]) {
                    // If last characters are same, ignore last char
                    // and recur for remaining string
                    dp[i][j] = Math.min(dp[i][j], dp[i - 1][j - 1]);
                } else {
                    // If the last character is different, consider all
                    // possibilities and find the minimum
                    dp[i][j] = Math.min(dp[i][j],
                            1 + Math.min(dp[i - 1][j - 1], // Replace
                                Math.min(dp[i - 1][j], // Remove
                                         dp[i][j - 1] // Insert
                                    )));
                }
            }
        }
        return dp[n][m];
    }

    String availableChars = "abcdefghijklmnopqrstuvwxyz";

    private String generateString(Random rd, int size) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < size; i++) {
            sb.append(availableChars.charAt(rd.nextInt(availableChars.length())));
        }
        return sb.toString();
    }

    private String makeNumber(int x) {
        String number = x + "";
        while (number.length() < 3) {
            number = "0" + number;
        }
        return number;
    }

    static class Node implements Comparable<Node> {
        int value;
        int row;
        int column;

        Node(int xx, int yy, int zz) {
            value = xx;
            row = yy;
            column = zz;
        }

        @Override
        public int compareTo(Node o) {
            return Long.compare(this.value, o.value);
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
