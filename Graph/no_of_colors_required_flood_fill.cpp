#include<bits/stdc++.h>
using namespace std;

bool isBound(int i, int j, int n, int m, vector<vector<bool>>&vis)
{
    if(i>=0 and i<n and j>=0 and j<m and vis[i][j] == false)
        return true;
    return false;
}
void dfs(vector<vector<char>>&mat, vector<vector<bool>>&vis, int i, int j)
{
    int n = mat.size();
    int m = mat[0].size();
    vis[i][j] = true;

    if(isBound(i+1, j, n, m, vis) and mat[i+1][j] == mat[i][j])
        dfs(mat, vis, i+1, j);
    
    if(isBound(i-1, j, n, m, vis) and mat[i-1][j] == mat[i][j])
        dfs(mat, vis, i-1, j);
    
    if(isBound(i, j+1, n, m, vis) and mat[i][j+1] == mat[i][j])
        dfs(mat, vis, i, j+1);

    if(isBound(i, j-1, n, m, vis) and mat[i][j-1] == mat[i][j])
        dfs(mat, vis, i, j-1);
}
int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    vector<string>v = {"aaaba", "ababa", "aaaca"};
    //{"aabba", "aabba",  "aaacb"};
    int n = v.size();
    int m = v[0].size();
    vector<vector<char>>mat(n, vector<char>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
             mat[i][j] = v[i][j];
        }
    }

    vector<vector<bool>>vis(n, vector<bool>(m, false));
    int cnt = 0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(vis[i][j] == false)
            {
                cnt++;
                dfs(mat, vis, i, j);
            }
        }
    }
    cout<<cnt<<endl;
    return 0;
}