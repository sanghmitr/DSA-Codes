#include<bits/stdc++.h>
using namespace std;

int kthGrammar(int n, int k) {
        if(n ==1 and k == 1)
            return 0;
        int mid = (pow(2, n-1))/2;
        if(k <= mid)
            return kthGrammar(n-1, k);
        else
            return !kthGrammar(n-1, k-mid);
}    
int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n,k;
    cin>>n>>k;
    cout<<kthGrammar(n,k)<<endl;
    return 0;
}