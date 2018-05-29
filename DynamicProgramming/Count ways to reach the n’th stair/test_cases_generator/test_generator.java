
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
        for (int tc = 0; tc < 4; tc++) {
            out = new PrintWriter(new File("input" + makeNumber(tc) + ".txt"));
            int n = 100 - rd.nextInt(10);
            int finalStep = rd.nextInt(100)+100;
            out.println(n);
            int steps[] = new int[n];
            HashSet<Integer> set = new HashSet<>();
            for (int i = 0; i < n; i++) {
                steps[i]=rd.nextInt(finalStep)+1;
                while(set.contains(steps[i])){
                    steps[i]=rd.nextInt(finalStep)+1;
                }
                set.add(steps[i]);
                out.print(steps[i]+" ");
            }
            out.println();
            out.println(finalStep);
            out.close();
            out = new PrintWriter(new File("output" + makeNumber(tc) + ".txt"));
            out.println(countWaysToClimb(steps, finalStep));
            out.close();
        }
    }
    
    // ---------------------My Code Ends Here------------------------
    /*
     * Space Complexity: O(n*length(steps))
     * Time Complexity: O(n*(length(steps))
     */
    private static long countWaysToClimb(int[] steps, int n) {
        /*
         * We will store counts till every step.
         */
        long countTillHere[] = new long[n + 1];
        // There is one way to reach till zero, as we start from 0
        countTillHere[0] = 1;
        for (int i = 1; i <= n; i++) {
            // Find the ways that you can reach here from current step
            for (int step : steps) {
                int previousStep = i - step;
                if (previousStep >= 0) {
                    countTillHere[i] += countTillHere[previousStep];
                }
            }
        }
        
        // Ways to reach the nth step
        return countTillHere[n];
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
