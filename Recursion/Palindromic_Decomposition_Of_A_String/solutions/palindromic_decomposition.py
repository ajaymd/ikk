def generate_palindromic_decompositions(string):
    if not string or len(string) == 1:
        return [string]

    output = []
    n = len(string)

    def _palindromic_decomposition(so_far, start):
        # base case
        if start == n:
            output.append('|'.join(so_far))
            return

        # take every possible string from the current position and if it's palndromic go forward, and if it's not prune
        for i in range(start+1, n+1):
            curr = string[start:i]
            if is_palindrome(curr):
                so_far.append(curr)
                _palindromic_decomposition(so_far, i)
                # at the end of dfs remove what was appended to
                so_far.pop()

    _palindromic_decomposition([], 0)
    return output


def is_palindrome(string):
    if not string or len(string) == 1:
        return True

    low, high = 0, len(string) - 1
    while low < high:
        if string[low] != string[high]:
            return False
        low += 1
        high -= 1

    return True


def is_palindrome_rec(string):
    if len(string) == 0:
        return True
    return _is_palindrome(string, 0, len(string)-1)


def _is_palindrome(string, start, end):
    # empty string or string of 1 character
    if start == end or start > end:
        return True

    return string[start] == string[end] and _is_palindrome(string, start+1, end-1)


print generate_palindromic_decompositions('abcba')
# print generate_palindromic_decompositions('abaccdaba')
# print generate_palindromic_decompositions('abracadabra')
# print generate_palindromic_decompositions('abba')
