
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
        for (int tc = 25; tc < 28; tc++) {
            out = new PrintWriter(new File("input" + makeNumber(tc) + ".txt"));
            int n = 100000 - rd.nextInt(100);
            boolean occupied[] = new boolean[n];
            ArrayList<Integer> arr = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                arr.add(-1);
            }
            for (int i = 1; i < n - 1; i++) {
                if (rd.nextInt(100) == 0) {
                    int to = rd.nextInt(n);
                    if (!occupied[to] && !occupied[i] && to != i) {
                        arr.set(i, to);
                        occupied[i] = occupied[to] = true;
                    }
                }
            }
            out.println(n);
            out.println(n);
            for (int i = 0; i < n; i++) {
                if (arr.get(i) != -1)
                    arr.set(i, arr.get(i) + 1);
                out.println(arr.get(i));
            }
            out.close();
            int[] moves = new int[n];
            for (int i = 0; i < n; i++) {
                moves[i] = arr.get(i);
                if (moves[i] != -1)
                    moves[i]--;
            }
            out = new PrintWriter(new File("output" + makeNumber(tc) + ".txt"));
            out.println(minNumberOfRollsHelper(moves, n));
            out.close();
        }
    }
    
    // ---------------------My Code Ends Here------------------------
    
    // ==================start==================
    
    /*
     * Space Complexity: O(n) Time Complexity: O(n)
     */
    static int minNumberOfRolls(int n, List<Integer> moves) {
        int[] move = new int[n];
        // Converting to 0 index based array
        for (int i = 0; i < n; i++) {
            move[i] = moves.get(i);
            if (move[i] != -1)
                move[i]--;
        }
        return minNumberOfRollsHelper(move, n);
    }
    
    // An entry in queue used in BFS
    static class qentry {
        int v;// Vertex number
        int dist;// Distance of this vertex from source
    }
    
    // This function returns minimum number of dice
    // throws required to Reach last cell from 0'th cell
    // in a snake and ladder game. move[] is an array of
    // size N where N is no. of cells on board If there
    // is no snake or ladder from cell i, then move[i]
    // is -1 Otherwise move[i] contains cell to which
    // snake or ladder at i takes to.
    static int minNumberOfRollsHelper(int move[], int n) {
        int visited[] = new int[n];
        Queue<qentry> q = new LinkedList<>();
        qentry qe = new qentry();
        qe.v = 0;
        qe.dist = 0;
        
        // Mark the node 0 as visited and enqueue it.
        visited[0] = 1;
        q.add(qe);
        
        // Do a BFS starting from vertex at index 0
        while (!q.isEmpty()) {
            qe = q.remove();
            int v = qe.v;
            
            // If front vertex is the destination
            // vertex, we are done
            if (v == n - 1)
                break;
            
            // Otherwise dequeue the front vertex and
            // enqueue its adjacent vertices (or cell
            // numbers reachable through a dice throw)
            for (int j = v + 1; j <= (v + 6) && j < n; ++j) {
                // If this cell is already visited, then ignore
                if (visited[j] == 0) {
                    // Otherwise calculate its distance and
                    // mark it as visited
                    qentry a = new qentry();
                    a.dist = (qe.dist + 1);
                    visited[j] = 1;
                    
                    // Check if there a snake or ladder at 'j'
                    // then tail of snake or top of ladder
                    // become the adjacent of 'i'
                    if (move[j] != -1)
                        a.v = move[j];
                    else
                        a.v = j;
                    q.add(a);
                }
            }
        }
        
        // We reach here when 'qe' has last vertex
        // return the distance of vertex in 'qe'
        if (qe.v == n - 1)
            return qe.dist;
        else
            return -1;
    }
    
    // ==================end==================
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
