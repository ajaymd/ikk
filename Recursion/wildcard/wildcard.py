POSSIBILITIES = ['1', '0']
WILDCARD = '?'


def find_all_possibilities(string_input):
    if not string_input or not WILDCARD in string_input:
        return [string_input]

    output = []
    n = len(string_input)
    str_arr = list(string_input)

    # recursive function to do the work
    # while writing the recursive function it's good to have only parameters which change, here it's the start of recursion
    def _wildcard(start):
        # base case
        if start == n:
            output.append(''.join(str_arr))
            return

        if str_arr[start] == WILDCARD:
            for e in POSSIBILITIES:
                str_arr[start] = e
                _wildcard(start + 1)
                # set it back to wild card at the end of dfs
                str_arr[start] = WILDCARD
        else:
            _wildcard(start + 1)

    # call recursive function with starting point
    _wildcard(0)
    return output


print find_all_possibilities('10??1?')

