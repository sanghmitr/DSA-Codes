//Print N-bit binary numbers having more 1’s than 0’s for any prefix

#include<bits/stdc++.h>
using namespace std;

void gen_binary_string(int n, int ones, int zeros, string op, vector<string>&result)
{
    if(n == 0)
    {
        result.push_back(op);
        return;
    }

    string op1 = op;
    op1.push_back('1');
    gen_binary_string(n-1, ones+1, zeros, op1, result);
    if(ones > zeros)
    {
        string op2 = op;
        op2.push_back('0');
        gen_binary_string(n-1, ones, zeros+1, op2, result);
    }
}
int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin>>n;
    int ones = 0;
    int zeros = 0;
    string op = "";
    vector<string>result;
    gen_binary_string(n, ones, zeros, op, result);
    for(auto s : result)
        cout<<s<<", ";

    return 0;
}