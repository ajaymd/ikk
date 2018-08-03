# https://leetcode.com/problems/word-search-ii/description/

"""
Given a 2D board and a list of words from the dictionary, find all words in the board.

Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

Example:

Input:
words = ["oath","pea","eat","rain"] and board =
[
  ['o','a','a','n'],
  ['e','t','a','e'],
  ['i','h','k','r'],
  ['i','f','l','v']
]

Output: ["eat","oath"]
"""

# ------------------------------------------ START ------------------------------------------

from collections import defaultdict


class TrieNode(object):
    def __init__(self):
        self.is_word_end = False
        self.children = defaultdict(TrieNode)


class Trie(object):
    def __init__(self):
        self.root = TrieNode()

    def add_word(self, word):
        node = self.root
        for c in word:
            node = node.children[c]

        node.is_word_end = True

    def add_words(self, words):
        for word in words:
            self.add_word(word)


# Leetcode version has only 4 neighboring cells, IK has 8 cells
DIRECTIONS = [(0, 1), (0, -1), (-1, 0), (1, 0), (-1, 1), (1, 1), (-1, -1), (1, -1)]


def findWords(words, board):
    trie = Trie()
    trie.add_words(words)
    root = trie.root

    output = []

    def _dfs(node, i, j, path):
        if node.is_word_end:
            output.append(path)
            node.is_word_end = False

        if i < 0 or i >= len(board) or j < 0 or j >= len(board[0]):
            return

        # save current pos to put back
        tmp = board[i][j]
        child = node.children.get(tmp)
        if not child:
            return
        board[i][j] = '#'
        for dr, dc in DIRECTIONS:
            _dfs(child, i + dr, j + dc, path + tmp)
        # set board back at end of dfs
        board[i][j] = tmp

    # start here
    for i in range(len(board)):
        for j in range(len(board[0])):
            _dfs(root, i, j, '')

    return output


# ------------------------------------------ STOP ------------------------------------------

# SAMPLE TEST CASES
b = [
  ['o', 'a', 'a', 'n'],
  ['e', 't', 'a', 'e'],
  ['i', 'h', 'k',' r'],
  ['i', 'f', 'l', 'v']
]
w = ['oath', 'pea', 'eat', 'rain']
print(findWords(w, b))
