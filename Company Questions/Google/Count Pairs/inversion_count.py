import random


def optimized_solver(n, c, d, A, B):
    X = d - c
    Z = [0] * n  # Difference Array
    for i in range(n):
        Z[i] = A[i] - B[i]
    ans = 0  # Count of elements which satisfy this property

    def merge_sort_recursive_utility(l, r):
        nonlocal ans
        # Partition base case.
        if r == l:
            return

        # Partitioning step. NOTE: All indices are inclusive
        mid = (l + r) // 2
        merge_sort_recursive_utility(l, mid)
        merge_sort_recursive_utility(mid + 1, r)

        # Merging step
        lo = lo_merge = l  # Two lo pointers: one for merging and one for forming pairs
        hi = hi_merge = mid + 1  # Two hi pointers: one for merging and one for forming pairs
        arr = []  # Merged sorted array

        # Basically do the merging that we do while sorting.
        # Apart from that we also maintain two other pointers to check for answers
        while lo_merge <= mid and hi_merge <= r:
            # The usual sorting step
            left_val, right_val = Z[lo_merge], Z[hi_merge]
            if left_val > right_val:
                arr.append(right_val)
                hi_merge += 1
            else:
                arr.append(left_val)
                lo_merge += 1
            # This is the main solving part.
			# Basically lo is our i candidate and hi is out j candidate
            # Since lo is in lower array and hi is in higher index array. i < j is always satisfied.
            # If Z[lo] - Z[hi] <= X is satisfied for current values of lo and hi.
            # Then since values to the right of hi in the 2nd array are larger than Z[hi],
			# They too will satisfy the condition for lo. Let a value to right of hi in 2nd array be Z[hi] + p,  Since it is larger than Z[hi] and p is non -ve(either 0 or +ve value)
			# So, Z[lo] - (Z[hi] + p) => Z[lo] - Z[hi] - p => Since Z[lo] - Z[hi] was itself <= X, then subtracting a non -ve value will definitely we smaller than X.
            # Hence all values including and to the right of hi can form pair with lo. Hence we add r - hi + 1 to ans that is the length of array to right of hi in 2nd array.
            # If Z[lo] - Z[hi] > X, then no point in looking forward of hi for current value of lo, hence lo++. If current dont satisfy, then later values wont satisfy the property too.
            if Z[lo] <= Z[hi] + X:
                ans += r - hi + 1
                lo += 1
            else:
                hi += 1

        # If some values still remains, we must also add them to the sorted array
        while lo_merge <= mid:
            arr.append(Z[lo_merge])
            lo_merge += 1
        while hi_merge <= r:
            arr.append(Z[hi_merge])
            hi_merge += 1

        # Update the original array with sorted one.
        for j in range(l, r + 1):
            Z[j] = arr[j - l]

    merge_sort_recursive_utility(0, n - 1)
    return ans


# Brute method to verify our answer
def brute_method_solver(n, c, d, A, B):
    ans = 0
    for i in range(n - 1):
        for j in range(i + 1, n):
            if A[i] - A[j] + c <= B[i] - B[j] + d:
                ans += 1
    return ans


# Random input generator to generate random inputs and validate our answers
def random_input_generator(test_size):
    for _ in range(test_size):
        n = random.randint(2, 20000) # Can also run for 2*10^5, but will take time if brute method is also running
        c, d = random.randint(0, 100), random.randint(0, 100)
        a, b = [], []
        for i in range(n):
            a.append(random.randint(1, 10 ** 9))
            b.append(random.randint(1, 10 ** 9))
        # Use this to check answers from both approaches, may take 10-20 seconds due to O(n^2) brute method also running.
        # print('Got:', optimized_solver(n, c, d, a, b), "but Expected:", brute_method_solver(n, c, d, a, b))
        # Use this to run only optimized version, runs almost instantaneously
        print('Got:', optimized_solver(n, c, d, a, b))


def custom_input_runner():
    t = int(input())
    while t:
        t -= 1
        n, c, d = int(input()), int(input()), int(input())
        a = list(map(int, input().split(" ")))
        b = list(map(int, input().split(" ")))
        # Use this to check answers from both approaches, may take 10-20 seconds due to O(n^2) brute method also running.
        print('Got:', optimized_solver(n, c, d, a, b), "but Expected:", brute_method_solver(n, c, d, a, b))
        # Use this to run only optimized version, runs almost instantaneously
        # print('Got:', optimized_solver(n, c, d, a, b))


random_input_generator(5)