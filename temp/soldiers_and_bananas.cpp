//https://codeforces.com/contest/546/problem/A

#include<bits/stdc++.h>
using namespace std;
     
int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int k , n, w;
    cin>>k>>n>>w;

    long long total_amt = (long long)(w*(w+1))/(long long)2;
    total_amt *= k;
    if(total_amt > n)
        cout<<total_amt - n;
    else
        cout<<"0";
    return 0;
}