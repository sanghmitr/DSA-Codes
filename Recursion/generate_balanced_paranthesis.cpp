#include<bits/stdc++.h>
using namespace std;

void gen_balance_paranthesis(int open, int close, string op, vector<string>&result)
{
    if(open == 0 and close == 0)
    {
        result.push_back(op);
        return;
    }

    if(open > 0)
    {
        string op1 = op;
        op1.push_back('(');
        gen_balance_paranthesis(open-1, close, op1, result);
    }
    if(open < close)
    {
        string op2 = op;
        op2.push_back(')');
        gen_balance_paranthesis(open, close-1, op2, result);
    }
}     
int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin>>n;
    int open = n;
    int close = n;
    string op = "";
    vector<string>result;
    gen_balance_paranthesis(open, close, op, result);

    cout<<"Total No.  of balance paranthesis possible : "<<result.size()<<endl;
    for(auto s : result)
        cout<<s<<", ";
    return 0;
}