def findZeroSum(nums, k=0):
    if not nums or len(nums) < 3:
        return []
    n = len(nums)
    output = []
    nums.sort()
    for i, num in enumerate(nums[:-2]):
        if i > 0 and nums[i] == nums[i - 1]:
            continue
        l = i + 1
        r = n - 1
        while l < r:
            s = num + nums[l] + nums[r]
            if s > 0:
                r -= 1
            elif s < 0:
                l += 1
            else:
                output.append([num, nums[l], nums[r]])
                # remove duplicates
                while l + 1 < r and nums[l] == nums[l + 1]:
                    l += 1
                while r - 1 > l and nums[r] == nums[r - 1]:
                    r -= 1
                l += 1
                r -= 1

    # return output
    #  hackerrank wants a string output :-/ ugh
    return map(lambda x: ','.join([str(a) for a in x]), output)


n = [6, 10, 3, -4, 1, -6, 9]
print findZeroSum(n)
n = [6, -1, -1, 0, 0, 1, 1]
print findZeroSum(n)
