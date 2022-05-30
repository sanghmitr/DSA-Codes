//https://binarysearch.com/problems/Max-Character-Distinct-Words

// Refer Bitmasking - https://www.youtube.com/watch?v=mqCdA8mcJeo

//  Bit masking is useful for finding intersections, unions of integers or strings.
//  Only Limitation is that we can store upto '31' elements information in the integer. Or '63' in long long int.
//  This problem is solvable using bitmask because we are storing characters as bits in integers. Since characters are only in range in 0-26 so we can easily store them into integers.

#include<bits/stdc++.h>
using namespace std;
int bitmask(string s)
{
    int ans = 0;
    for(auto c : s) 
        ans = ans | (1 << (c - 'a'));
    return ans;
}
int solve(vector<string>& words) {
    int n = words.size();

    vector<int>masks;
    for(auto s : words){
        masks.push_back(bitmask(s));
    }

    int ans = 0;
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(masks[i] + masks[j] == (masks[i] | masks[j]))
            {
                int total = words[i].size() + words[j].size();
                ans = max(ans, total);
            }
        }
    }
    return ans;
}
int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<string> words = {"abcde", "xyz", "abdexyz", "axyz"};
    cout << solve(words) << endl;
    return 0;
}

