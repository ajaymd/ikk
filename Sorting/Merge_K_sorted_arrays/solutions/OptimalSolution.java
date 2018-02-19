import java.util.PriorityQueue;

public class OptimalSolution {
    /*
     * Time Complexity: O(NK*Log(K))
     * Space Complexity: O(K + NK)
     */
    static int[] mergeArrays(int[][] arr) {
        int K = arr.length;
        int N = arr[0].length;
        // Get appropriate priority queue
        PriorityQueue<Node> priorityQueue = getPriorityQueue(arr);
        for (int i = 0; i < K; i++) {
            priorityQueue.add(new Node(arr[i][0], i, 0));
        }
        int ans[] = new int[N * K];
        int pointer = 0;
        while (pointer < N * K) {
            Node rem = priorityQueue.poll();
            ans[pointer++] = rem.value;
            // Add the next element from the same row from which element is
            // removed, if available
            if (rem.column + 1 < N) {
                priorityQueue.add(new Node(arr[rem.row][rem.column + 1], rem.row, 
                    rem.column + 1));
            }
        }
        return ans;
    }
    
    static private PriorityQueue<Node> getPriorityQueue(int[][] arr) {
        boolean isIncreasing = false, isDecreasing = false;
        // We will check if the input is sorted in increasing manner or
        // decreasing manner
        for (int i = 0; i < arr.length; i++) {
            if (arr[i][0] < arr[i][arr[i].length - 1]) {
                isIncreasing = true;
            }
            if (arr[i][0] > arr[i][arr[i].length - 1]) {
                isDecreasing = true;
            }
        }
        
        if (isIncreasing) {
            // Make a min priority queue
            return new PriorityQueue<>();
        }
        if (isDecreasing) {
            // Make a max priority queue
            return new PriorityQueue<>(arr.length, Collections.reverseOrder());
        }
        // Some error in test case; Code should never reach here;
        return null;
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
}
