def group_nums(nums):
    if not nums or len(nums) == 1:
        return nums

    _group_nums(nums, 0, len(nums)-1)


def swap(arr, i, j):
    arr[i], arr[j] = arr[j], arr[i]


def _group_nums(nums, left, right):
    while left < right:
        while nums[left] % 2 == 0:
            left += 1
        while right >= 0 and nums[right] % 2 != 0:
            right -= 1

        if left < right:
            swap(nums, left, right)


n = [1, 2, 3, 4, 5, 6, 1, 3, 5, 8, 9, 10]
group_nums(n)
print n

n = [1, 1, 3, 3, 5]
group_nums(n)
print n

n = [1, 2, 3, 4]
group_nums(n)
print n