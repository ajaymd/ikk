import java.util.*;

public class ShortestContainingSubArray {
    public static class Pair {
        public Pair() {
            left = 0;
            right = Integer.MAX_VALUE;
        }

        int left, right;
    }

    public static Pair shortestContainingSubArray(char[] array, Set<Character> set) {
        Pair result = new Pair();
        Map<Character, Boolean> map = new HashMap<Character, Boolean>();
        for (Character c : set)
            map.put(c, false);
        int missing = set.size();
        int left = -1;
        for (int right = 0; right < array.length; ++right) {
            char c = array[right];

            if (!set.contains(c))
                continue;

            if (left == -1)
                left = right;

            boolean appears = map.get(c);
            if (!appears)
                missing--;
            map.put(c, true);

            if (missing > 0)
                continue;

            if (right - left < result.right - result.left) {
                result.right = right;
                result.left = left;
            }

            if (left == right) {
                left = -1;
                continue;
            }

            char cc = array[left];
            for (left++; ; left++) {
                c = array[left];

                if (!set.contains(c))
                    continue;

                if (c != cc)
                    break;

                if (right - left < result.right - result.left) {
                    result.right = right;
                    result.left = left;
                }
            }
            map.put(cc, false);
            missing = 1;
        }

        if (result.right == Integer.MAX_VALUE)
            result.left = -1;
        return result;
    }

    public static void main(String[] args) {
        int errors = 0;
        for (int i = 0; i < tests.length; ++i) {
            char[] array = tests[i].array.toCharArray();
            HashSet<Character> set = new HashSet<Character>();
            for (Character c : tests[i].set.toCharArray())
                set.add(c);
            Pair result = shortestContainingSubArray(array, set);
            if (result.left != tests[i].left || result.right != tests[i].right) {
                System.out.println("Error: result of test case number " + i);
                errors++;
            }
        }

        if (errors > 0)
            System.out.println("Got " + errors + " errors");
        else
            System.out.println("Good work");
    }

    private static TestCase tests[] = {
            new TestCase("abc", "abc", 0, 2),
            new TestCase("abcdefabcdef", "c", 2, 2),
            new TestCase("abcdefgh", "j", -1, Integer.MAX_VALUE),
            new TestCase("", "a", -1, Integer.MAX_VALUE),
            new TestCase("abcccccdefg", "dc", 6, 7),
            new TestCase("abcccccdeeeeeefg", "dec", 6, 8)
    };

    private static class TestCase {
        public TestCase(String a, String s, int l, int r) {
            array = a;
            set = s;
            left = l;
            right = r;
        }

        String array, set;
        int left, right;
    }
}