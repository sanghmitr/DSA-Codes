//https://leetcode.com/problems/n-queens


class Solution {
public:
    //We need to check only three directions out of 8, becasue only left columns can have queen at that time.
    bool isSafe(int row, int col, vector<string>board, int n){
        //check left upper diagonal
        int duprow = row;
        int dupcol = col;
        
        while(row >=0 and col >= 0){
            if(board[row][col] == 'Q') return false;
            row-- , col--;
        }
        
        col = dupcol, row = duprow;
        //Check on the same row;
        while(col >= 0){
            if(board[row][col] == 'Q') return false;
            col--;
        }
        
        //check left downward diagonal
        col = dupcol, row = duprow;
        while(row < n and col >=0){
            if(board[row][col] == 'Q') return false;
            row++, col--;
        }
        
        return true;
    }
    //solve will select one column at a time and look in which row we can place a queen
    void solve(int col, vector<string>&board, vector<vector<string>>&ans, int n){
        if(col == n){
            ans.push_back(board);
            return;
        }
        
        for(int row = 0; row<n; row++){
            if(isSafe(row, col, board, n)){
                board[row][col] = 'Q';
                solve(col+1, board, ans, n);
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n);
        
        //Fill complete board with '.'
        string s(n, '.');
        for(int i=0; i<n; i++){
            board[i] = s;
        }
        
        solve(0, board, ans, n);
        return ans;
    }
};

#include<bits/stdc++.h>
using namespace std;
     
int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    
    return 0;
}