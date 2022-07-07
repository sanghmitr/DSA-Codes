class Solution {
public:
    //vector<long long>dp;
    bool flag = false;
    void findcombinations(vector<long long>&v, int index, long long num, long long reducednum, unordered_set<long long>&s)
    {
        if(reducednum < 0)
            return;
        
        if(reducednum == 0 and !flag)
        {
            unordered_set<long long>temp;
            for(int i=0;i<index;i++)
            {
                //cout<<v[i]<<" ";
                temp.insert(v[i]);
            }
            //cout<<endl;
            if(temp.size() > s.size())
                s = temp;
            flag = true;
            return;
        }
    
        int prev = (index == 0)? 0 : v[index-1];
        
        for(int i=prev+2;i<=num;i+=2)
        {
            v[index] = i;
            findcombinations(v, index+1, num, reducednum - i, s);
        }
    }
    vector<long long> maximumEvenSplit(long long finalSum) {
        if(finalSum%2 == 1)
            return {};
        
        unordered_set<long long>s;
        //dp.resize(finalSum, -1);
        vector<long long>v(finalSum);
        findcombinations(v, 0, finalSum, finalSum, s);
        vector<long long>ans;
        for(auto x : s)
            ans.push_back(x);
        
        return ans;
    }
};