"""
Question:
---------
Given a sorted dictionary of an alien language, find order of characters.

Example-1:
Input: words[] = {"baa", "abcd", "abca", "cab", "cad"}
Output: Order of characters is 'b', 'd', 'a', 'c'

Note that words are sorted and in the given language. "baa"
comes before "abcd", therefore 'b' is before 'a' in output.

Example-2:
Input: words[] = {"caa", "aaa", "aab"}
Output: Order of characters is 'c', 'a', 'b'

Solution:
---------
Few directions that you may head in

- Collect all unique characters. Generate all permutations of those characters.
  Validate each permutation against the given dictionary.
  [How would you validate a certain ordering of characters against the
  dictionary?]

- If you're familiar with topological sort and what it means, however,
  you'll see that this is a simple application of topological sort.

  Quick recap - Topological sort is ordering the vertices in a directed graph
    such that vertex A appears before vertex B for all directed edges A->B.
    One way to look at it is that you're given a graph of dependencies and you
    want to order the vertices such that no dependecies are broken when going
    from left to right.

  So, what is the graph in this question anyway?
  Since we are given the words sorted lexicographically, we know which
  character precedes what other characters.
  From example 1, we know that 'b' has to appear before 'a' and 'a' before 'c'
  and so on.

  How do we determine these relationships between characters in practice?
  We know a few things about the dictionary ordering.
  In a dictionary, between two adjacent words, one of the following is true
  1. there is at least one character different. Eg. "abcd" and "abde" in English
  2. the left word is shorter. Eg. "abc" and "abcd" in English

  In case 1, we know from the dictionary's property that the character at
  mismatch index in the left word appears before its counter part in right word in the
  alphabet.
  In case 2, there is no meaningful information with respect to the alphabet

  It is also necessarily true between two adjacent words, that the characters after the
  first mismatch do not convey any relationship between the characters
"""
from util.stack import Stack


class CyclicAlphabetException(BaseException):
    pass


def _topological_sort(graph, vertex, visited, stack, path_set):
    """
    Graph in our solution is represented by the adjacency set
    Vertex is each character in the alphabet
    Visited is a set of all characters that have already been processed
    Stack is used to maintain the ordering
    Path_set is used to keep track of all vertices we saw in the current path
        If we encounter a vertex already in the path, we have a cycle
        and a cycle doesn't make sense in an alphabet

    [Remember? A vertex tells all of its dependents to sort themselves and places itself on top
    of the result since it has to come before any of the dependents and
    their dependents and so on.]
    """
    if vertex in path_set:
        raise CyclicAlphabetException()

    if vertex in visited:
        # We have already seen this vertex from somewhere else
        # we can skip
        return

    # Add the current vertex to the path
    path_set.add(vertex)
    for neighbor in graph.get(vertex, []):
        # Recursively let neighbors sort themselves
        _topological_sort(graph, neighbor, visited, stack, path_set)

    path_set.remove(vertex)
    visited.add(vertex)

    # Current vertex should be processed before any of its dependents
    stack.push(vertex)


def get_alphabet(dictionary):
    """
    Given a dictionary sorted list, returns a possible ordering of the alphabet.
    There is no guarantee that there's only one valid ordering. It is dependent
    on whether or not the input dictionary contains enough relationships.
    """
    adjacency_set = {}  # Maps character to a set of all characters to the right in the alphabet
    for dictionary_index in xrange(1, len(dictionary)):
        left = dictionary[dictionary_index-1]
        right = dictionary[dictionary_index]

        # In a dictionary, between two adjacent words, one of the following is true
        # 1. there is at least one character different. Eg. "abcd" and "abde" in English
        # 2. the left word is shorter. Eg. "abc" and "abcd" in English
        #
        # In case 1, we know from the dictionary's property that the character at
        # mismatch index in the left word appears before its counter part in right word in the
        # alphabet.
        # In case 2, there is no meaningful information with respect to the alphabet
        #
        # It is also necessarily true between two adjacent words, that the characters after the
        # first mismatch do not convey any relationship between the characters

        for word_index in xrange(len(left)):
            if left[word_index] != right[word_index]:
                # We found the first mismatch
                # the right character has to appear after the left character
                if left[word_index] not in adjacency_set:
                    adjacency_set[left[word_index]] = set()
                adjacency_set[left[word_index]].add(right[word_index])

                # We break now because subsequent characters do not tell us anything meaningful
                break

    # We now have our adjacency set built
    # Time to do some topological sorting
    stack = Stack()
    visited = set()
    for char in adjacency_set.iterkeys():
        if char in visited:
            continue
        _topological_sort(adjacency_set, char, visited, stack, set())

    alphabet = []
    while not stack.empty():
        alphabet.append(stack.pop())

    return alphabet


def main():
    # Assuming that the input is space separated dictionary words
    words = raw_input().split()
    print get_alphabet(words)

if __name__ == '__main__':
    main()