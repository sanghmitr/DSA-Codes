#include<bits/stdc++.h>
using namespace std;

//Instead of using vector, use set for unique subsets

void subsets(string s, string op, set<string>& allsubSet)
{
    if(s.length() == 0)
    {
        allsubSet.insert(op);
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
    set<string>allSubset;
    subsets(s, op, allSubset);

    cout<<"Number of subsets = "<<allSubset.size()<<endl;
    for(auto sub : allSubset)
        cout<<sub<<", "; 
    return 0;
}