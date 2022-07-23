
#include<bits/stdc++.h>
using namespace std;

int diff = 0;

int merge(vector<int> &a, vector<int> &temp, int l, int m, int h)
{
    int inv = 0;

    int i = l, j = m + 1;

    for (; i <= m; ++i)
    {
        while (j <= h && a[i] >= a[j] + diff)
            ++j;
        inv += (j - (m + 1));
    }

    for (int k = l; k <= h; ++k)
        temp[k] = a[k];
    i = l;
    j = m + 1;

    for (int k = l; k <= h; ++k)
    {
        if (i > m)
            a[k] = temp[j++];
        else if (j > h)
            a[k] = temp[i++];
        else if (temp[i] > temp[j])
            a[k] = temp[j++];
        else
            a[k] = temp[i++];
    }

    return inv;
}

int mergeSort(vector<int>&a, vector<int>&temp, int l, int h)
{
    if (l >= h)
        return 0;
    int m = l + (h - l) / 2, inv = 0;

    inv += mergeSort(a, temp, l, m);
    inv += mergeSort(a, temp, m + 1, h);
    inv += merge(a, temp, l, m, h);

    return inv;
}


int reversePairs(vector<int> &arr)
{
    int n = arr.size();
    int ans = 0;
    int lo = 0, hi = n - 1;
    vector<int> temp(n);
    ans = mergeSort(arr, temp, lo, hi);
    return ans;
}

int main()
{
    ios_base :: sync_with_stdio(0);
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

    diff = c - d;
    vector<int> difference(n);
    for (int i = 0; i < n; i++){
        difference[i] = b[i] - a[i];
    }

    cout << reversePairs(difference);
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