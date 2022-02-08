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
    //Append only first letter of input to the output
    op1.push_back(s[0]);

    //Append first letter along with space to the output
    op2.push_back(' ');
    op2.push_back(s[0]);
    
    s.erase(s.begin()+0);
    //Call recursively without appending space between the output symbol
    permuteSpaces(s, op1);
    //Call rescursively with appending space between the output symbols
    permuteSpaces(s, op2);
}     
int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string s;
    cin>>s;
    string op = "";
    op.push_back(s[0]);
    s.erase(s.begin()+0);
    permuteSpaces(s, op);
    return 0;
}