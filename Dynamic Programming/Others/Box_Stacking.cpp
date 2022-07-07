#include<bits/stdc++.h>
using namespace std;

bool compare(vector<int>a, vector<int>b)
{
    return a[2] < b[2];
}
int boxStacking(vector<vector<int>>&boxes)
{
    sort(boxes.begin(), boxes.end(), compare);

    int n = boxes.size();
    vector<int>dp(n+1, 0);

    for(int i=0;i<n;i++)
    {
        dp[i] = boxes[i][2];
    }

    for(int i=1;i<n; i++)
    {
        //Check for all boxes whose index is less than i;
        for(int j=0; j<i; j++)
        {
            int cur_height = boxes[i][2];
            if(boxes[j][0] < boxes[i][0] and
               boxes[j][1] < boxes[i][1] and
               boxes[j][2] < cur_height)
               {
                   dp[i] = max(dp[i], dp[j] + cur_height);
               }
        }
    }
    int mx_height = 0;
    for(int i=0; i<=n; i++){
        mx_height = max(mx_height, dp[i]);
    }
    return mx_height;
}
int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    vector<vector<int>>boxes = {
        {2,1,2},
        {3,2,3},
        {2,2,8},
        {2,3,4},
        {2,2,1},
        {4,4,5}
    };

    cout<<"max height is : "<<boxStacking(boxes);
    return 0;
}