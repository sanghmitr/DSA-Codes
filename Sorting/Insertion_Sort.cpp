#include<bits/stdc++.h>
using namespace std;

void insertion_sort(vector<int>&v)
{
    for(int i=0;i<v.size();i++)
    {
        int key = v[i];
        int j = i-1;
        while(j>=0 and v[j] > key)
        {
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = key;
    }
}
int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    vector<int>v = {4,2,6,8,5,9,1};
    insertion_sort(v);
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<" ";
    return 0;
}