/******************************************************************************
 * Find best path in an MxN matrix
 *****************************************************************************/

public class BestPathDP {
    public static int solve(int array[][]) {
        int m = array.length;
        int n = array[0].length;

        int bp[][] = new int[m][n];

        bp[m - 1][n - 1] = array[m - 1][n - 1];

        for (int j = n - 2; j >= 0; --j)
            bp[m - 1][j] = array[m - 1][j] + bp[m - 1][j + 1];

        for (int i = m - 2; i >= 0; --i) {
            bp[i][n - 1] = array[i][n - 1] + bp[i + 1][n - 1];
            for (int j = n - 2; j >= 0; --j) {
                int right = array[i][j] + bp[i][j + 1];
                int down = array[i][j] + bp[i + 1][j];
                bp[i][j] = Math.max(down, right);
            }
        }

        System.out.print("Solution: ");
        int i = 0;
        int j = 0;
        while (i != m - 1 || j != n - 1) {
            int right = j != n - 1 ? array[i][j] + bp[i][j + 1] : Integer.MIN_VALUE;
            int down = i != m - 1 ? array[i][j] + bp[i + 1][j] : Integer.MIN_VALUE;
            if (right > down) {
                System.out.print("R");
                j += 1;
            } else {
                System.out.print("D");
                i += 1;
            }
        }
        System.out.println(" " + bp[0][0]);

        return bp[0][0];
    }

    private static class TestCase {
        public TestCase(int r, int a[][]) {
            result = r;
            array = a;
        }

        public int result, array[][];
    }

    private static int arr1[][] = {{9}};
    private static int arr2[][] = {{1, 2, 3}};
    private static int arr3[][] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    private static int arr4[][] = {{2, 2, 1, 1, 1},
            {1, 2, 1, 1, 1},
            {1, 2, 2, 1, 1},
            {1, 1, 2, 2, 1},
            {1, 1, 1, 2, 2}};

    private static TestCase tests[] = {
            new TestCase(9, arr1),
            new TestCase(6, arr2),
            new TestCase(29, arr3),
            new TestCase(18, arr4)
    };

    public static void main(String[] args) {
        int errors = 0;
        for (int i = 0; i < tests.length; ++i) {
            int result = solve(tests[i].array);
            if (result != tests[i].result) {
                System.out.println("Error: Best path of test case number " + (i + 1) + " is " + (tests[i].result) +
                        ". Got " +  result + " instead\n");
                errors++;
            }
        }

        if (errors > 0)
            System.out.println("Got " + errors + " errors");
        else
            System.out.println("Good work");
    }
}
