//https://leetcode.com/problems/min-stack

#include<bits/stdc++.h>
using namespace std;
     
int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    
    return 0;
}
class MinStack {
public:
    stack<long>s;
    int mn;
    MinStack() {
        mn = 0;
    }
    
    void push(int val) {
        if(s.empty())
        {
            s.push(val);
            mn = val;
        }
        else
        {
            if(val >= mn)
                s.push(val);
            else
            {
                s.push((long)2*val - (long)mn);
                mn = val;
            }    
        }
    }
    
    void pop() {
        if(s.empty())
            return;
        else
        {
            if(s.top() > mn)
                s.pop();
            else
            {
                mn = (long)2*mn -(long)s.top();
                s.pop();
            }
        }
    }
    
    int top() {
        if(s.empty())
            return -1;
        else
        {
            if(s.top() > mn)
                return s.top();
            else
            {
                return mn;
            }
        }
    }
    
    int getMin() {
        if(s.empty())
           return -1;
        return mn;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */