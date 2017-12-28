/**
 *
 * Find a word in a text
 *
 */
public class RabinKarp {
    private static int[] powers;

    private static int calculateRollingHash(String s) {
        int hash = 0;
        for(int i = s.length() - 1; i >= 0; --i)
            hash = (hash + powers[s.length() - 1 - i] * (s.charAt(i) - 'a')) % 31;
        return hash;
    }

    private static int updateRollingHash(int length, int hash, char left, char right) {
        hash -= (left - 'a') * powers[length - 1];
        hash = (hash * 26 + (right - 'a')) % 31;
        return hash >= 0 ? hash : hash + 31;
    }

    public static int findString(String word, String text) {
        if (word.length() > text.length())
            return -1;
        int wordHash = calculateRollingHash(word);
        int rollingHash = calculateRollingHash(text.substring(0, word.length()));
        if (wordHash == rollingHash && word.equals(text.substring(0, word.length())))
            return 0;
        for (int i = 1; i + word.length() <= text.length() ; ++i) {
            rollingHash = updateRollingHash(word.length(), rollingHash, text.charAt(i - 1), text.charAt(i + word.length() - 1));
            if (wordHash == rollingHash && word.equals(text.substring(i, i + word.length())))
                return i;
        }
        return -1;
    }

    private static class TestCase {
        public TestCase(String w, String t, int r) {
            word = w;
            text = t;
            result = r;
        }
        String word, text;
        int result;
    }
    
    private static TestCase tests[] = {
            new TestCase("yuval", "yuval", 0),
            new TestCase("yuv", "yuval", 0),
            new TestCase("u", "yuval", 1),
            new TestCase("l", "yuval", 4),
            new TestCase("uva", "yuval", 1),
            new TestCase("val", "yuval", 2),
            new TestCase("yuvall", "yuval", -1),
            new TestCase("yub", "yuval", -1),
            new TestCase("yu", "zzzaaaaa", -1)
    };

    public static void main(String[] args) {
        powers = new int[50];
        powers[0] = 1;
        for(int i = 1; i < 50; ++i)
            powers[i] = (powers[i - 1] * 26) % 31;

        int result;
        int errors = 0;
        for (int i = 0; i < tests.length; ++i) {
            result = findString(tests[i].word, tests[i].text);
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
