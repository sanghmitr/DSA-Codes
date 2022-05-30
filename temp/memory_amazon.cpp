#include<bits/stdc++.h>
using namespace std;

int minimizeMemory(vector<int>&processes, int m)
{
    int n = processes.size();

    int res = 0;
    int total = 0;
    for (int i=0; i<m; i++)
    {
        res += processes[i];
        total += processes[i];
    }
 
    int curr_sum = res;
    for (int i=m; i<n; i++)
    {
        total += processes[i];
        curr_sum += processes[i] - processes[i - m];
        res = max(res, curr_sum);
    }
    
    return total - res;
}
int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<int> processes = {10, 4, 8, 1};
    int m = 2;
    cout << minimizeMemory(processes, m) << endl;
    return 0;
}