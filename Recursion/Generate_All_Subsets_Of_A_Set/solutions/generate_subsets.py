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
    return output


a = [1, 2, 3]
print generate_all_subsets(a)
