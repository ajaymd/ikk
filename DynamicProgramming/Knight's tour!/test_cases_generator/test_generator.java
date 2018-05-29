
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
        // Handmade testcases for this problem
    }
    
    // ---------------------My Code Ends Here------------------------
    /*
     * Space Complexity: O(phonenumberlength)
     * Time Complexity: O(phonenumberlength)
     */
    public static long numPhoneNumbers(int startdigit, int phonenumberlength) {
        
        // List of where integers where you can go from a particular integer
        ArrayList<ArrayList<Integer>> listOfNext = new ArrayList<>();
        
        // 0
        listOfNext.add(new ArrayList<Integer>());
        listOfNext.get(0).add(4);
        listOfNext.get(0).add(6);
        
        // 1
        listOfNext.add(new ArrayList<Integer>());
        listOfNext.get(1).add(6);
        listOfNext.get(1).add(8);
        
        // 2
        listOfNext.add(new ArrayList<Integer>());
        listOfNext.get(2).add(7);
        listOfNext.get(2).add(9);
        
        // 3
        listOfNext.add(new ArrayList<Integer>());
        listOfNext.get(3).add(4);
        listOfNext.get(3).add(8);
        
        // 4
        listOfNext.add(new ArrayList<Integer>());
        listOfNext.get(4).add(3);
        listOfNext.get(4).add(9);
        listOfNext.get(4).add(0);
        
        // 5
        listOfNext.add(new ArrayList<Integer>());
        
        // 6
        listOfNext.add(new ArrayList<Integer>());
        listOfNext.get(6).add(1);
        listOfNext.get(6).add(7);
        listOfNext.get(6).add(0);
        
        // 7
        listOfNext.add(new ArrayList<Integer>());
        listOfNext.get(7).add(2);
        listOfNext.get(7).add(6);
        
        // 8
        listOfNext.add(new ArrayList<Integer>());
        listOfNext.get(8).add(1);
        listOfNext.get(8).add(3);
        
        // 9
        listOfNext.add(new ArrayList<Integer>());
        listOfNext.get(9).add(4);
        listOfNext.get(9).add(2);
        
        long numTill[][] = new long[phonenumberlength][10];
        // First digit is already given. So we can only form one number of length 1.
        numTill[0][startdigit] = 1;
        
        for(int i = 1; i < phonenumberlength; i++){
            for(int num = 0; num < 10; num++){
                for(int to:listOfNext.get(num)){
                    // We can come to num from all its neighbours.
                    // So we will add all possible numbers of length i-1 that are neighnours of num.
                    numTill[i][num] += numTill[i-1][to];
                }
            }
        }
        
        long ans = 0;
        // Sum all possible ending of length phonenumberlength
        for(int num = 0; num < 10; num++){
            ans += numTill[phonenumberlength-1][num];
        }
        return ans;
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
