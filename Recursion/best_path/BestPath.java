/******************************************************************************
 *
 *  Find best path in an MxN matrix
 *
 *****************************************************************************/
public class BestPath {
    public static void main(String [] args) {
        int result;
        int errors = 0;
        for(int i = 0; i < tests.length; ++i) {
            result = bestPath(tests[i].array);
            System.out.println(result);
            if (result != tests[i].result) {
                System.out.println(
                        "Error: Best path of test case number " + i + " is " + tests[i].result + ". Got " + result + " instead");
                errors++;
            }
        }

        if (errors > 0)
            System.out.println("Got " + errors + " errors");
        else
            System.out.println("Good work");

    }

    public static int bestPath(int[][] array) {
        return bestPath(array, 0, 0);
    }

    private static int bestPath(int[][] array, int i, int j) {
        int m = array.length;
        int n = array[0].length;
        if (i == m - 1 && j == n - 1)
            return array[i][j];

        if (i == m - 1)
            return array[i][j] + bestPath(array, i, j + 1);

        if (j == n - 1)
            return array[i][j] + bestPath(array, i + 1, j);

        int down = array[i][j] + bestPath(array, i + 1, j);
        int right = array[i][j] + bestPath(array, i, j + 1);
        return Math.max(down, right);
    }

    private static class TestCase {
        public TestCase(int[][] a, int r) {
            array = a;
            result = r;
        }
        int result;
        int[][] array;
    }

    private static int[][] arr1 = {{9}};
    private static int[][] arr2 = {{1, 2, 3}};
    private static int[][] arr3 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    private static int[][] arr4 = {{2, 2, 1, 1, 1}, {1, 2, 1, 1, 1}, {1, 2, 2, 1, 1}, {1, 1, 2, 2, 1}, {1, 1, 1, 2, 2}};
    private static TestCase tests[] = {
            new TestCase(arr1, 9),
            new TestCase(arr2, 6),
            new TestCase(arr3, 29),
            new TestCase(arr4, 18)
    };
}
