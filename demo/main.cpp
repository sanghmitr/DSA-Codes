#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int sum(int arr[], int len){
    int ans = 0;

    for (int i = 0; i < len; i++)
    {
        ans += arr[i];
    }
    return ans;
}

int main()
{
    // cout << "Hello World" << endl
    //      << "Heloo"
    //      << "\n"
    //      << "Hello";

    // Datatypes
    int x = 2;       // 4 bytes
    float y = 2.2;   // 8 bytes
    double z = 6.77; // 16 bytes
    char c = 'a';
    string a = "Hello";
    bool flag = true;
    long g = 5656;
    return 0;

    int arr[6]; // fixed in size
    int arr1[] = {6, 3, 6, 3, 8};

    cout << sum(arr1, 5) << endl;
}
