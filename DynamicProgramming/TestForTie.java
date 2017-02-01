public class TestForTie {
    static boolean testTie(int[] votes) {
        int sum = 0;
        for (int vote : votes)
            sum += vote;
        if (sum % 2 == 1)
            return false;

        return testTie(votes, 0, sum / 2);
    }

    static boolean testTie(int[] votes, int i, int target) {
        if (target < 0)
            return false;
        if (target == 0)
            return true;
        if (i == votes.length)
            return false;
        return testTie(votes, i + 1, target) || testTie(votes, i + 1, target - votes[i]);
    }

    // O(nv) space;
    static boolean testTieDP(int[] votes) {
        int sum = 0;
        for (int vote : votes)
            sum += vote;
        if (sum % 2 == 1)
            return false;
        int target = sum / 2;

        boolean[][] dp = new boolean[votes.length + 1][target + 1];

        for (int i = 0; i <= votes.length; ++i)
            dp[i][0] = true;

        for (int t = 1; t <= target; ++t)
            dp[votes.length][t] = false;

        for (int i = votes.length - 1; i >= 0; i--)
            for (int t = 1; t <= target; t++)
                dp[i][t] = dp[i + 1][t] || t - votes[i] >= 0 && dp[i + 1][t - votes[i]];

        return dp[0][target];
    }

    // O(V) space
    static int testTieFancy(int[] votes) {
        int sum = 0;
        for (int vote : votes)
            sum += vote;
        System.out.println("Sum: " + sum);
        if (sum % 2 == 1)
            return 0;
        sum /= 2;

        int[] scores = new int[sum + 1];
        for(int i = 0; i <= sum; i++)
            scores[i] = -1;

        for(int state = 0; state < votes.length; state++) {
            int v = votes[state];
            for(int j = sum; j > votes[state]; --j) {
                if (scores[j] == -1 && scores[j - votes[state]] != -1)
                    scores[j] = state;
            }
            scores[votes[state]] = state;
            if (scores[sum] != -1)
                break;
        }

        int result = 0;
        if (scores[sum] != -1) {
            result = 1;
            int state;
            for(int i = sum; i != 0; i -= votes[state]) {
                state = scores[i];
                System.out.println(state + " " + votes[state] + " " + i);
            }
        }

        return result;
    }

    static int[] votes = {
            9, 3, 11, 6, 55, 9, 7, 3, 29, 16, 4, 4, 20, 11, 6, 6, 8,
            8, 4, 10, 11, 16, 10, 6, 10, 3, 5, 6, 4, 14, 5, 29, 15, 3,
            18, 7, 7, 20, 4, 9, 3, 11, 38, 6, 3, 13, 12, 5, 10, 3, 3
    };

    public static void main(String[] args) {
        testTieFancy(votes);
    }
}
