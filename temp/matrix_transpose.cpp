//https://atcoder.jp/contests/abc237/tasks/abc237_b

#include<bits/stdc++.h>
using namespace std;
     
int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int h,w;
    cin>>h>>w;
    vector<vector<int>>mat(h, vector<int>(w));

    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
            cin>>mat[i][j];
    }

    vector<vector<int>>v(w, vector<int>(h));
    for(int i=0;i<w;i++)
    {
        for(int j=0;j<h;j++)
        {
            v[i][j] = mat[j][i];
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}