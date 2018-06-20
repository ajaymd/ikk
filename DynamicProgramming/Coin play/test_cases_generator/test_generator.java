
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
        for (int tc = 27; tc < 30; tc++) {
            out = new PrintWriter(new File("input" + makeNumber(tc) + ".txt"));
            int n = 1000 - rd.nextInt(10);
            out.println(n);
            int v[] = new int[n];
            for(int i=0;i<n;i++){
                v[i]=1000000-rd.nextInt(100);
                out.print(v[i]+" ");
            }
            out.println();
            out.close();
            out = new PrintWriter(new File("output" + makeNumber(tc) + ".txt"));
            out.println(maxWin(v));
            out.close();
        }
    }
    
    // ---------------------My Code Ends Here------------------------
    /*
     * Space Complexity: O(n*n)
     * Time Complexity: O(n*n)
     */
    static int maxWin(int arr[]) {
        int n = arr.length;
        // Create a table to store solutions of subproblems
        int table[][] = new int[n][n];
        recursiveSolve(arr, table, 0, n - 1);
        return table[0][n - 1];
    }
    
    static int recursiveSolve(int arr[], int table[][], int start, int end) {
        if (table[start][end] != 0) {
            return table[start][end];
        }
        if (start == end) {
            return table[start][end] = arr[start];
        }
        if (start + 1 == end) {
            return table[start][end] = Math.max(arr[start], arr[end]);
        }
        
        table[start][end] = Math.max(
                                     arr[start] + Math.min(recursiveSolve(arr, table, start + 2, end),
                                                           recursiveSolve(arr, table, start + 1, end - 1)),
                                     arr[end] + Math.min(recursiveSolve(arr, table, start + 1, end - 1),
                                                         recursiveSolve(arr, table, start, end - 2)));
        return table[start][end];
        
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
