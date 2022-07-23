// https://leetcode.com/discuss/interview-question/2260088/special-path-google-oa-july-2022-graph/1480733

#include<bits/stdc++.h>
using namespace std;

int find(vector<int> &dis_arr, int i)
{
    if (dis_arr[i] == -1)
        return i;
    else
        return find(dis_arr, dis_arr[i]);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> adj_list[n], values(n);
        ;
        for (int i = 0; i < n - 1; i++)
        {
            int x, y;
            cin >> x >> y;
            adj_list[x - 1].push_back(y - 1);
            adj_list[y - 1].push_back(x - 1);
        }
        map<int, set<int>> mp;
        for (int i = 0; i < n; i++)
        {
            cin >> values[i];
            if (mp.count(values[i]) == 0)
                mp[values[i]] = {i};
            else
                mp[values[i]].insert(i);
        }
        sort(values.begin(), values.end());

        vector<int> dis_arr(n, -1);
        int prev = -1;
        long long ans = 0, x = 0;
        int first = -1;
        for (int i = 0; i < n; i++)
        {
            x = 0;

            if (prev == values[i])
                continue;
            for (auto j = mp[values[i]].begin(); j != mp[values[i]].end(); j++)
            {
                if (first != -1)
                {
                    for (int k = 0; k < adj_list[*j].size(); k++)
                    {
                        int u = *j;
                        int v = adj_list[*j][k];
                        if (find(dis_arr, v) == first)
                        {
                            dis_arr[*j] = first; // Union
                            x++;
                            continue;
                        }
                    }
                }
                else
                    first = *j;
            }
            ans += (x * (x - 1)) / 2;
            prev = values[i];
        }
        cout << ans << endl;
    }
}

/*

TestCase -

1
5
2 1
3 2
4 2
5 3
3 3 2 3 3

output - 6

1
5
2 1
3 1
4 1
5 1
1 3 1 2 3

output - 2

1
6
1 2
1 3
3 4
3 5
2 6
2 3 1 2 3 3

output - 4

*/