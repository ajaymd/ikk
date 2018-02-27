
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
            int n = 10000 - rd.nextInt(1);
            out.println(n);
            String arr[]=new String[n];
            for (int i = 0; i < n; i++) {
                arr[i] = generateString(rd, 256)+" "+generateString(rd, 800);
                out.println(arr[i]);
            }
            out.close();
            out = new PrintWriter(new File("output" + makeNumber(tc) + ".txt"));
            for (String str : originalSolution(arr)) {
                //out.println(str);
            }
            out.close();
        }
    }
    
    // ---------------------My Code Ends Here------------------------
    
    String availableChars = "1234567890abcdefghijklmnopqrstuvwxyz";
    
    private String generateString(Random rd, int size){
        StringBuilder sb =new StringBuilder();
        for(int i=0;i<size;i++){
            sb.append(availableChars.charAt(rd.nextInt(availableChars.length())));
        }
        return sb.toString();
    }
    
    private static String[] originalSolution(String[] arr) {
        HashMap<String, Integer> count = new HashMap<>();
        HashMap<String, String> maxValue = new HashMap<>();
        for (String x : arr) {
            String splits[] = x.split(" ");
            String key = splits[0];
            String value = splits[1];
            
            // If count contains the key, add 1 to it
            if (count.containsKey(key)) {
                count.put(key, count.get(key) + 1);
            }
            // Else put the value in map with count value 1
            else {
                count.put(key, 1);
            }
            
            // If maxValue contains key, put in map max of both values
            if (maxValue.containsKey(key)) {
                String value1 = maxValue.get(key);
                String value2 = value;
                if (value1.compareTo(value2) < 0) {
                    maxValue.put(key, value2);
                } else {
                    maxValue.put(key, value1);
                }
            }
            // Else add the new value
            else {
                maxValue.put(key, value);
            }
        }
        
        String answer[] = new String[count.size()];
        int pointer = 0;
        for (String key : count.keySet()) {
            answer[pointer++] = key + ":" + count.get(key) + "," + maxValue.get(key);
        }
        return answer;
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
