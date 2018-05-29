import java.util.TreeSet;

public class OptimalSolution {
    /*
     * Space Complexity: O(1)
     * Time Complexity: O(2^(length(values))
     */
    public static int maxStolenValue(int[] values) {
        return maxStolenTill(values.length - 1, values);
    }
    
    private static int maxStolenTill(int index, int[] values) {
        if (index < 0) {
            return 0;
        }
        if (index == 0) {
            return values[0];
        }
        if (index == 1) {
            return Math.max(values[0], values[1]);
        }
        return Math.max(maxStolenTill(index - 1, values),
                                      maxStolenTill(index - 2, values) + values[index]);
    }
}
