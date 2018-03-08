import java.util.TreeSet;

public class BruteForceSolution {
    /*
     * Space Complexity: O(1)
     * Time Complexity: O(N^2))
     */
    private static String[] solve(int nuts[], int bolts[]) {
        int n = nuts.length;
        String ans[] = new String[n];
        int pointer = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (nuts[i] == bolts[j]) {
                    ans[pointer] = nuts[i] + " " + bolts[j];
                    pointer++;
                }
            }
        }
        return ans;
    }
}
