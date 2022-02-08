#include<iostream>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;
void insertToStack(stack<int>&s, int num)
{
    if(s.size() == 0 or s.top() <= num)
    {
        s.push(num);
        return;
    }
    int val = s.top();
    s.pop();
    insertToStack(s, num);
    s.push(val);
}
void sortStack(stack<int>&s)
{
    if(s.size() == 1)
        return;
    int top = s.top();
    s.pop();
    sortStack(s);
    insertToStack(s, top);
}

int main()
{
    stack<int>s;
    s.push(2);
    s.push(1);
    s.push(5);
    s.push(6);
    s.push(4);

    sortStack(s);
    while(!s.empty())
    {
        int top = s.top();
        s.pop();
        cout<<top<<" ";
    }   
    return 0;
}