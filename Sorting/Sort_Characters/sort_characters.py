def sort_characters(in_str):
    if not in_str or len(in_str) == 1:
        return in_str
    in_arr = list(in_str)
    output_arr = [0] * 256
    for c in in_str:
        output_arr[ord(c)] += 1

    ctr = 0
    for i, n in enumerate(output_arr):
        if n == 0:
            continue
        for count in range(n):
            in_arr[ctr+count] = chr(i)
        ctr += n

    return ''.join(in_arr)


print sort_characters('This is easy')