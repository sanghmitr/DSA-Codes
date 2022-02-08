#include<bits/stdc++.h>
using namespace std;

void subsets(string s, string op, vector<string>& allsubSet)
{
    if(s.length() == 0)
    {
        allsubSet.push_back(op);
        return;
    }
    
    string op1 = op;
    string op2 = op;
    op2.push_back(s[0]);
    s.erase(s.begin()+0);
    subsets(s, op1, allsubSet);
    subsets(s, op2, allsubSet);
        
}     
int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string s;
    cin>>s;
    string op = "";
    vector<string>allSubset;
    subsets(s, op, allSubset);

    for(auto sub : allSubset)
        cout<<sub<<" "; 
    return 0;
}