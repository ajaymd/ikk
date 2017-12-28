public class PalindromicDecomposition {
    boolean isPalindrome(char[] s, int begin, int end) {
        return begin >= end || s[begin] == s[end] && isPalindrome(s, begin + 1, end - 1);
    }

    void palindromicDecompositionRecursion(char[] s, int begin, char[] decomposition, int write) {
        if (begin == s.length) {
            for (int i = 0; i < write; ++i)
                System.out.print(decomposition[i]);
            System.out.println();
            return;
        }

        for(int end = begin; end < s.length; ++end) {
            if (isPalindrome(s, begin, end)) {
                int w = write;
                for(int j = begin; j <= end ; ++j)
                    decomposition[w++] = s[j];
                decomposition[w++] = '|';
                palindromicDecompositionRecursion(s, end + 1, decomposition, w);
            }
        }
    }

    void decompose(String s) {
        char[] decomposition = new char[2 * s.length()];
        palindromicDecompositionRecursion(s.toCharArray(), 0, decomposition, 0);
    }

    public static void main(String[] args) {
        PalindromicDecomposition pD = new PalindromicDecomposition();
        String s = args.length > 0 ? args[0] : "abacddcaba";
        pD.decompose(s);
    }
}
