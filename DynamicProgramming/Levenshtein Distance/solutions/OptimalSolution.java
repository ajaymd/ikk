import java.util.TreeSet;

public class OptimalSolution {
    /*
     * Space Complexity: O(length(strWord1)*length(strWord2)) 
     * Time Complexity: O(length(strWord1)*length(strWord2))
     */
    static int levenshteinDistance(String strWord1, String strWord2) {
        char a[] = strWord1.toCharArray();
        char b[] = strWord2.toCharArray();
        int n = a.length;
        int m = b.length;

        // Fill all values in table with a maximum value
        int dp[][] = new int[n + 1][m + 1];
        for (int i = 0; i <= n; i++) {
            Arrays.fill(dp[i], n + m);
        }
        dp[0][0] = 0;
        for (int i = 1; i <= n; i++) {
            // If second string is empty, only option is to
            // remove all characters of second string
            dp[i][0] = i;
        }
        for (int i = 1; i <= m; i++) {
            // If first string is empty, only option is to
            // isnert all characters of second string
            dp[0][i] = i;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (a[i - 1] == b[j - 1]) {
                    // If last characters are same, ignore last char
                    // and recur for remaining string
                    dp[i][j] = Math.min(dp[i][j], dp[i - 1][j - 1]);
                } else {
                    // If the last character is different, consider all
                    // possibilities and find the minimum
                    dp[i][j] = Math.min(dp[i][j],
                            1 + Math.min(dp[i - 1][j - 1], // Replace
                                Math.min(dp[i - 1][j], // Remove
                                         dp[i][j - 1] // Insert
                                    )));
                }
            }
        }
        return dp[n][m];
    }
}
