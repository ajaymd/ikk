
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
        for (int tc = 25; tc < 30; tc++) {
            out = new PrintWriter(new File("input" + makeNumber(tc) + ".txt"));
            int n = 100000 - rd.nextInt(150);
            int values[] = new int[n];
            out.println(n);
            for (int i = 0; i < n; i++) {
                values[i] = rd.nextInt(100) + 901;
                out.print(values[i] + " ");
            }
            out.println();
            out.close();
            out = new PrintWriter(new File("output" + makeNumber(tc) + ".txt"));
            out.println(maxStolenValue(values));
            out.close();
        }
    }
    
    // ---------------------My Code Ends Here------------------------
    /*
     * Space Complexity: O(length(values))
     * Time Complexity: O((length(values))
     */
    private int maxStolenValue(int[] values) {
        int memo[] = new int[values.length];
        Arrays.fill(memo, -1);
        return maxStolenTill(values.length - 1, values, memo);
    }
    
    private int maxStolenTill(int index, int[] values, int[] memo) {
        if (index < 0) {
            return 0;
        }
        if (memo[index] != -1) {
            return memo[index];
        }
        if (index == 0) {
            return memo[index] = values[0];
        }
        if (index == 1) {
            return memo[index] = Math.max(values[0], values[1]);
        }
        return memo[index] = Math.max(maxStolenTill(index - 1, values, memo),
                                      maxStolenTill(index - 2, values, memo) + values[index]);
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
