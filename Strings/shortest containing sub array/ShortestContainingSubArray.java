import java.util.*;

public class ShortestContainingSubArray {
    public static class Pair {
        public Pair(int l, int r) {
            left = l;
            right = r;
        }

        int left, right;
    }

    // O(N^3)
    public static Pair shortestContainingSubArraySlow(char[] array, Set<Character> set) {
        Pair result = null;
        for (int left = 0; left + set.size() - 1 < array.length; ++left) {
            for (int right = left + set.size() - 1; right < array.length; ++right) {
                Set<Character> s = new HashSet<>(set);
                for (int k = left; k <= right; ++k) {
                    if (!set.contains(array[k]))
                        continue;
                    s.remove(array[k]);
                    if (s.isEmpty()) {
                        if (result == null || right - left < result.right - result.left)
                            result = new Pair(left, right);
                        break;
                    }
                }
            }
        }
        return result;
    }

    // O(N^2)
    public static Pair shortestContainingSubArrayFaster(char[] array, Set<Character> set) {
        Pair result = null;
        for (int left = 0; left + set.size() - 1 < array.length; ++left) {
            Set<Character> s = new HashSet<>(set);
            for (int right = left; right < array.length; ++right) {
                if (!set.contains(array[right]))
                    continue;
                s.remove(array[right]);
                if (s.isEmpty()) {
                    if (result == null || right - left < result.right - result.left)
                        result = new Pair(left, right);
                    break;
                }
            }
        }
        return result;
    }

    // O(n)
    public static Pair shortestContainingSubArray(char[] array, Set<Character> set) {
        int left;
        for (left = 0; left < array.length; ++left) {
            if (set.contains(array[left]))
                break;
        }

        if (left == array.length)
            return null;

        if (set.size() == 1)
            return new Pair(left, left);

        Map<Character, Integer> map = new HashMap<>();
        map.put(array[left], 1);
        int missing = set.size() - 1;
        Pair result = null;

        for (int right = left + 1; right < array.length; ++right) {
            char c = array[right];
            if (!set.contains(c))
                continue;

            int count = map.getOrDefault(c, 0);
            map.put(c, count + 1);

            if (count == 0)
                missing--;

            if (missing > 0)
                continue;

            for (; ; ++left) {
                c = array[left];
                if (!set.contains(c))
                    continue;

                if (result == null || right - left < result.right - result.left)
                    result = new Pair(left, right);

                count = map.get(c);
                map.put(c, --count);

                if (count == 0) {
                    ++left;
                    missing = 1;
                    break;
                }
            }
        }

        return result;
    }

    public static void main(String[] args) {
        int errors = 0;
        for (int i = 0; i < tests.length; ++i) {
            char[] array = tests[i].array.toCharArray();
            HashSet<Character> set = new HashSet<>();
            for (Character c : tests[i].set.toCharArray())
                set.add(c);
            Pair result = shortestContainingSubArray(array, set);
            if (result == null) {
                if (tests[i].left != -1) {
                    System.out.println("Error: result of test case number " + (i + 1));
                    errors++;
                }
            } else if (result.left != tests[i].left || result.right != tests[i].right) {
                System.out.println("Error: result of test case number " + (i + 1));
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
            new TestCase("abcccccfdefdcg", "dc", 11, 12),
            new TestCase("abcccccdeeeeeefg", "dec", 6, 8),
            new TestCase("ababababcddd", "abc", 6, 8),
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