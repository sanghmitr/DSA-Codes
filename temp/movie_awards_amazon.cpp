#include<bits/stdc++.h>
using namespace std;

int minAwards(vector<int>&awards, int k)
{
    sort(awards.begin(), awards.end());
    int groups = 0;

    int key_ele = awards[0];
    for (int i = 1; i < awards.size(); i++)
    {
        if(awards[i] - key_ele > k)
        {
            key_ele = awards[i];
            groups++;
        }
    }
    return groups+1;
}
int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<int> awards = {1, 13, 6, 8, 9, 3, 5};
    int k = 4;
    cout<<minAwards(awards, k)<<endl;
    return 0;
}

