/**********************************************************
 * Find Minimal Palindromic Decomposition
 *********************************************************/

public class MinimalPalindromicDecomposition {
    public static int recursion(String s, int index) {
        int length = s.length();
        boolean isPalindrome[][] = calcPalindromes(s);

        if (index == length)
            return 0;

        int min = length;
        for (int j = index; j < length; ++j)
            if (isPalindrome[index][j])
                min = Math.min(min, 1 + recursion(s, j + 1));

        return min;
    }

    public static int dynamicProgramming(String string) {
        int length = string.length();
        boolean isPalindrome[][] = calcPalindromes(string);

        int mPD[] = new int[length + 1]; // Minimum Palindromic Decomposition

        mPD[length] = 0;

        for (int i = length - 1; i >= 0; --i) {
            int min = length;
            for (int j = i; j < length; ++j)
                if (isPalindrome[i][j])
                    min = Math.min(min, 1 + mPD[j + 1]);
            mPD[i] = min;
        }

        return mPD[0];
    }

    private static boolean[][] calcPalindromes(String s) {
        int length = s.length();
        // isPalindrome[i][j] == true iff substring(string, i, j) is a palindrome
        boolean isPalindrome[][] = new boolean[length][length];
        for (int i = length - 1; i >= 0; --i) {
            for (int j = i; j < length; ++j) {
                isPalindrome[i][j] = false;

                if (s.charAt(i) != s.charAt(j))
                    continue;

                if ((j - i <= 1) || isPalindrome[i + 1][j - 1])
                    isPalindrome[i][j] = true;
            }
        }
        return isPalindrome;
    }

    private static class TestCase {
        public TestCase(String s, int r) {
            string = s;
            result = r;
        }

        String string;
        int result;
    }

    private static TestCase tests[] = {
            new TestCase("1234", 4),        // 1|2|3|4
            new TestCase("11234", 4),       // 11|2|3|4
            new TestCase("1211213121", 2)   //121|1213121
    };

    public static void main(String[] args) {
        int errors = 0;
        for (int i = 0; i < tests.length; ++i) {
            int result = dynamicProgramming(tests[i].string);
            if (result != tests[i].result) {
                System.out.println("Error: test case number " + (i + 1) + " returned " + result + ". Expected " +
                        tests[i].result);
                errors++;
            }
        }

        if (errors > 0)
            System.out.println("Got " + errors + " errors");
        else
            System.out.println("Good work");

        errors = 0;
        for (int i = 0; i < tests.length; ++i) {
            int result = recursion(tests[i].string, 0);
            if (result != tests[i].result) {
                System.out.println("Error: test case number " + (i + 1) + " returned " + result + ". Expected " +
                        tests[i].result);
                errors++;
            }
        }

        if (errors > 0)
            System.out.println("Got " + errors + " errors");
        else
            System.out.println("Good work");
    }
}
