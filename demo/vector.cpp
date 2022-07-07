#include<bits/stdc++.h>
using namespace std;


class Node{
    int data;
    Node *next;
};

static bool compare(char a, char b){
    if(a > b)
        return true;
    return false;
}

bool compare1(int a, int b)
{
    return a > b;
}

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

    //To insert data by user using cin >>
    vector<int>v10;
    int k = 10;
    for (int i = 0; i < k; i++)
    {
        int temp;
        cin >> temp;
        v10.push_back(temp);
    }

    //Another way to insert from user
    int a = 5;
    vector<int> v9(a);
    for (int i = 0; i < a; i++)
    {
        cin >> v9[i];
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
    vector<int> v6(n, INT_MIN); // INT_MIN means smallest value that can be represented using int -2^31 
    vector<int> v7(n, INT_MAX); // INT_MAX means largest value that can be represented using int +2^31 - 1
    
    for (int i = 0; i < n; i++)
    {
        v5[i] = 0;
    }

    // cout <<"size : "<< v5.size() << endl;
    // v5.push_back(15);
    // cout << "size : " << v5.size() << endl; // Size means number of elements present in the vector at this time.
    // cout << "capacity : " << v5.capacity() << endl;  //Capacity means actual memory blocks allocated to that vector at this time.

    //Sorting - Array
    int arr[5] = {8, 6, 3, 2, 5};
    int len = 5;
    sort(arr, arr + 3);
    sort(arr, arr + len);
    /*
    
    items = 8    6    3    2   5
    loc =  200  202  204  206  208  210
    
    arr + len = 200 + 5*2 = 210
    */
    //(inclusive, exclusive);

    // vector iterator
    // starting = v.begin();
    // ending = v.end();
    sort(v.begin(), v.end()); // Sort in ascending order
    sort(v.begin(), v.begin() + 4);

    //descending sort
    sort(v.begin(), v.end(), greater<int>()); // Third parameter is comparator method.

    //Custom sort using comparators
    vector<char> name = {'c', 'f', 'a' , 'c', 'z'};
    sort(name.begin(), name.end(), compare); // Sorting time complexity O(nlogn)
    // Sort method internally uses Quicksort


    vector<Node*> linkedList;

    // Find minimum of whole array.. vector ka sabse minimum ya maximum element;
    vector<int> v11 = {6, 1, 6, 9, 2, 0};
    int mn = INT_MAX;
    int mx = INT_MIN;

    for (int i = 0; i < v11.size(); i++)
    {
        mn = min(mn, v11[i]);
        mx = max(mx, v11[i]);
    }
    
    for(auto x : v11)
    {
        mn = min(mn, x);
        mx = max(mx, x);
    }

    cout << "Min - " << mn << " Max - " << mx<<endl;
    return 0;
}

/*

Time complexity

O(1) < O(logn) < O(n) < O(nlogn) < O(n^2) < O(n^3) < O(2^n) < O(n^n) = O(n!)

*/
