#include<bits/stdc++.h>
using namespace std;

class MaxHeap
{
    public:
    vector<int>v;
    void push(int num)
    {
        v.push_back(num);
        int n = v.size();
        int i = n-1;
        while(i > 0)
        {
            int parent = i/2;
            if(v[parent] < v[i])
                swap(v[parent], v[i]);
            else
                return;
        }
    }

    void pop()
    {
        cout<<"max popped : "<<v[0]<<endl;
        int n = v.size();
        //Copy the last element to first location
        v[0] = v[n-1];
        v.resize(v.size()-1);
        int i = 0;
        while(i < v.size())
        {
            int left = v[2*i];
            int right = v[(2*i)+1];
            int larger = left > right ? left : right;
            if(v[i] < v[larger])
                swap(v[larger], v[i]);
            else
                return;
        }
    }

    void printHeap()
    {
        int x = 0;
        for(int i=0;i<v.size();i++)
        {
            if(i-1 == x)
            {
                x++;
                x *= 2;
                cout<<endl;
            }
            cout<<v[i]<<" ";
        }
    }
};

int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    vector<int>v = {5,2,7,8,2,9,10};

    MaxHeap h;
    for(int i=0;i<v.size();i++)
    {
        h.push(v[i]);
    }

    h.printHeap();
    // h.pop();
    // h.printHeap();
    // h.pop();
    // h.printHeap();
    return 0;
}