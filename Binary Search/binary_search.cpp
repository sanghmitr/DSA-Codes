#include<bits/stdc++.h>
using namespace std;

bool binarySearch(vector<int>&v, int num)
{
    int n = v.size();
    int lo = 0, hi = n-1;
    while(lo <= hi)
    {
        int mid = lo + (hi-lo)/2;
        if(v[mid] == num)
            return true;
        else if(v[mid] < num)
            lo = mid + 1;
        else
            hi = mid - 1;
    }
    return false;
}
int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    vector<int>v = {5,8,9,12,25,30,32,45,50};

    if(binarySearch(v, 12))
        cout<<"Present"<<endl;
    else 
        cout<<"Not Present"<<endl;

    return 0;
}