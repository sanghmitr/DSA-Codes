//https://binarysearch.com/problems/Find-the-Largest-Number-in-a-Rotated-List

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMax(vector<int>& arr) {
    int n = arr.size();
    int mx = INT_MIN;
    int l = 0, h = n - 1;
    while (l < h) {
        int mid = (l + h) / 2;
        if (arr[mid] > arr[h]) {
            l = mid + 1;
        } 
        else 
        {
            h = mid;
        }
    }
    if(l==0)
        return arr[n-1];
    return arr[l-1];
}
};

int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Solution s;
    vector<int>nums = {4,5,6,7,0,1,2,3};
    cout<<s.findMax(nums);
    return 0;
}