# ------------------------------------------ START ------------------------------------------

from collections import defaultdict


def find_order(words):
        all_chars = set()
        for word in words:
            for c in word:
                all_chars.add(c)

        deps = defaultdict(set)  # dependency -> dependants
        # get word and its following word one by one
        for w1, w2 in zip(words, words[1:]):
            # do the same character by character
            for c1, c2 in zip(w1, w2):
                if c1 != c2:
                    deps[c1].add(c2)
                    break

        order = []
        visited = {}

        # use visited (1), visiting(-1) and unvisited (not in dictionary) states to keep track
        # dfs returns False if there is a cycle
        def _dfs(node):
            status = visited.get(node)
            # have visited this node
            if status == 1:
                return True
            # there is a cycle as this node is currently being visited
            if status == -1:
                return False

            # set to visiting
            visited[node] = -1

            for n in deps[node]:
                if not _dfs(n):
                    return False

            # complete visiting and add to order
            visited[node] = 1
            order.append(node)
            return True

        # run through dfs and check for cycles
        for c in all_chars:
            if not _dfs(c):
                return ''

        # since order is used as a stack it will be need to be reversed to get the right order
        return ''.join(reversed(order))

# ------------------------------------------ STOP ------------------------------------------


# MAIN/TEST CASES
w = ["baa", "abcd", "abca", "cab", "cad"]
print(find_order(w))