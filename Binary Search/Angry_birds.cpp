/*
There is a long wire along a straight line, which contains N bird nests at positions x1, x2, ... xN

There are B (B < N) birds, which become angry towards each other once put into a nest. 
To put the birds from hurting each other you want to assign birds to nests such that minimum distance 
between any two birds is as large as the possible. What is the largest minimum distance? 

Input

N = 5 nests
B = 3 Birds
Nests = [1,2,4,8,9]

output 
3

*/

#include<bits/stdc++.h>
using namespace std;

bool canPlaceBirds(int B, int N, vector<int>&nests, int sep)
{
    int birds = 1;
    int location = nests[0];

    for(int i=1; i<N; i++)
    {
        int cur_location = nests[i];
        if(cur_location - location >= sep)
        {
            birds++;
            location = cur_location;

            if(birds == B)
                return true;
        }
    }
    return false;
}
int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int B = 3;
    vector<int>nests{1,2,4,8,9};
    int N = nests.size();
    sort(nests.begin(), nests.end());

    // Binary Search
    int s = 0, e = nests[N-1] - nests[0];
    int ans = -1;
    while(s <= e)
    {
        int mid = s + (e-s)/2;
        
        bool canPlace = canPlaceBirds(B, N, nests, mid);
        if(canPlace)
        {
            ans = mid;
            s = mid + 1;
        }
        else{
            e = mid - 1;
        }
    }
    cout<<ans<<endl;
    return 0;
}