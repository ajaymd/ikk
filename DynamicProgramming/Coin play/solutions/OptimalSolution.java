import java.util.TreeSet;

public class OptimalSolution {
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
}
