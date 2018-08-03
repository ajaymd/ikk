# ------------------------------------------ START ------------------------------------------


def generate_all_subsets(s):
    output = []

    # recursive function to generate subsets
    def _generate_all_subsets(so_far, idx):
        # base case
        if idx == len(s):
            # IK OJ is expecting a list of strings and not a list of lists
            output.append(''.join(so_far))
            return

        # recurse after adding current and not adding current to so_far
        _generate_all_subsets(so_far + [s[idx]], idx+1)
        _generate_all_subsets(so_far, idx+1)

    _generate_all_subsets([], 0)

    return output

# ------------------------------------------ STOP ------------------------------------------


# SAMPLE TEST CASES
a = ['x', 'y', 'z']
print generate_all_subsets(a)
a = ['x']
print generate_all_subsets(a)
a = []
print generate_all_subsets(a)

