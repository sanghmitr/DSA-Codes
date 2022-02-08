/*

Write a function that takes input an sorted array of distinct integers, which is rotated about pivot point
and finds the index of any given eleement.

Input array = [7,9,10,1,2,3,4,5,6]
key = 4

output = 6

*/
#include<bits/stdc++.h>
using namespace std;

int rotated_search(vector<int>&v, int key)
{
    int s = 0, e = v.size()-1;

    while(s <= e)
    {
        int mid = s+(e-s)/2;
        if(v[mid] == key)
            return mid;
        // 2 cases
        if(v[s] <= v[mid]) //left part
        {
            if(key >= v[s] and key <= v[mid])
            {
                e = mid-1;
            }
            else
            {
                s = mid+1;
            }
        }
        else // right part
        {
            if(key >= v[mid] and key <= v[e])
            {
                s = mid+1;
            }
            else
                e = mid -1;
        }
    }
    return -1;
}
int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    vector<int>v = {4,5,6,7,0,1,2,3};
    int key = 6;
    cout<<rotated_search(v, key);
    return 0;
}