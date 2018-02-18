
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
        for (int tc = 26; tc < 30; tc++) {
            out = new PrintWriter(new File("input" + makeNumber(tc) + ".txt"));
            int n = 1000 - rd.nextInt(1);
            out.println(n);
            Integer arr[] = new Integer[n];
            for (int i = 0; i < n; i++) {
                arr[i] = rd.nextInt(1000) - rd.nextInt(1000);
                out.println(arr[i]);
            }
            out.close();
            out = new PrintWriter(new File("output" + makeNumber(tc) + ".txt"));
            for (String str : originalSolution(new ArrayList(Arrays.asList(arr)))) {
                out.println(str);
            }
            out.close();
        }
    }
    
    // ---------------------My Code Ends Here------------------------
    
    static String[] originalSolution(ArrayList<Integer> input) {
        TreeSet<String> set = new TreeSet<>();
        ArrayList<String> arr = new ArrayList<>();
        int n = input.size();
        Collections.sort(input);
        for (int index = 0; index < n; index++) {
            int currentElement = input.get(index);
            int neededSum = -currentElement;
            int left = index + 1, right = n - 1;
            while (left < right) {
                int sum = input.get(left) + input.get(right);
                if (sum == neededSum) {
                    if (!set.contains(currentElement + "," + input.get(left) + "," + input.get(right))) {
                        set.add(currentElement + "," + input.get(left) + "," + input.get(right));
                        arr.add(currentElement + "," + input.get(left) + "," + input.get(right));
                    }
                    left++;
                } else if (sum > neededSum) {
                    right--;
                } else {
                    left++;
                }
            }
        }
        return arr.toArray(new String[set.size()]);
    }
    
    static String[] bruteForce(int[] arr) {
        HashSet<String> set = new HashSet<>();
        Arrays.sort(arr);
        int n = arr.length;
        for (int index_1 = 0; index_1 < n; index_1++) {
            for (int index_2 = index_1 + 1; index_2 < n; index_2++) {
                for (int index_3 = index_2 + 1; index_3 < n; index_3++) {
                    int sum = arr[index_1] + arr[index_2] + arr[index_3];
                    if (sum == 0) {
                        set.add(arr[index_1] + "," + arr[index_2] + "," + arr[index_3]);
                    }
                }
            }
        }
        String returnArray[] = set.toArray(new String[set.size()]);
        return returnArray;
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
