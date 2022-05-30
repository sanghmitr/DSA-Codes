//https://practice.geeksforgeeks.org/problems/the-celebrity-problem

#include<bits/stdc++.h>
using namespace std;
     
int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    
    return 0;
}

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat, int n) 
    {
        stack<int>s;
        for(int i = 0; i<n; i++)
            s.push(i);
        
        while(s.size() > 1)
        {
            int a = s.top(); s.pop();
            int b = s.top(); s.pop();
            
            if(mat[a][b] == 1)
                s.push(b);
            else
                s.push(a);
        }
        
        int ans = s.top();
        bool colCheck = false, rowCheck = false;
        int zeros = 0, ones = 0;
        //Check Column of candidate celebrity
        for(int i=0; i<n; i++)
        {
            if(mat[i][ans] == 1)
                ones++;
        }
        if(ones == n-1)
            colCheck = true;
        //Check row of candidate celebrity
        for(int i=0; i<n; i++)
        {
            if(mat[ans][i] == 0)
                zeros++;
        }
        if(zeros == n)
            rowCheck = true;
            
        if(rowCheck and colCheck)
            return ans;
       
        return -1;
    }
};