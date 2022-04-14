//https://leetcode.com/problems/online-stock-span/

#include<bits/stdc++.h>
using namespace std;
     
int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    
    return 0;
}
class StockSpanner {
public:
    vector<int>stocks;
    stack<pair<int, int>>s;
    int i;
    StockSpanner() {
        i = 0;
    }
    
    int next(int price) {
        int ans = 0;
        i++;
        if(s.empty())
        {
            ans = i;
        }
        if(!s.empty() and s.top().first > price)
        {
            ans = i - s.top().second;
        }
        else if(!s.empty() and s.top().first <= price)
        {
            while(!s.empty() and s.top().first <= price)
                s.pop();
            
            if(s.empty())
            {
                ans = i;
            }
            else
            {
                ans = i - s.top().second;
            }
        }
        stocks.push_back(price);
        s.push({price, i});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */