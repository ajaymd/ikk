def pow(base, exp):
    absexp = abs(exp)

    # recursive function to calculate base ^ positive exponent
    def _pow(exp):
        if exp == 0:
            return 1
        elif exp == 1:
            return base

        if exp % 2 == 0:
            temp = _pow(exp / 2)
            return temp * temp
        else:
            temp = _pow((exp - 1) / 2)
            return temp * base * base

    result = _pow(absexp)

    if exp < 0:
        return 1.0 / result

    return result


print pow(2, -3)

