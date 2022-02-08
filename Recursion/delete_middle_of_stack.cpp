#include<iostream>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;

void delete_middle(stack<int>&s, int mid)
{
    if(mid == 0)
    {
        s.pop();
        return;
    }
    int top = s.top();
    s.pop();
    delete_middle(s,mid-1);
    s.push(top);
}
int main()
{
    stack<int>s;
    s.push(2);
    s.push(1);
    s.push(5);
    s.push(6);
    s.push(4);
    //s.push(8);
    int mid = (s.size()/2);
    delete_middle(s, mid);
    while(!s.empty())
    {
        int top = s.top();
        s.pop();
        cout<<top<<" ";
    }   
    return 0;
}