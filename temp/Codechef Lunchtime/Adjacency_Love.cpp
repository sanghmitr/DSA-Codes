#include<bits/stdc++.h>
using namespace std;
     
int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>nums(n);
        int o = 0, e = 0;
        unordered_map<int, int>odds,evens;
        for(int i=0;i<n;i++)
        {
            cin>>nums[i];
            if(nums[i]%2)
            {
                odds[nums[i]]++;
                o++;
            }
            else
            {
                 evens[nums[i]]++;
                 e++;
            }
        }

        vector<int>ans;

        if(o%2 == 0)
        {
            for(auto p : odds)
            {
                int k = p.second;
                while(k--)
                {
                    ans.push_back(p.first);
                }
            }
            for(auto p : evens)
            {
                int k = p.second;
                while(k--)
                {
                    ans.push_back(p.first);
                }
            }
        }
        else
        {
            for(auto p : odds)
            {
                //cout<<p.first<<" "<<p.second<<endl;
                int key = p.first;
                while(ans.size() < o-1 and odds[key] > 0)
                {
                    ans.push_back(key);
                    odds[key]--;
                }
            }
            for(auto p : evens)
            {
                int k = p.second;
                while(k--)
                {
                    ans.push_back(p.first);
                }
            }

            for(auto p : odds)
            {
                //cout<<p.first<<" "<<p.second<<endl;
                int k = p.second;
                while(k--)
                {
                    ans.push_back(p.first);
                }
            }
        }

        int sum = 0;
        for(int i=0; i<n-1; i++)
        {
            sum += (ans[i]*ans[i+1]);
        }

        if(sum%2 != 0)
        {
            for(auto x : ans)
            {
                cout<<x<<" ";
            }
            cout<<endl;
        }
        else
            cout<<"-1"<<endl;  
        ans.clear();
    }
    return 0;
}