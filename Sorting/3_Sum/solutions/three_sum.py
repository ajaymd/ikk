def three_sum(nums, k=0):
    output = []
    if len(nums) < 3:
        return

    # sorted_nums = sorted(nums)
    nums.sort()
    n = len(nums)
    for i in range(n-2):
        x = nums[i]
        low = i + 1
        high = n - 1
        while low < high:
            curr_sum = x + nums[low] + nums[high]
            if curr_sum == k:
                output.append([x, nums[low], nums[high]])
                low += 1
                high -= 1
            elif curr_sum < k:
                # need to pick a higher second number
                low += 1
            else:
                # need to pick a lower third number
                high -= 1

    return output


n = [6, 10, 3, -4, 1, -6, 9]
print three_sum(n)