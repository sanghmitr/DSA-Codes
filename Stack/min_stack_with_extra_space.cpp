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
    stack<int>s, ss;
    MinStack() {
        
    }
    
    void push(int val) {
        s.push(val);
        if(ss.empty() or (!ss.empty() and ss.top() >= val))
            ss.push(val);        
    }
    
    void pop() {
        if(s.empty())
            return;
        else
        {
            if(s.top() == ss.top())
                ss.pop();
            s.pop();
        }
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        if(ss.empty())
            return -1;
        return ss.top();
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