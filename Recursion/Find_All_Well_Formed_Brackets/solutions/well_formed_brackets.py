OPENING_BRACKET = '('
CLOSING_BRACKET = ')'


def find_all_well_formed_brackets(n):
    output = []
    if not n:
        return output
    in_arr = [None] * 2 * n

    def _generate_well_formed_brackets(left_remaining, right_remaining, start):
        # invalid case - number of closing brackets is greater than number of opening brackets
        if left_remaining < 0 or left_remaining > right_remaining:
            return

        if left_remaining == 0 and right_remaining == 0:
            output.append(''.join(in_arr))
            return

        # add opening bracket and recurse
        in_arr[start] = OPENING_BRACKET
        _generate_well_formed_brackets(left_remaining - 1, right_remaining, start + 1)

        # add closing bracket and recurse
        in_arr[start] = CLOSING_BRACKET
        _generate_well_formed_brackets(left_remaining, right_remaining - 1, start + 1)

        # set back arr
        in_arr[start] = None

    _generate_well_formed_brackets(n, n, 0)
    return output



print find_all_well_formed_brackets(1)
print find_all_well_formed_brackets(2)
print find_all_well_formed_brackets(3)
