/*

Given an integer N and an integer P, you need to find the square root of the given number N upto P decimal places.
Do it without using a library function.

N = 10
P = 3

ans = 3.162

*/

#include<bits/stdc++.h>
using namespace std;

double square_root(int n, int p)
{
    int s = 0, e = n;
    double ans = 0;

    //Binary Search to find the integer before decimal point (search space 0....N)
    while(s<=e)
    {
        int mid = s+(e-s)/2;
        if(mid*mid == n)
            return mid;
        else if(mid*mid < n)
        {
            ans = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    //cout<<ans<<endl;

    //Linear search for the floating part
    double inc = 0.1; 
    for(int i=0;i<p;i++)
    {
        //do linear search
        while(ans*ans <= n)
        {
            ans += inc;
        }
        //take one step back
        ans = ans - inc;
        inc = inc/10.0;
    }
    return ans;
}
int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int N,P;
    cin>>N>>P;

    cout<<square_root(N, P);
    return 0;
}