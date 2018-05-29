import java.util.TreeSet;

public class OptimalSolution {
    /*
     * Space Complexity: O(length(values))
     * Time Complexity: O((length(values))
     */
    public static int maxStolenValue(int[] values) {
        int memo[] = new int[values.length];
        Arrays.fill(memo, -1);
        return maxStolenTill(values.length - 1, values, memo);
    }
    
    private static int maxStolenTill(int index, int[] values, int[] memo) {
        if (index < 0) {
            return 0;
        }
        if (memo[index] != -1) {
            return memo[index];
        }
        if (index == 0) {
            return memo[index] = values[0];
        }
        if (index == 1) {
            return memo[index] = Math.max(values[0], values[1]);
        }
        return memo[index] = Math.max(maxStolenTill(index - 1, values, memo),
                                      maxStolenTill(index - 2, values, memo) + values[index]);
    }
}
