#include<bits/stdc++.h>
using namespace std;

bool compare(pair<int, int>a, pair<int,int>b)
{
    return a.first < b.first;
}
pair<int, int> twosum(vector<int>&packages, int capacity)
{
    vector<pair<int, int>> v;
    for(int i=0; i<packages.size(); i++)
    {
        v.push_back({packages[i], i});
    }
    sort(v.begin(), v.end(), compare);

    int i = 0, j = v.size() - 1;
    int target = capacity - 30;
    while(i < j)
    {
        int sum = v[i].first + v[j].first;
        if(sum == target)
        {
            pair<int, int>p = make_pair(v[i].second, v[j].second);
            if(p.first > p.second)
            {
                swap(p.first, p.second);
            }
            return p;
        }
        else if(sum > target)
            j--;
        else
            i++;
    }
    return {-1, -1};
}
int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    vector<int>packages = {1, 10, 25, 35, 60};
    int capacity = 90;
    pair<int, int> p = twosum(packages, capacity);
    cout << p.first << " " << p.second << endl;
    return 0;
}