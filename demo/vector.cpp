#include<bits/stdc++.h>
using namespace std;
     
int main()
{
    //declaration
    vector<int> v;

    vector<int> v1 = {4, 6, 7, 8};

    for (int i = 0; i < v1.size(); i++)
    {
        cout << v1[i] << " ";
    }
    cout << "Insertion" << endl;


    // insert
    v1.push_back(6);
    for (int i = 0; i < v1.size(); i++)
    {
        cout << v1[i] << " ";
    }


    cout << "Deletion" << endl;
    //delete from back
    v1.pop_back();
    for (int i = 0; i < v1.size(); i++)
    {
        cout << v1[i] << " ";
    }

    // Define fixed size vector;
    vector<int> v2(7);
    int n = 4;
    vector<int> v3(n);
    
    //initialize all values of a vector
    vector<int> v4(n, 0);
    vector<int> v5(n, -1);
    vector<int> v6(n, INT_MIN); // INT_MIN means smallest value that can be represented using int - 2^31 - 1
    vector<int> v7(n, INT_MAX); // INT_MAX means largest value that can be represented using int + 2^31 - 2
    
    for (int i = 0; i < n; i++)
    {
        v5[i] = 0;
    }

    // cout <<"size : "<< v5.size() << endl;
    // v5.push_back(15);
    // cout << "size : " << v5.size() << endl;
    // cout << "capacity : " << v5.capacity() << endl;

    //Sorting
    int arr[5] = {8, 6, 3, 2, 5};
    int len = 5;
    sort(arr, arr + 3);
    sort(arr, arr + len);
    //(inclusive, exclusive);

    // vector iterator
    // starting = v.begin();
    // ending = v.end();
    sort(v.begin(), v.end());
    sort(v.begin(), v.begin() + 4);

    //descending sort
    sort(v.begin(), v.end(), greater<int>());

    return 0;
}