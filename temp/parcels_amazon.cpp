#include<bits/stdc++.h>
using namespace std;

long getMinimumCost(vector<int>&parcels, int k)
{
    if(parcels.size() == k)
        return 0;

    unordered_set<int> s(parcels.begin(), parcels.end());
    int rem = k - parcels.size();
    long i = 1, ans = 0;
    while(rem)
    {
        if(!s.count(i))
        {
            ans += i;
            rem--;
        }
        i++;
    }
    return ans;
}
int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<int> v = {6,5,4,1,3};
    int k = 7;
    cout << getMinimumCost(v, k) << endl;
    return 0;
}