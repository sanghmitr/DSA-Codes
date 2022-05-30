#include<bits/stdc++.h>
using namespace std;

void solve(vector<int>&v)
{
    vector<int> ans;
    if(v.size() == 2)
        return;

    for (int i = 0; i < v.size() - 1; i++)
    {
        ans.push_back((v[i] + v[i + 1]) % 10);
    }
    v = ans;
    solve(v);
}
int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<int> v = {1,2,3,4};
    solve(v);
    string ans = "";

    for (int i = 0; i < v.size(); i++)
        ans += to_string(v[i]);

    cout << ans << endl;
    return 0;
}