//https://leetcode.com/problems/max-chunks-to-make-sorted
#include<bits/stdc++.h>
using namespace std;
     
int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    
    return 0;
}
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        int mx = INT_MIN;
        int groups = 0;
        for(int i=0;i<n;i++)
        {
            mx = max(mx, arr[i]);
            if(mx == i)
                groups++;
        }
        return groups;
    }
};