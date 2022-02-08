#include<bits/stdc++.h>
using namespace std;

//Print all subsequences, all subsets, both codes are same

void subsequences(string s, string op)
{
    if(s.length() == 0)
    {
        cout<<op<<", ";
        return;
    }
    string op1 = op;
    string op2 = op;
    op2.push_back(s[0]);
    s.erase(s.begin()+0);
    subsequences(s, op1);
    subsequences(s, op2);
}     
int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string s;
    cin>>s;
    string op = "";
    subsequences(s, op);
    return 0;
}