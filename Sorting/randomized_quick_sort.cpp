#include<bits/stdc++.h>
using namespace std;

int partition(vector<int>&v, int lo, int hi)
{
    int pivot = hi;
    int idx = lo;
    for(int i=lo;i<hi;i++)
    {
        if(v[i] < v[pivot])
        {
            swap(v[i], v[idx]);
            idx++;
        }
    }
    swap(v[pivot], v[idx]);
    return idx;
}

int random_pivot_partition(vector<int>&v, int lo, int hi)
{
    int n = rand();
    int pivot = lo + n%(hi-lo+1);

    swap(v[hi], v[pivot]);
    return partition(v, lo, hi);
}   

void quick_sort(vector<int>&v, int lo, int hi)
{
    if(lo < hi)
    {
        int pivot_index = random_pivot_partition(v, lo, hi);
        quick_sort(v, lo, pivot_index);
        quick_sort(v, pivot_index+1, hi);
    }
}
int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    vector<int>v = {4,2,6,8,5,9,1,50};
    int n = v.size();
    quick_sort(v, 0, n-1);

    for(int i=0;i<n;i++)
        cout<<v[i]<<" ";
    return 0;
}