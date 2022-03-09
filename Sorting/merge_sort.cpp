#include<bits/stdc++.h>
using namespace std;

void merge(vector<int>&v, int start, int mid, int end)
{
    // Create a temp array
    vector<int>temp(end - start + 1);

    //
    int i=start, j = mid+1, k = 0;
    while(i<=mid and j <= end)
    {
        if(v[i] < v[j])
        {
            temp[k++] = v[i++];
        }
        else
            temp[k++] = v[j++];
    }

    while(i <= mid)
        temp[k++] = v[i++];
    
    while(j <= end)
        temp[k++] = v[j++];
    
    k = 0;
    for(int i=start;i<=end;i++)
    {
        v[i] = temp[k++];
    }
}

void merge_sort(vector<int>&v, int start, int end)
{
    if(start < end)
    {
        int mid = start + (end - start)/2;
        merge_sort(v, start, mid);
        merge_sort(v, mid+1, end);
        merge(v, start, mid, end);
    }
}
int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    vector<int>v = {4,2,6,8,5,9,1,50};
    int n = v.size();
    merge_sort(v, 0, n-1);

    for(int i=0;i<n;i++)
        cout<<v[i]<<" ";
    return 0;
}