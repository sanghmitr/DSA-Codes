/*

Given a sorted array which can contain repeated elements, and an element K
We need to find the frequency of a given element.

Input array = [ 0,1,1,1,1,2,2,2,3,4,4,5,10]
key = 2

output = 3

*/

#include<bits/stdc++.h>
using namespace std;

// This lowerbound only finds the first equal occurance of the key. It is different from STL lower_bound
int lowerBound(vector<int>&v, int key)
{
    int lo = 0, hi = v.size()-1;
    int ans = -1; // -1 means element not present in the array

    while(lo <= hi)
    {
        int mid = lo + (hi-lo)/2;
        if(v[mid] == key)
        {
            // If key is found then reduce our search space to the left side of mid
            ans = mid;
            hi = mid-1;
        }
        else if(v[mid] < key)
            lo = mid + 1;
        else
            hi = mid - 1;
    }
    return ans;
}   

// This lowerbound only finds the last equal occurance of the key. It is different from STL lower_bound
int upperBound(vector<int>&v, int key)
{
    int lo = 0, hi = v.size()-1;
    int ans = -1; // -1 means element not present in the array

    while(lo <= hi)
    {
        int mid = lo + (hi-lo)/2;
        if(v[mid] == key)
        {
            //If key is found then reduce our search space to right side of the mid
            ans = mid;
            lo = mid+1;
        }
        else if(v[mid] < key)
            lo = mid + 1;
        else
            hi = mid - 1;
    }
    return ans;
} 

int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    vector<int>v = {0,1,1,1,1,2,2,2,3,3,3,3,3,4,4,5,10};
    int key = 2;

    if(lowerBound(v, key) == -1)
    {
        cout<<"Key not present"<<endl;
        return 0;
    }
    int ans = upperBound(v, key) - lowerBound(v, key) + 1;
    cout<<ans<<endl;

    //Using STL
    // Upper bound gives->  '>' strictly greater index
    // Lower bound gives->  '>=' greater than equals index
    cout<<upper_bound(v.begin(), v.end(), key) - lower_bound(v.begin(), v.end(), key)<<endl;
    return 0;
}