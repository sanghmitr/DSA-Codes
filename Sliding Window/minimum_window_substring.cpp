//https://leetcode.com/problems/minimum-window-substring

#include<bits/stdc++.h>
using namespace std;
     
int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    
    return 0;
}
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> Tf;
        unordered_map<char,int> Sf;
        
        int len=INT_MAX;
        string result;
        for(char &ch:t)Tf[ch]++;
        int i=0,j=0,count=0;
        
        for(int j = 0;j<s.length();j++)
        {
            char ch=s[j];
            if(Tf.find(ch)!=Tf.end())
            {
                Sf[ch]++;
                if(Sf[ch]<=Tf[ch])
                    count++;
            }
            
            if(count>=t.length())
            {
                while(Tf.find(s[i])==Tf.end()||Sf[s[i]]>Tf[s[i]])
                {
                    Sf[s[i]]--;
                    i++;
                }
                if(j-i+1<len)
                {
                    len=j-i+1;
                    result=s.substr(i,len);
                }
            }
        }
        return result;
    }
};