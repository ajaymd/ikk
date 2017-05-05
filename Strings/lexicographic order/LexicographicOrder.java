/**
 *
 * Find the lexicographic order of a string
 *
 */
public class LexicographicOrder {
    private static final int MAX_LENGTH = 21;
    private static final long[] FACTORIAL = new long[MAX_LENGTH];

    static {
        FACTORIAL[1] = 1;
        for (int i = 2; i < MAX_LENGTH; ++i)
            FACTORIAL[i] = i * FACTORIAL[i - 1];
    }

    public static long findLexicographicOrder(String s) {
        if (s == null || s.length() >= MAX_LENGTH)
            return -1;

        long result = 1;
        for (int i = 0; i < s.length(); ++i)
            for (int j = i + 1; j < s.length(); ++j)
                if (s.charAt(j) < s.charAt(i))
                    result += FACTORIAL[s.length() - i - 1];
        return result;
    }

    private static class TestCase {
        public TestCase(String s, long r) {
            string = s;
            result = r;
        }
        String string;
        long result;
    }

    private static TestCase tests[] = {
            new TestCase("string", 598),
            new TestCase("abc", 1),
            new TestCase("cba", 6),
            new TestCase("d", 1)
    };

    public static void main(String[] args) {
        int errors = 0;
        for (int i = 0; i < tests.length; ++i) {
            long result = findLexicographicOrder(tests[i].string);
            if (result != tests[i].result) {
                System.out.println(
                        "Error: result of test case number " + (i + 1) + " is " + tests[i].result + ". Got " + result + " instead");
                errors++;
            }
        }

        if (errors >  0)
            System.out.println("Got " + errors + " errors");
        else
            System.out.println("Good work");
    }
}
