def generate_all_subsets(s):
    output = []
    if len(s) < 1:
        return output

    # recursive function to generate subsets
    def _generate_all_subsets(so_far, rest):
        # base case
        if len(rest) == 0:
            output.append(so_far)
            return

        # recurse after adding current and not adding current to so_far
        _generate_all_subsets(so_far + [rest[0]], rest[1:])
        _generate_all_subsets(so_far, rest[1:])

    _generate_all_subsets([], s)

    # hackerrank was expecting a list of strings and not a list of lists :-/
    # return output
    return [''.join(x) for x in output]


a = ['x', 'y', 'z']
print generate_all_subsets(a)
