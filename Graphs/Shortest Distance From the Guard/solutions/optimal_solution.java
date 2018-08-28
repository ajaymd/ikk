import java.util.TreeSet;

public class OptimalSolution {
    // ==================start==================
    
    /*
     * Space Complexity: O(n*m) 
     * Time Complexity: O(n*m)
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
}
