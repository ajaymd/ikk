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
            int b, e;
            for (b = c - 1, e = c + 1; b >= 0 && e < s.length() && s.charAt(b) == s.charAt(e); --b, ++e)
                ;
            if ((e - 1) - (b + 1) + 1 > max.e - max.b + 1)
                max = new Pair(b + 1, e - 1);

            for (b = c, e = c + 1; b >= 0 && e < s.length() && s.charAt(b) == s.charAt(e); --b, ++e)
                ;
            if ((e - 1) - (b + 1) + 1 > max.e - max.b + 1)
                max = new Pair(b + 1, e - 1);
        }

        return max;
    }

    // O(n)
    public static Pair findLongestPalindromeMancher(String s) {
        if (s.length() == 0)
            return null;

        int[] p = new int[2 * s.length() - 1]; // Maintain the wing length
        p[0] = 0;
        int leader = 0;
        int max = 0;                           // Center of maximum palindrome

        for (int c = 1; c < 2 * s.length() - 1; ++c) {
            int b, e;
            int w = 0;

            int buddy = leader - (c - leader);
            if (buddy >= 0) {
                int buddyLeftTip = buddy / 2 - p[buddy] + (buddy % 2 == 0 ? 0 : 1);
                int leaderLeftTip = leader / 2 - p[leader] + (leader % 2 == 0 ? 0 : 1);
                if (buddyLeftTip > leaderLeftTip) { // We spend only O(1) on this center. Thank you Mancher.
                    if (c / 2 + p[buddy] > s.length())
                        p[c] = s.length() - c / 2;      // The palindrome is chopped by the end of the string.
                    else                                // We continue the algorithm because sometime we want the lengths
                        p[c] = p[buddy];                // of the palindromes arounf all centers.
                    continue;
                } else {
                    w = buddy / 2 - leaderLeftTip + (buddy % 2 == 0 ? 0 : 1);
                }
            }

            b = c / 2 - w - (c % 2 == 0 ? 1 : 0);   // If w > 0 we still gain from Mancher.
            e = c / 2 + w + 1;
            while (b >= 0 && e < s.length() && s.charAt(b) == s.charAt(e)) {
                --b;
                ++e;
            }

            int l = (e - 1) - (b + 1) + 1;
            if (l > 2 * p[max] + (max % 2 == 0 ? 1: 0))
                max = c;
            p[c] = l / 2;
            leader = c;
        }

        return new Pair(max / 2 - p[max] + (max % 2 == 0 ? 0 : 1), max / 2 + p[max]);
    }

    public static void main(String[] args) {
        String s = "a";
        System.out.println(findLongestPalindromeSlow(s) + " " + findLongestPalindromeFaster(s) + " " + findLongestPalindromeMancher(s));

        s = "abcde";
        System.out.println(findLongestPalindromeSlow(s) + " " + findLongestPalindromeFaster(s) + " " + findLongestPalindromeMancher(s));

        s = "abcdefedcba";
        System.out.println(findLongestPalindromeSlow(s) + " " + findLongestPalindromeFaster(s) + " " + findLongestPalindromeMancher(s));

        s = "aaaaabcdefedcba";
        System.out.println(findLongestPalindromeSlow(s) + " " + findLongestPalindromeFaster(s) + " " + findLongestPalindromeMancher(s));

        s = "abcdefedcbaaaaa";
        System.out.println(findLongestPalindromeSlow(s) + " " + findLongestPalindromeFaster(s) + " " + findLongestPalindromeMancher(s));

        s = "abcdeffedcba";
        System.out.println(findLongestPalindromeSlow(s) + " " + findLongestPalindromeFaster(s) + " " + findLongestPalindromeMancher(s));

        s = "abcabcdccdccdccdcbabbaabbabcdccdccdccdccghg";
        System.out.println(findLongestPalindromeSlow(s) + " " + findLongestPalindromeFaster(s) + " " + findLongestPalindromeMancher(s));
    }
}
