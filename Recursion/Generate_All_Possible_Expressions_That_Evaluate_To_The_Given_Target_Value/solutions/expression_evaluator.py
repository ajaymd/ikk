# https://leetcode.com/problems/expression-add-operators/description/

# ------------------------------------------ START ------------------------------------------


def generate_all_expressions(num, target):
    """
    :type num: str
    :type target: int
    :rtype: List[str]
    """
    if not num:
        return []
    output = []

    def _dfs(so_far, evaluated, start, prev):
        """
        :param so_far: expression so far (string)
        :param evaluated: evaluated value so far (int)
        :param start: index to start recursing from
        :param prev: prev value to use for the multiplication special case to give it precedence (explained in comments)
        :return: doesn't return, appends to output in the base case
        """
        if start == len(num):
            if evaluated == target:
                output.append(so_far)
            return

        for i in range(start, len(num)):
            # can't have leading zeros concatenated in leetcode version, but IK version allows it
            # if num[start] == '0' and i > start:
            #     break
            curr = num[start:i + 1]
            curr_int = int(curr)
            if start == 0:
                # just appending digits for first pass
                _dfs(so_far + curr, curr_int, i + 1, curr_int)
            else:
                _dfs(so_far + '+' + curr, evaluated + curr_int, i + 1, curr_int)
                # Leetcode version also has - sign
                # _dfs(so_far + '-' + curr, evaluated - curr_int, i + 1, -curr_int)
                # Detailed explanation - https://github.com/InterviewKickstart/CodingProblemsIK/blob/master/Recursion/Generate_All_Possible_Expressions_That_Evaluate_To_The_Given_Target_Value/solutions/optimal_solution.cpp
                # In short we need to give precdence to multiplication - eg if we have a + b * c, we really want a + (b*c) and not (a+b) * c;
                #  having the evaluated so far value say s and prev value passed up b (for addition b, and for multiplication a * b), will help us evaluate correctly
                # For prev addition; ev = (a + b), prev = b, curr = c; so current calculation (ev - prev) + (prev * curr) will give us (a + b - b) + (b * c) = a + (b * c)
                # For prev multiplication; ev = (a * b), prev = a * b, curr = c; so current calculation (ev - prev) + (prev * curr) will give us (a * b - a * b) + (a * b * c) = a * b * c
                # For prev subtraction (in LC) ; ev = (a - b), prev = -b, curr = c; so current calculation (ev - prev) + (prev * curr) will give us (a - b + b) + (-b * c) = a - (b * c)
                _dfs(so_far + '*' + curr, (evaluated - prev) + (prev * curr_int), i + 1, prev * curr_int)

    _dfs('', 0, 0, 0)
    return output

# ------------------------------------------ STOP ------------------------------------------

# MAIN/SAMPLE INPUT


print(generate_all_expressions('222', 24))
