"""
Question:
Given an array of integers, return the subarray with maximum sum
"""


# Brute force - O(N^3)
# Begin
def bruteforce(arr):
    """
    We'll generate all subarrays of the given array
    Sum up each subarray
    Maintain the maximum sum, corresponding start and end
    Return the start and end after we're through with all subarrays
    """
    max_sum = 0
    max_start = -1
    max_end = -1
    for start in xrange(len(arr)):
        for end in xrange(start, len(arr)):
            curr_sum = 0
            for i in xrange(start, end+1):
                curr_sum += arr[i]
            if curr_sum > max_sum:
                max_sum = curr_sum
                max_start = start
                max_end = end
    return max_start, max_end
# End


# Improvement on brute force - O(N^2)
# Begin
def improved(arr):
    """
    The key insight from generating all subarrays is that
    once we generate a subarray [start, end], the immediate next subarray we
    will process is [start, end+1].

    Therefore, if we know the sum of [start, end], we don't need to iterate
    over [start, end+1] to get the sum of the next subarray like we were doing
    in the brute force solution. We can instead just add arr[end+1] to the
    previous sum.

    This pattern can be applied at many places where we generate all subarrays
    or substrings.
    """
    max_sum = 0
    max_start = -1
    max_end = -1
    for start in xrange(len(arr)):
        cumulative_sum = 0
        for end in xrange(start, len(arr)):
            cumulative_sum += arr[end]
            if cumulative_sum > max_sum:
                max_sum = cumulative_sum
                max_start = start
                max_end = end
    return max_start, max_end
# End


# Divide and conquer approach - O(N.logN)
# Begin
def divide_and_conquer(arr):
    """
    For a given array there are three possibilities,
    The maximum sum subarray
    - is entirely in the left half
    - is entirely in the right half
    - is crossing the middle element

    Returns a tuple of start index and end index of the max sum subarray
    """
    start, end, _ = divide_and_conquer_helper(arr, 0, len(arr)-1)
    return start, end


def max_sum_subarray_necessarily_including_idx(arr, start, end, idx):
    mid = (start + end) / 2
    # Identify the max sum subarray that necessarily includes the middle element

    # Count the cumulative sum starting from middle element till the left end
    # and keep track of the maximum we accumulated along the way
    l_cum_sum = 0
    l_cum_max = 0
    l_cum_max_idx = mid
    for i in xrange(mid-1, -1, -1):
        l_cum_sum += arr[i]
        if l_cum_sum > l_cum_max:
            l_cum_max = l_cum_sum
            l_cum_max_idx = i

    # Count the cumulative sum starting from middle element till the right end
    # and keep track of the maximum we accumulated along the way
    r_cum_sum = 0
    r_cum_max = 0
    r_cum_max_idx = mid
    for i in xrange(mid+1, len(arr)):
        r_cum_sum += arr[i]
        if r_cum_sum > r_cum_max:
            r_cum_max = r_cum_sum
            r_cum_max_idx = i

    # The overall maximum sub array including the middle element
    # should be the maximum to the left of the middle element, the middle
    # element itself and the maximum to the right
    m_max = r_cum_max + l_cum_max + arr[mid]
    if m_max < 0:
        # If the maximum sum including the middle element is less than zero
        # then the maximum sum subarray including the middle element is the
        # empty subarray
        m_start, m_end, m_max = -1, -1, 0
    else:
        m_start, m_end = l_cum_max_idx, r_cum_max_idx
    return m_start, m_end, m_max


def divide_and_conquer_helper(arr, start, end):
    """
    Helper for divide_and_conquer
    'end' is non-inclusive

    Returns a 3-tuple of start index, end index and sum of the max sum subarray
    """
    if start == end:
        return -1, -1, 0
    if start == end-1:
        return start, start, max(arr[start], 0)

    mid = (start + end) / 2
    # Get the max sum subarray entirely in the left half
    l_start, l_end, l_max = divide_and_conquer_helper(arr, start, mid)
    # Get the max sum subarray entirely in the right half
    r_start, r_end, r_max = divide_and_conquer_helper(arr, mid+1, end)
    # Get the max sum subarray necessarily including the middle element
    m_start, m_end, m_max = max_sum_subarray_necessarily_including_idx(
        arr, start, end, mid)

    final_max = max(l_max, r_max, m_max)
    if final_max == l_max:
        # Max sum subarray is entirely in the left half of the array
        return l_start, l_end, l_max
    if final_max == r_max:
        # Max sum subarray is entirely in the right half of the array
        return r_start, r_end, r_max
    # Max sum subarray spans across the two halves
    return m_start, m_end, m_max
# End


# Most optimal (Kadane's Algorithm) - O(N)
# Begin
def kadanes(arr):
    """
    The key idea is this,
    Let us assume there is a subarray A [start, end] and
    another subarray B [left, start-1]
    If the sum of B is positive, A cannot have the maximum sum but [left, end]
    could have the maximum sum.
    Conversely if sum of B is negative, [left, end] cannot have the maximum
    sum but A could.

    Based on this insight, starting from the beginning of the array,
    we explore to the right as long as we have a subarray that can contribute
    positively to any unexplored subarray to the right.
    If this running (current) subarray ever gets a negative sum, we know it
    cannot contribute to any unexplored subarray. Therefore we discard this
    subarray and start afresh from the index after it.
    If we keep doing this until we explore the entire array, we will have
    encountered the maximum subarray, so we keep track of the max subarray we
    saw so far.
    """
    max_sum = 0
    max_start = -1
    max_end = -1

    curr_start = 0
    cumulative_sum = 0
    for i in xrange(len(arr)):
        cumulative_sum += arr[i]
        if cumulative_sum > max_sum:
            # From [curr_start, i] is the maximum sum subarray so far
            max_sum = cumulative_sum
            max_start = curr_start
            max_end = i
        elif cumulative_sum < 0:
            # [curr_start, i] has a negative sum so it cannot contribute
            # positively to any adjacent subarray's sum so we reset
            cumulative_sum = 0
            curr_start = i+1
    return max_start, max_end
# End
