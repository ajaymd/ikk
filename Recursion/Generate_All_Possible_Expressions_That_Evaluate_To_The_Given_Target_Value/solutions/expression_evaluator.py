# Note - this does not do evaluation on the fly while building the expression

EXPRS = ['+', '*', '$']


def intersperse(lst, e=None):
    arr = [e] * (2 * len(lst) - 1)
    arr[0::2] = lst
    return arr


def generate_all_expressions(exp, r):
    output = []
    if not exp or not isinstance(exp, str) or (not r and r != '0'):
        return output

    result = int(r)

    if len(exp) == 1:
        if int(exp) == int(result):
            return '%s=%s' % (exp, result)

    arr = intersperse(list(exp))
    n = len(arr)

    # recursive function to build possible expressions and prune
    def _build_exprs(c):
        curr_exp = ''.join([x for x in arr[:c] if x != '$'])
        curr_result = eval(curr_exp)

        # prune here if current value is greater than result
        if eval(curr_exp) > result:
            return

        if c == n:
            if curr_result == result:
                output.append('%s=%s' % (curr_exp, result))
            return

        for e in EXPRS:
            arr[c] = e
            _build_exprs(c + 2)
            # set current char back to None
            arr[c] = None

    _build_exprs(1)
    return output


a = '551'
result = '25'
print generate_all_expressions(a, result)
