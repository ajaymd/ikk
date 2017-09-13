import java.util.HashSet;
import java.util.Set;

public class PalindromePairs {
    public static class Pair {
        public Pair(int i, int j) {
            this.i = i;
            this.j = j;
        }

        public int i, j;
    }

    private static boolean isPalindrome(String s, int b, int e) {
        return e <= b || s.charAt(b) == s.charAt(e) && isPalindrome(s, b + 1, e - 1);
    }

    // O(n^2k) where k is a limit on the length of the words
    public static Set<Pair> findPalindromePairsSlow(String... words) {
        Set<Pair> result = new HashSet<>();

        for (int i = 0; i < words.length; ++i) {
            for (int j = 0; j < words.length; ++j) {
                if (i != j && isPalindrome(words[i] + words[j], 0, words[i].length() + words[j].length() - 1))
                    result.add(new Pair(i, j));
            }
        }

        return result;
    }


    private static class TrieNode {
        TrieNode[] children = new TrieNode[26];     // We assume only small English letters
        int wordIndex = -1; // Only used when it is the end (beginning) of a word.
    }

    // We calculate the length of all palindromes in input string. We start by adding # signs between all letters,
    // at the beginning of the string, and at the end of teh string. We do that so all palindromes will be of odd size.
    // So result[2x] is the length of the palindrome centered at gap between indices x - 1 and x in s
    // for 0 <= x <= s.length(). Therefore always result[0] == result[2 * s.length()] == 0.
    // result[2x + 1] is the length of the palindrome centered at index x in s for 0 <= x <= s.length() - 1
    private static int[] findAllPalindromes(String s) {
        if (s.length() == 0)
            return null;

        if (s.length() == 1)
            return new int[]{0, 1, 0};

        int[] w = new int[2 * s.length() + 1]; // Maintain the wing lengths
        w[1] = 1;
        int max = 1;                           // Index of the center of maximum palindrome
        int leader = 1;                        // Index of the center of the leader

        int e = 3;
        for (int c = 2; c < w.length; ++c) {
            int buddy = leader - (c - leader);
            if (buddy - w[buddy] > leader - w[leader]) {
                w[c] = Math.min(w[buddy], (w.length - 1) - c);
                continue;   // We spend only O(1) on this center. Thank you Manacher.
            }

            int b = c - (e - c);
            while (b >= 0 && e < w.length) {
                if (e % 2 == 0 ^ b % 2 == 0 || e % 2 != 0 && b % 2 != 0 && s.charAt(b / 2) != s.charAt(e / 2))
                    break;
                --b;
                ++e;
            }

            w[c] = e - c - 1;
            if (w[c] > w[max])
                max = c;
            leader = c;
        }

        return w;
    }

    // O(nk) where k is a limit on the length of the words
    public static Set<Pair> findPalindromePairsFast(String... words) {
        Set<Pair> result = new HashSet<>();

        // Build trie of words in O(nk).
        TrieNode rootOfWordsTrie = new TrieNode();
        for (int i = 0; i < words.length; ++i) {
            TrieNode node = rootOfWordsTrie;
            for (int j = 0; j < words[i].length(); ++j) {
                char c = words[i].charAt(j);
                TrieNode child = node.children[c - 'a'];
                if (child != null)
                    node = child;
                else
                    node = node.children[c - 'a'] = new TrieNode();
            }
            node.wordIndex = i;
        }

        // Build trie of inverse of words in O(nk).
        TrieNode rootOfInversedWordsTrie = new TrieNode();
        for (int i = 0; i < words.length; ++i) {
            TrieNode node = rootOfInversedWordsTrie;
            for (int j = words[i].length() - 1; j >= 0; --j) {
                char c = words[i].charAt(j);
                TrieNode child = node.children[c - 'a'];
                if (child != null)
                    node = child;
                else
                    node = node.children[c - 'a'] = new TrieNode();
            }
            node.wordIndex = i;
        }

        for (int i = 0; i < words.length; ++i) {        // A loop of n iterations
            String word = words[i];
            int[] palindromes = findAllPalindromes(word); // We use "Manacher" so O(k)

            TrieNode node = rootOfWordsTrie;
            for (int k = word.length() - 1; k >= 0; --k) {   // A loop of k iterations. From the end to the beginning
                char c = word.charAt(k);
                if (node.children[c - 'a'] == null)
                    break;

                node = node.children[c - 'a'];

                assert palindromes != null;
                boolean isPalindromeLongEnough = palindromes[k] / 2 >= k / 2;

                if (node.wordIndex >= 0 && isPalindromeLongEnough && node.wordIndex != i
                        && words[i].length() > words[node.wordIndex].length()) // Equal length words will be added by the second part
                    result.add(new Pair(node.wordIndex, i));      // words[i] == P + inverse(W), words[j] == W. P might be empty.
            }

            node = rootOfInversedWordsTrie;
            for (int k = 0; k < word.length(); ++k) {   // A loop of k iterations. From the beginning to the end.
                char c = word.charAt(k);
                if (node.children[c - 'a'] == null)
                    break;

                node = node.children[c - 'a'];

                int matchedCharacters = k + 1;
                int leftOverCharacters = word.length() - matchedCharacters;
                assert palindromes != null;
                boolean isPalindromeLongEnough = palindromes[matchedCharacters + word.length()] / 2 >= leftOverCharacters / 2;

                if (node.wordIndex >= 0 && isPalindromeLongEnough && node.wordIndex != i)
                    result.add(new Pair(i, node.wordIndex));      // words[i] == W + P, words[j] == inverse(W). P can't be empty.
            }
        }

        return result;
    }

    public static void main(String[] args) {
        runTestCase("bat", "tab", "cat"); // [[0, 1], [1, 0]]
        runTestCase("abcd", "dcba", "lls", "s", "sssll"); // [[0, 1], [1, 0], [3, 2], [2, 4]]
        runTestCase("abcdc", "ba"); // [[0, 1], [0, 2]]
        runTestCase("abcdccdc", "ba", "cdcba"); // [[0, 1], [0, 2]]
        runTestCase("abbaqwe", "ewq", "abaert", "tre", "abcdedcbafg", "gf"); // [1, 0] [5, 4] [3, 2]
    }

    private static void runTestCase(String... words) {
        for (String s : words) {
            System.out.print(" " + s);
        }
        System.out.println();
        Set<Pair> result = findPalindromePairsSlow(words);
        for (Pair p : result)
            System.out.print("[" + p.i + ", " + p.j + "] ");
        System.out.println();
        result = findPalindromePairsFast(words);
        for (Pair p : result)
            System.out.print("[" + p.i + ", " + p.j + "] ");
        System.out.println();
    }
}
