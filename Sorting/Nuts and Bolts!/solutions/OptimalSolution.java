import java.util.TreeSet;

public class OptimalSolution {
    /*
     * Space Complexity: O(1)
     * Time Complexity: O(N*(Log(N)))
     */
    private static String[] solve(int nuts[], int bolts[]) {
        matchPairs(nuts, bolts, 0, nuts.length - 1);
        String str[] = new String[nuts.length];
        for (int i = 0; i < nuts.length; i++) {
            str[i] = nuts[i] + " " + bolts[i];
        }
        return str;
    }
    
    // Method which works just like quick sort
    private static void matchPairs(int nuts[], int bolts[], int low, int high) {
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
    private static int partition(int arr[], int low, int high, int pivot) {
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
}
