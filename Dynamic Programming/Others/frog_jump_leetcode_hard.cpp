//https://leetcode.com/problems/frog-jump/


class Solution {
public:
    vector<vector<int>>dp;
    bool recursive(vector<int>& stones, int i, int lastJump)
    {
        if(i == stones.size()-1)
            return true;
        
        if(i >= stones.size())
            return false;
        
        if(dp[i][lastJump] != -1)
            return dp[i][lastJump];
        
        bool res = false;
        for(int j=-1; j<=1; j++)
        {
            int nextJump = lastJump + j;
            if(nextJump > 0)
            {
                int idx = lower_bound(stones.begin(), stones.end(), stones[i]+nextJump) - stones.begin();
                
                if(idx == stones.size() or stones[idx] != stones[i] + nextJump)
                    continue;
                
                res = res or recursive(stones, idx, nextJump);
            }
        }
        return dp[i][lastJump] = res;
    }
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        dp.resize(n+1, vector<int>(n+1, -1));
        return recursive(stones, 0, 0);
    }
};