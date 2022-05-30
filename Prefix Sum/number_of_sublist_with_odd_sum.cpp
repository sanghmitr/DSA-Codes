//https://binarysearch.com/problems/Number-of-Sublists-With-Odd-Sum
//https://leetcode.com/problems/number-of-sub-arrays-with-odd-sum

#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>& nums) {
    int even = 1, odd = 0, cs = 0, ans = 0;
    for (int i = 0; i < nums.size(); i++) {
        cs += nums[i];
        ans = (ans + ((cs & 1) ? even : odd)) % (1000000007);
        odd += cs & 1;
        even += !(cs & 1);

        cout << cs << " " << odd << " " << even << " " << ans << endl;
    }
    return ans;
}

int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    vector<int>v = {2,3,1,5};
    cout << solve(v) << endl;
    return 0;
}

