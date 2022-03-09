#include<bits/stdc++.h>
using namespace std;

void selectionSort(vector<int>&v)
{
    for(int i=0;i<v.size();i++)
    {
        int mn = INT_MAX;
        int mn_idx = -1;
        for(int j=i;j<v.size();j++)
        {
            if(mn > v[j])
            {
                mn = v[j];
                mn_idx = j;
            }
        }
        swap(v[i], v[mn_idx]);
    }
}
int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    vector<int>v = {4,2,6,6,9,1,3,7};
    selectionSort(v);
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<" ";
    return 0;
}