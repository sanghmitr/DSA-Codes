#include<bits/stdc++.h>
using namespace std;

string rotateLeft(string s , int d)
{
    reverse(s.begin(), s.begin()+d);
    reverse(s.begin()+d, s.end());
    reverse(s.begin(), s.end());
    return s;
}

string rotateRight(string s, int d)
{
    int n = s.length();
    d = n-d;
    return rotateLeft(s, d);
}
int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string s = "amazon";
    cout<<rotateLeft(s, 2)<<endl;
    cout<<rotateRight(s, 2)<<endl;
    return 0;
}