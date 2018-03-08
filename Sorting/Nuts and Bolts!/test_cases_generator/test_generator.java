
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
            set.clear();
            out = new PrintWriter(new File("input" + makeNumber(tc) + ".txt"));
            int n = 100000 - rd.nextInt(5);
            out.println(n);
            ArrayList<Integer> arr = new ArrayList<>();
            int nuts[] = new int[n];
            for (int i = 0; i < n; i++) {
                arr.add(12499688 + i);
                nuts[i] = arr.get(i);
                out.println(arr.get(i));
            }
            int bolts[] = new int[n];
            // Collections.shuffle(arr);
            out.println(n);
            for (int i = 0; i < n; i++) {
                bolts[i] = arr.get(i);
                out.println(arr.get(i));
            }
            out.close();
            out = new PrintWriter(new File("output" + makeNumber(tc) + ".txt"));
            for (String str : solve(nuts, bolts)) {
                out.println(str);
            }
            out.close();
        }
    }
    
    // ---------------------My Code Ends Here------------------------
    static HashSet<Integer> set = new HashSet<Integer>();
    
    static int generateUniquePositiveInteger(Random rd, int range) {
        int pos = rd.nextInt(range) + 1;
        while (set.contains(pos)) {
            pos = rd.nextInt(range) + 1;
        }
        set.add(pos);
        return pos;
    }
    
    private static String[] solve(int nuts[], int bolts[]) {
        matchPairs(nuts, bolts, 0, nuts.length - 1);
        String str[] = new String[nuts.length];
        for (int i = 0; i < nuts.length; i++) {
            str[i] = nuts[i] + " " + bolts[i];
        }
        return str;
    }
    
    // Method which works just like quick sort
    private static void matchPairs(int[] nuts, int[] bolts, int low, int high) {
        if (low < high) {
            // Choose random integer of bolts array for nuts partition.
            int pivot = partition(nuts, low, high, bolts[new Random().nextInt(high - low + 1) + low]);
            
            // Now using the partition of nuts choose that for bolts
            // partition.
            partition(bolts, low, high, nuts[pivot]);
            
            // Recur for [low...pivot-1] & [pivot+1...high] for nuts and
            // bolts array.
            matchPairs(nuts, bolts, low, pivot - 1);
            matchPairs(nuts, bolts, pivot + 1, high);
        }
    }
    
    // Similar to standard partition method. Here we pass the pivot element
    // too instead of choosing it inside the method.
    private static int partition(int[] arr, int low, int high, int pivot) {
        int i = low;
        int temp1, temp2;
        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                // Move all elements smaller than pivot ahead in the array
                temp1 = arr[i];
                arr[i] = arr[j];
                arr[j] = temp1;
                i++;
            } else if (arr[j] == pivot) {
                // Move the matched element to the end
                // This is why we don't go to the last element in the iteration.
                temp1 = arr[j];
                arr[j] = arr[high];
                arr[high] = temp1;
                j--;
            }
        }
        // Swap the matched element from the last position to its correct place
        // i
        temp2 = arr[i];
        arr[i] = arr[high];
        arr[high] = temp2;
        
        // Return the partition index of an array based on the pivot
        // element of other array.
        return i;
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
