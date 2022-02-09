/*
Given two non-empty arrays, find the pair of numbers (one from each array)
whose absolute difference is minimum. Print the any one pair with smallest difference.

Input-
a1 = [-1,5,10,20,3]
a2 = [26,134,135,15,17]

Output-
[20,17] 
*/

#include<bits/stdc++.h>
using namespace std;

void find_minPair(vector<int>&a1, vector<int>&a2)
{
    int n = a1.size(), m = a2.size();
    sort(a2.begin(), a2.end());

    int p1=0,p2=0;
    int min_diff = INT_MAX;
    for(int i=0;i<n;i++)
    {
        int idx = lower_bound(a2.begin(), a2.end(), a1[i]) - a2.begin();
        //Greater/Right element
        if(idx < m and min_diff > abs(a2[idx] - a1[i]))
        {
            p2 = a2[idx];
            p1= a1[i];
            min_diff = abs(a2[idx] - a1[i]);
        }
        // smaller/left element
        if(idx > 0 and min_diff > abs(a2[idx-1] - a1[i]))
        {
            p2 = a2[idx-1];
            p1 = a1[i];
            min_diff = abs(a2[idx-1] - a1[i]);
        }
    }
    cout<<"Min Pair : "<<p2<<" "<<p1;
}
int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    vector<int>a1 = {-1,5,10,20,3};
    vector<int>a2 = {26, 134, 135, 15, 17};

    find_minPair(a1, a2);
    
    return 0;
}