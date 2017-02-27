/**********************************************************
 * String Matching
 *********************************************************/

public class RegexMatcher {
    public static boolean stringMatching(String r, String s) {
        if (r == null || s == null)
            return false;
        return stringMatching(r, 0, s, 0);
    }

    private static boolean stringMatching(String r, int i, String s, int j) {
        if (i == r.length())
            return (j == s.length());
        if (i + 1 < r.length() && r.charAt(i + 1) == '*')
            return (stringMatching(r, i + 2, s, j) ||
                    j != s.length() && (r.charAt(i) == s.charAt(j) || r.charAt(i) == '.') && stringMatching(r, i, s, j + 1));
        if (j != s.length() && (r.charAt(i) == s.charAt(j) || r.charAt(i) == '.'))
            return stringMatching(r, i + 1, s, j + 1);

        return false;
    }

    public static void main(String[] args) {
        int errors = 0;
        for (int i = 0; i < tests.length; ++i) {
            boolean result = stringMatching(tests[i].r, tests[i].s);
            if (result != tests[i].result) {
                System.out.println("Error: result of test case number " + i + " is " + tests[i].result + ". Got " + result + " instead");
                errors++;
            }
        }

        if (errors > 0)
            System.out.println("Got " + errors + " errors");
        else
            System.out.println("Good work");
    }

    private static class TestCase {
        public TestCase(String r, String s, boolean result) {
            this.r = r;
            this.s = s;
            this.result = result;
        }

        String r, s;
        boolean result;
    }

    private static TestCase tests[] = {
            new TestCase("yuval", "yuval", true),
            new TestCase("yuval", "yuva", false),
            new TestCase("yuv", "yuval", false),
            new TestCase("", "yuval", false),
            new TestCase("yuval", "", false),
            new TestCase(".....", "yuval", true),
            new TestCase("yuvb*al", "yuval", true),
            new TestCase(".*", "yuval", true),
            new TestCase("a*b*c*yuval.*a*b*c*", "yuval", true),
            new TestCase("a*abc", "aaaabc", true)
    };
}


