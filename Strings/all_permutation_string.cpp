//https://practice.geeksforgeeks.org/problems/permutations-of-a-given-string2041/1#

#include<bits/stdc++.h>
using namespace std;

void permute(string s, string op, vector<bool>&visited, vector<string>&ans)
{
    if(op.length() == s.length())
    {
        ans.push_back(op);
        return;
    }
    
    for(int i=0;i<s.length();i++)
    {
        if(!visited[i])
        {
            op.push_back(s[i]);
            visited[i] = true;
            permute(s, op, visited, ans);
            visited[i] = false;
            op.pop_back();
        }
    }
}
vector<string>find_permutation(string S)
{
    int n = S.length();
    vector<bool>visited(n, false);
    string op = "";
    vector<string>ans;
    
    permute(S, op, visited, ans);
    sort(ans.begin(), ans.end());
    return ans;
}

int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string s = "ABC";
    vector<string>permutations = find_permutation(s);
    for(auto s : permutations)
        cout<<s<<", ";
    return 0;
}