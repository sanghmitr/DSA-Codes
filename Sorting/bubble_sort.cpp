#include<bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int>&v)
{
    for(int i=0;i<v.size();i++)
    {
        for(int j=i+1;j<v.size();j++)
        {
            if(v[i] > v[j])
                swap(v[i], v[j]);
        }
    }
}
int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    vector<int>v = {4,2,6,6,9,1,3,7};
    bubbleSort(v);
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<" ";
    return 0;
}