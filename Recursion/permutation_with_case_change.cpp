#include<bits/stdc++.h>
using namespace std;

void permuteSpaces(string s, string op)
{
    if(s.length() == 0)
    {
        cout<<op<<", ";
        return;
    }
    string op1 = op;
    string op2 = op; 

    op1.push_back(toupper(s[0]));

    op2.push_back(s[0]);
    
    s.erase(s.begin()+0);

    permuteSpaces(s, op1);

    permuteSpaces(s, op2);
}     
int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    //Always take lowercase input string
    string s;
    cin>>s;
    string op = "";

    permuteSpaces(s, op);
    return 0;
}