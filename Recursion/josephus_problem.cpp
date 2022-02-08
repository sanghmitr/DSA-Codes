#include <iostream>
using namespace std;
 
int josephus(int n, int k)
{
    if (n == 1)
        return 1;
    else
        /* The position returned by josephus(n - 1, k)
        is adjusted because the recursive call
        josephus(n - 1, k) considers the
        original position k % n + 1 as position 1 */
        return (josephus(n - 1, k) + k - 1) % n + 1;
}
 
// Driver Program to test above function
int main()
{
    int n,k;
    cin>>n>>k;
    cout << "The chosen place is " << josephus(n, k);
    return 0;
}



//O(n^2)
// #include<bits/stdc++.h>
// using namespace std;

// void solve(vector<int>&v, int k, int index, int& ans)
// {
//     if(v.size() == 1)
//     {
//         ans = v[0];
//         return;
//     }

//     int n = v.size();
//     index = (index+k-1)%n;
//     //cout<<v[index]<<" ";
//     v.erase(v.begin() + index);
//     solve(v, k, index, ans);
// }
// int main()
// {
//     ios_base :: sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
    
//     int n,k;
//     cin>>n,k;
//     vector<int>v(n);
//     for(int i=0;i<n;i++)
//         v[i] = i+1;
    
//     int ans = 0;
//     solve(v, k, 0, ans);
//     cout<<ans<<endl;
//     return 0;
// }