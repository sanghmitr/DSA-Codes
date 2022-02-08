#include<bits/stdc++.h>
using namespace std;

void insert(stack<int>&s, int ele)
{
    if(s.size() == 0)
    {
        s.push(ele);
        return;
    }
    int temp = s.top();
    s.pop();
    insert(s, ele);
    s.push(temp);
}

void reverseStack(stack<int>&s)
{
    if(s.empty())
        return;
    int top = s.top();
    s.pop();
    reverseStack(s);
    insert(s, top);
}
int main()
{
    stack<int>s;
    s.push(5);
    s.push(3);
    s.push(4);
    s.push(1);
    s.push(2);
    reverseStack(s);

    while(!s.empty())
    {
        int num = s.top();
        cout<<num<<" ";
        s.pop();
    }
    return 0;
}