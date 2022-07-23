// https://leetcode.com/discuss/interview-question/2258394/Google-OA

/*

You are given the following:

Integers n, c, d
Array a as {a1, a2, ..., an} of length n
Array b as {b1, b2, ..., bn} of length n
Task
Determine the number of pairs i, j (1 <= i < j <= n), satisfying the inequality
ai - aj + c <= bi - bj + d

Constraints
1 <= T <= 10
2 <= n <= 2.10^5
0 <= c, d <= 100
1 <= ai, bi <= 10^9

My approach
Make an array diff where diff[i] = a[i] - b[i]
Traverse on array a

x = a[i] - b[i] + c - d
check if x is less than (min-max) of diff, then, every pair is greater than x
check if x is more than (max-min) of diff, then no pair is greater than x
otherwise go check for i+1 to n
worst case is still n^2, can anyone help further?

*/

#include <bits/stdc++.h>
using namespace std;

int X = 0;

int merge(vector<int> &arr, vector<int> &temp, int lo, int mid, int hi)
{
    int i = lo, j = mid, k = lo;
    int cnt = 0;

    int y = mid;
    for (int x = lo; x < mid; x++)
    {
        while (y <= hi and (long long) arr[x] <= (long long)X + arr[y])
        {
            y++;
        }
        cnt += y - mid;
    }

    while (i <= mid - 1 and j <= hi)
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid - 1)
    {
        temp[k++] = arr[i++];
    }

    while (j <= hi)
    {
        temp[k++] = arr[j++];
    }

    for (int i = lo; i <= hi; i++)
        arr[i] = temp[i];
    return cnt;
}
int mergesort(vector<int> &arr, vector<int> &temp, int lo, int hi)
{
    int mid;
    int cnt = 0;
    if (lo < hi)
    {
        mid = lo + (hi - lo) / 2;
        cnt += mergesort(arr, temp, lo, mid);
        cnt += mergesort(arr, temp, mid + 1, hi);
        cnt += merge(arr, temp, lo, mid + 1, hi);
    }
    return cnt;
}

int reversePairs(vector<int> &arr)
{
    int n = arr.size();
    int ans = 0;
    int lo = 0, hi = n - 1;
    vector<int> temp(n);
    ans = mergesort(arr, temp, lo, hi);
    return ans;
}

int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, c, d;
    cin >> n >> c >> d;
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    X = d - c;
    vector<int> diff(n);
    for (int i = 0; i < n; i++)
    {
        diff[i] = a[i] - b[i];
    }

    cout << reversePairs(diff);
    return 0;
}

/*

Testcases-

4 1 4
3 2 3 10
10 10 2 9

output = 6


6 1 2
7 2 2 7 7 8
8 9 2 3 4 1

output = 14


10 0 2
1 10 5 3 4 8 4 9 9 3
10 3 3 5 9 10 4 10 1 2

output = 32

*/

/*

Input
3
2 1 1
1 2
2 1
3 2 1
1 2 3
1 2 3
1 2 3

Output
2
0

Explanation
Test Case #1:

a = {1, 2}
b = {1, 2}

diff = {0, 0}

Test Case #2:

a = {1, 2}
b = {1, 2}

diff = {0, 0}

Test Case #3:

a = {1, 2, 3}
b = {1, 2, 3}

diff = {0, 0, 0}

*/