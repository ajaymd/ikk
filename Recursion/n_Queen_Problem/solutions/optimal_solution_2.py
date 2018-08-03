# Reference - https://github.com/InterviewKickstart/CodingProblemsIK/blob/master/Recursion/n_Queen_Problem/editorial.txt


# ------------------------------------------ START ------------------------------------------

def find_all_arrangements(n):
    output = []

    # n columns for n rows
    col_occupied = [False] * n

    # for n * n board there are 2*n - 1 diagonals (slash and back slash diagonals)
    slash_diag_occupied = [False] * (2*n-1)
    back_slash_diag_occupied = [False] * (2*n-1)

    # by using auxilary space for col occupied and diags occupied and updating then accordingly this function will run in O(1)
    def is_safe(row, col):
        return not (col_occupied[col] or slash_diag_occupied[row+col] or back_slash_diag_occupied[row-col+n-1])

    def _generate_n_queens(curr_arrangement, row):
        if row == n:
            output.append([x for x in curr_arrangement])
            return

        for col in range(0, n):
            if is_safe(row, col):
                # mark this col and both diagonals as being occupied
                curr_arrangement[row] = col
                col_occupied[col] = True
                slash_diag_occupied[row+col] = True
                back_slash_diag_occupied[row-col+n-1] = True

                # try to place queen in the next row
                _generate_n_queens(curr_arrangement, row+1)

                # set back as not occupied
                col_occupied[col] = False
                slash_diag_occupied[row+col] = False
                back_slash_diag_occupied[row-col+n-1] = False

    # start recursive function with empty current arrangement and 0 row
    _generate_n_queens([None]*n, 0)
    return generate_output(output)


def generate_output(boards):
    output = []
    for arr in boards:
        o = [['-'] * len(arr) for _ in range(len(arr))]
        for r, c in enumerate(arr):
            o[r][c] = 'q'
        # join rows
        output.append([''.join(row) for row in o])
    return output


# ------------------------------------------ STOP ------------------------------------------


# MAIN FUNCTION/SAMPLE INPUT


# for i in range(0, 6):
#     out = find_all_arrangements(i)
#     print('for n = ', i)
#     print('\n')
#     for a in out:
#         print('\n'.join(a))
#         print('\n')
out = find_all_arrangements(5)
print(out)
print(len(out))