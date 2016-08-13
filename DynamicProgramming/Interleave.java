public class Interleave {
    private static boolean recursion(String t, String s1, int i, String s2, int j) {
        if (i == s1.length() && j == s2.length())
            return true;

        if (j == s2.length())
            return t.charAt(i + j) == s1.charAt(i) && recursion(t, s1, i + 1, s2, j);

        if (i == s1.length())
            return t.charAt(i + j) == s2.charAt(j) && recursion(t, s1, i, s2, j + 1);

        return ((t.charAt(i + j) == s1.charAt(i) && recursion(t, s1, i + 1, s2, j)) ||
                (t.charAt(i + j) == s2.charAt(j) && recursion(t, s1, i, s2, j + 1)));
    }

    private static boolean dynamicProgramming(String t, String s1, String s2) {
        if (t.length() != s1.length() + s2.length())
            return false;

        boolean interleave[][] = new boolean[s1.length() + 1][s2.length() + 1];
        interleave[s1.length()][s2.length()] = true;

        int i, j;
        j = s2.length();
        for (i = s1.length() - 1; i >= 0; --i) {
            if (t.charAt(i + j) != s1.charAt(i))
                break;
            interleave[i][j] = true;
        }

        for (; i >= 0; --i)
            interleave[i][s2.length()] = false;

        i = s1.length();
        for (j = s2.length() - 1; j >= 0; --j) {
            if (t.charAt(i + j) != s2.charAt(j))
                break;
            interleave[i][j] = true;
        }

        for (; j >= 0; --j)
            interleave[i][j] = false;

        for (i = s1.length() - 1; i >= 0; --i)
            for (j = s2.length() - 1; j >= 0; --j)
                interleave[i][j] = ((t.charAt(i + j) == s1.charAt(i) && interleave[i + 1][j]) ||
                        (t.charAt(i + j) == s2.charAt(j) && interleave[i][j + 1]));


        return interleave[0][0];
    }

    private static class TestCase {
        public TestCase(String t, String s1, String s2, boolean result) {
            this.t = t;
            this.s1 = s1;
            this.s2 = s2;
            this.result = result;
        }

        String t, s1, s2;
        boolean result;
    }

    private static TestCase tests[] = {
            new TestCase("1234", "123", "123", false),
            new TestCase("112233", "123", "123", true),
            new TestCase("123456", "123456", "", true),
            new TestCase("123456", "", "123456", true),
            new TestCase("12345678", "1234", "5678", true),
            new TestCase("12345678", "1233", "5678", false)
    };

    public static void main(String[] args) {
        int errors = 0;
        for (int i = 0; i < tests.length; ++i) {
            // check that length(t) == length(s1) + length(s2)
            boolean result = recursion(tests[i].t, tests[i].s1, 0, tests[i].s2, 0);
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
            boolean result = dynamicProgramming(tests[i].t, tests[i].s1, tests[i].s2);
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
