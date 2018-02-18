import java.util.TreeSet;

public class BruteForce {
    /*
     * Time Complexity: O(N^3)
     * Space Complexity: O(N^3)
     */
    static String[] bruteForce(int[] arr) {
        HashSet<String> set = new HashSet<>();
        // Sorting is not pre-requisite for the solution but for maintaining unique triplets
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
}
