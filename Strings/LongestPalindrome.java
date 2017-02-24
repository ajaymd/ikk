public class LongestPalindrome {
    public static class Pair {
        public Pair(int b, int e) {
            this.b = b;
            this.e = e;
        }

        public int b, e;

        public String toString() {
            return "<" + b + "," + e + ">";
        }
    }

    public static boolean isPalindrome(String s, int b, int e) {
        return e <= b || s.charAt(b) == s.charAt(e) && isPalindrome(s, b + 1, e - 1);
    }

    // O(n^3) traversing the sub-strings in descending lengths order.
    public static Pair findLongestPalindromeSlow(String s) {
        if (s.length() == 0)
            return null;

        for (int l = s.length(); l >= 1; --l) {
            for (int b = 0; b + l - 1 < s.length(); ++b) {
                int e = b + l - 1;
                if (isPalindrome(s, b, e))
                    return new Pair(b, e);
            }
        }

        return null; // Unreachable code !!!
    }

    // O(n^2)
    public static Pair findLongestPalindromeFaster(String s) {
        if (s.length() == 0)
            return null;

        Pair max = new Pair(0, 0);

        for (int c = 0; c < s.length() - 1; ++c) {
            int b = c - 1;
            int e = c + 1;
            while (b >= 0 && e < s.length() && s.charAt(b) == s.charAt(e)) {
                --b;
                ++e;
            }
            ++b;
            --e;
            if (e - b + 1 > max.e - max.b + 1)
                max = new Pair(b, e);

            b = c;
            e = c + 1;
            while (b >= 0 && e < s.length() && s.charAt(b) == s.charAt(e)) {
                --b;
                ++e;
            }
            ++b;
            --e;
            if (e - b + 1 > max.e - max.b + 1)
                max = new Pair(b, e);
        }

        return max;
    }

    // O(n)
    public static Pair findLongestPalindromeManacher(String s) {
        if (s.length() == 0)
            return null;

        if (s.length() == 1)
            return new Pair(0, 0);

        int[] w = new int[2 * s.length() - 1]; // Maintain the wing lengths
        if (s.charAt(0) == s.charAt(1))
            w[1] = 1;
        int max = w[1] == 1 ? 1 : 0;           // Index of the center of maximum palindrome
        int leader = 1;                        // Index of the center of the leader

        int e = 2;
        for (int c = 2; c < w.length; ++c) {
            int buddy = leader - (c - leader);
            if (getLeftTip(buddy, w[buddy]) > getLeftTip(leader, w[leader])) {
                w[c] = Math.min(w[buddy], (s.length() - 1) - c / 2);
                continue;   // We spend only O(1) on this center. Thank you Manacher.
            }

            int b = getLeftTip(c, e - c / 2);
            while (b >= 0 && e < s.length() && s.charAt(b) == s.charAt(e)) {
                --b;
                ++e;
            }

            int l = (e - 1) - (b + 1) + 1;
            if (l > getRightTip(max, w[max]) - getLeftTip(max, w[max]) + 1)
                max = c;
            w[c] = l / 2;
            leader = c;
        }

        return new Pair(getLeftTip(max, w[max]), getRightTip(max, w[max]));
    }

    // The two functions below return incorrect answers for (indexOfCenter % 2 == 1 && wing == 0)
    // but the function above still works correctly with those answers.

    private static int getLeftTip(int indexOfCenter, int wing) {
        int t = indexOfCenter / 2 - wing;
        return  indexOfCenter % 2 == 1 ? t + 1 : t;
    }

    private static int getRightTip(int indexOfCenter, int wing) {
        return indexOfCenter / 2 + wing;
    }

    public static void main(String[] args) {
        String s = "a";
        System.out.println(findLongestPalindromeSlow(s) + " " + findLongestPalindromeFaster(s) + " " + findLongestPalindromeManacher(s));

        s = "abcde";
        System.out.println(findLongestPalindromeSlow(s) + " " + findLongestPalindromeFaster(s) + " " + findLongestPalindromeManacher(s));

        s = "abcdefedcba";
        System.out.println(findLongestPalindromeSlow(s) + " " + findLongestPalindromeFaster(s) + " " + findLongestPalindromeManacher(s));

        s = "aaaaabcdefedcba";
        System.out.println(findLongestPalindromeSlow(s) + " " + findLongestPalindromeFaster(s) + " " + findLongestPalindromeManacher(s));

        s = "abcdefedcbaaaaa";
        System.out.println(findLongestPalindromeSlow(s) + " " + findLongestPalindromeFaster(s) + " " + findLongestPalindromeManacher(s));

        s = "abcdeffedcba";
        System.out.println(findLongestPalindromeSlow(s) + " " + findLongestPalindromeFaster(s) + " " + findLongestPalindromeManacher(s));

        s = "abcabcdccdccdccdcbabbaabbabcdccdccdccdccghg";
        System.out.println(findLongestPalindromeSlow(s) + " " + findLongestPalindromeFaster(s) + " " + findLongestPalindromeManacher(s));
    }
}
