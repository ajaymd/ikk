
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
        for (int tc = 0; tc < 30; tc++) {
            in = new InputReader(new FileInputStream("input" + makeNumber(tc) + ".txt"));
            int n = in.nextInt();
            int m = in.nextInt();
            
            List<String> grid = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                grid.add(in.nextLine());
            }
            out = new PrintWriter(new File("output" + makeNumber(tc) + ".txt"));
            shortestDistanceFromAGuard(grid).stream().forEach(r -> {
                r.stream().forEach(x -> {
                    out.print(x + " ");
                });
                out.println();
            });
            out.close();
        }
    }
    
    // ---------------------My Code Ends Here------------------------
    
    // ==================start==================
    
    /*
     * Space Complexity: O(n*m) Time Complexity: O(n*m)
     */
    // Complete the shortestDistanceFromAGuard function below.
    static char GUARD = 'G';
    static char OPEN = 'O';
    static char WALL = 'W';
    
    static List<List<Integer>> shortestDistanceFromAGuard(List<String> grid) {
        int n = grid.size();
        int m = grid.get(0).length();
        List<List<Integer>> distance = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            distance.add(new ArrayList<Integer>());
            for (int j = 0; j < m; j++) {
                distance.get(i).add(-1);
            }
        }
        
        Queue<Node> queue = new LinkedList<>();
        // Initialize marker to keep track of visited cells
        boolean visited[][] = new boolean[n][m];
        // Adding all guards to the Queue
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid.get(i).charAt(j) == GUARD) {
                    // Cells with guards are at 0 distance from the Guard
                    queue.add(new Node(i, j, 0));
                }
            }
        }
        // Starting a multi-source BFS
        while (!queue.isEmpty()) {
            Node removedCell = queue.poll();
            // Continue if already visited
            if (visited[removedCell.x][removedCell.y]) {
                continue;
            }
            
            // Mark the new cell visited
            visited[removedCell.x][removedCell.y] = true;
            // Update the distance
            distance.get(removedCell.x).set(removedCell.y, removedCell.dist);
            
            for (Node neighbour : validNeighboursOf(removedCell.x, removedCell.y, n, m, grid)) {
                neighbour.dist = removedCell.dist + 1;
                queue.add(neighbour);
            }
        }
        
        return distance;
    }
    
    // An entry in queue used in BFS
    static class Node {
        Node(int x, int y, int dist) {
            this.x = x;
            this.y = y;
            this.dist = dist;
        }
        
        int x, y;// Row and Column number
        int dist;// Distance of this vertex from source
    }
    
    static ArrayList<Node> validNeighboursOf(int x, int y, int n, int m, List<String> grid) {
        ArrayList<Node> listOfValidNeighbours = new ArrayList<>();
        
        // To the left
        if (isOnBoard(x - 1, y, n, m, grid)) {
            Node node = new Node(x - 1, y, 0);
            listOfValidNeighbours.add(node);
        }
        
        // To the right
        if (isOnBoard(x + 1, y, n, m, grid)) {
            Node node = new Node(x + 1, y, 0);
            listOfValidNeighbours.add(node);
        }
        
        // To the top
        if (isOnBoard(x, y - 1, n, m, grid)) {
            Node node = new Node(x, y - 1, 0);
            listOfValidNeighbours.add(node);
        }
        
        // To the bottom
        if (isOnBoard(x, y + 1, n, m, grid)) {
            Node node = new Node(x, y + 1, 0);
            listOfValidNeighbours.add(node);
        }
        
        return listOfValidNeighbours;
    }
    
    static boolean isOnBoard(int x, int y, int n, int m, List<String> grid) {
        // Cases for the cell not being on the board
        if (x < 0 || y < 0 || x >= n || y >= m || grid.get(x).charAt(y) != OPEN) {
            return false;
        } else {
            return true;
        }
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
