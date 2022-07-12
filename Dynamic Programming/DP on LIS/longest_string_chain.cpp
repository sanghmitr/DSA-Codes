//

#include<bits/stdc++.h>
using namespace std;

bool compare(string &a, string &b){
    int n = a.length();
    int m = b.length();
    if(n != m+1) return false; 

    int i = 0, j=0;
    while(i<n){
        if(a[i] == b[j]){
            i++, j++;
        }
        else{
            i++;
        }
    }
    if(i == n and j == m) return true;
    return false;
}
// O(N*N*L) where N = number of words, L = length of the largest individual string
int longestStrChain(vector<string>& words) {
    int n = words.size();
    sort(words.begin(), words.end(), [](string &a, string &b){
        return a.size() < b.size();
    });
    
    vector<int>dp(n, 1);
    int len = 1;
    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            if(compare(words[i], words[j])){
                //cout<<words[j]<<" "<<words[i]<<endl;
                dp[i] = max(dp[i], 1+dp[j]);
            }
        }
        len = max(len, dp[i]);
    }
    return len;
}

int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    
    return 0;
}