#include<bits/stdc++.h>
using namespace std;

int my_min(vector<int>& nums){
    int mn = INT_MAX;
    int mx = INT_MIN;
    for(auto x : nums)
    {
        mn = min(mn, x);
        mx = max(mx, x);
    }
    return mn;
}

int main()
{

    vector<int> v = {6, 1, 6, 9, 2, 0};
    int mn = INT_MAX;
    int mx = INT_MIN;

    for (int i = 0; i < v.size(); i++)
    {
        if(v[i] < mn){
            mn = v[i];
        }

        if(v[i] > mx){
            mx = v[i];
        }
    }

    for (int i = 0; i < v.size(); i++)
    {
        mn = min(mn, v[i]);
        mx = max(mx, v[i]);
    }
    
    for(auto x : v)
    {
        mn = min(mn, x);
        mx = max(mx, x);
    }

    cout << my_min(v);

    cout << "Min - " << mn << " Max - " << mx << endl;
    return 0;
}