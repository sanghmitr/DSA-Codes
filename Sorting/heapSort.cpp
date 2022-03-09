#include<bits/stdc++.h>
using namespace std;

void heapify(vector<int>&v,int n, int i)
{
    int largest = i;
    int l = 2*i+1;
    int r = 2*i+2;
    if(i<n and v[l] > v[i])
        largest = l;
    if(r<n and v[r] > v[i])
        largest = r;
    
    if(largest != i)
    {
        swap(v[largest], v[i]);
        heapify(v, n, largest);
    }
}    
void build_MaxHeap(vector<int>&v)
{
    int n = v.size();
    for(int i=n/2 - 1;i>=0;i--)
        heapify(v, n, i);
}

void heapSort(vector<int>&v)
{
    int n = v.size();
    for(int i = n-1; i>=0; i--)
    {
        swap(v[0], v[i]);
        heapify(v, i, 0);
    }
}
int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    vector<int>v = {10, 30, 50, 20, 25, 15};
    int n = v.size();

    build_MaxHeap(v);
    
    for(int i=0;i<n;i++)
        cout<<v[i]<<" ";
    cout<<endl;

    heapSort(v);
    for(int i=0;i<n;i++)
        cout<<v[i]<<" ";
    cout<<endl;
    return 0;
}