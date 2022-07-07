#include<bits/stdc++.h>
using namespace std;

bool compare(vector<int>a, vector<int>b)
{
    int size1 = a.size();
    int size2 = b.size();

    return size1 > size2;
}

int main()
{ 
    // Declare a 2D vector
    vector<vector<int>> v;

    // Completely dynamic sized 2-d vector
    // Insert values in 2-D vector; 
    // Input coming from user
    int r = 4;
    for (int i = 0; i < r; i++)
    {
        int m;
        cin >> m;
        vector<int> temp;
        for (int j = 0; j < m; j++)
        {
            int x;
            cin >> x;
            temp.push_back(x);
        }
        v.push_back(temp);
    }

    // Fixed size
    int r = 4, c = 3;
    for (int i = 0; i < r; i++)
    {
        vector<int> temp;
        for (int j = 0; j < c; j++) // This loop creates a row(vector) for us
        {
            int x;
            cin >> x;
            temp.push_back(x);
        }
        v.push_back(temp);
    }

    // Allocate memory at the declaration time; // Fixed size vector
    int n = 3, m = 2; // N means rows, M means columns
    vector<vector<int>> v1(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> v1[i][j];
        }
    }

    sort(v1.begin(), v1.end(), compare);
    return 0;
}