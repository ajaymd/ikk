import java.util.TreeSet;

public class OptimalSolution {
    /*
     * Space Complexity: O(n*length(steps))
     * Time Complexity: O(n*(length(steps))
     */
    private static long countWaysToClimb(int[] steps, int n) {
        /*
         * We will store counts till every step.
         */
        long countTillHere[] = new long[n + 1];
        // There is one way to reach till zero, as we start from 0
        countTillHere[0] = 1;
        for (int i = 1; i <= n; i++) {
            // Find the ways that you can reach here from current step
            for (int step : steps) {
                int previousStep = i - step;
                if (previousStep >= 0) {
                    countTillHere[i] += countTillHere[previousStep];
                }
            }
        }
        
        // Ways to reach the nth step
        return countTillHere[n];
    }
}
