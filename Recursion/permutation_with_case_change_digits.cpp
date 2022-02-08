//print all permutations of the string which contains digits and letters in any case i.e. (either lowercase or uppercase)
// example Input = a1B2
// example Output = a1B2, A1B2, a1b2, A1b2

#include<bits/stdc++.h>
using namespace std;

void print_permutation(string s, string op)
{
    if(s.length() == 0)
    {
        cout<<op<<", ";
        return;
    }

    if(isalpha(s[0]))
    {
        string op1 = op;
        string op2 = op;
        op1.push_back(tolower(s[0]));
        op2.push_back(toupper(s[0]));
        s.erase(s.begin() + 0);
        print_permutation(s, op1);
        print_permutation(s, op2);
    }
    else
    {
        string op1 = op;
        op1.push_back(s[0]);
        s.erase(s.begin() + 0);
        print_permutation(s, op1);
    }
}

int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string s;
    cin>>s;

    string op = "";
    print_permutation(s, op);
    return 0;
}