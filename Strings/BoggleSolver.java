import java.io.File;
import java.io.FileNotFoundException;
import java.util.*;

public class BoggleSolver {
    private static TrieNode trie;
    private static List<String> wordList;

    private static class TrieNode {
        TrieNode[] children = new TrieNode[26];     // We assume only small English letters
        int wordIndex = -1; // Only used when it is the end of a word.
    }

    private static int readFile() throws FileNotFoundException {
        wordList = new ArrayList<>();
        Scanner sc = new Scanner(new File("data/words.txt"));
        int i;
        for (i = 0; sc.hasNextLine();) {
            String word = sc.nextLine();
            int c;
            for (c = 0; c < word.length(); ++c)
                if (word.charAt(c) < 'a' || word.charAt(c) > 'z')
                    break;     // Our trie doesn't support characters outside [a-z]
            if (c >= word.length()) {
                wordList.add(word);
                ++i;
            }
        }
        return i;
    }

    private static void buildTrie() {
        trie = new TrieNode();
        int i = 0;
        for (String word : wordList) {
            TrieNode node = trie;
            for (int c = 0; c < word.length(); ++c) {
                TrieNode child = node.children[word.charAt(c) - 'a'];
                if (child != null)
                    node = child;
                else
                    node = node.children[word.charAt(c) - 'a'] = new TrieNode();
            }
            node.wordIndex = i++;
        }
    }

    private void solve(char[][] board) {
        boolean[][] used = new boolean[board.length][board[0].length];
        for (int r = 0; r < board.length; ++r)
            for (int c = 0; c < board[0].length; ++c)
                solve(board, used, r, c, trie, 0);

        System.out.println();
    }

    private static int[] dr = {-1, -1, -1, 0, 0, 1, 1, 1};
    private static int[] dc = {-1, 0, 1, -1, 1, -1, 0, 1};

    private void solve(char[][] board, boolean[][] used, int r, int c, TrieNode node, int length) {
        node = node.children[board[r][c] - 'a'];
        if (node == null)
            return;       // If the node that exist in the trie, prune.
        length++;

        used[r][c] = true;

        if (node.wordIndex >= 0 && length > 2)
            System.out.print(wordList.get(node.wordIndex) + ", ");

        for (int i = 0; i < 8; ++i) {
            r += dr[i];
            c += dc[i];
            if (r >= 0 && r < board.length && c >= 0 && c < board[0].length && !used[r][c])
                solve(board, used, r, c, node, length);
            r -= dr[i];
            c -= dc[i];
        }

        used[r][c] = false;
    }

    public static void main(String[] args) throws FileNotFoundException {
        long start = System.currentTimeMillis();
        int w = readFile();
        long end = System.currentTimeMillis();
        System.out.println("Read " + w + " words from file in " + (end - start) + "ms");

        start = end;
        buildTrie();
        end = System.currentTimeMillis();
        System.out.println("Build trie in " + (end - start) + "ms");

        BoggleSolver obj = new BoggleSolver();
        start = end;
        obj.solve(new char[][]{
                {'d', 'g', 'h', 'i'},
                {'k', 'l', 'p', 's'},
                {'y', 'e', 'u', 't'},
                {'e', 'o', 'r', 'n'}});
        end = System.currentTimeMillis();
        System.out.println((end - start) + "ms");

        start = end;
        obj.solve(new char[][]{
                {'d', 'g', 'h', 'i', 'b', 'n'},
                {'k', 'l', 'p', 'd', 'k', 's'},
                {'y', 'e', 'u', 't', 'o', 'p'},
                {'e', 'o', 't', 'r', 'w', 'n'},
                {'a', 'c', 'd', 'e', 'q', 't'},
                {'s', 'o', 'p', 'e', 'd', 'p'}
        });
        end = System.currentTimeMillis();
        System.out.println((end - start) + "ms");
    }
}
