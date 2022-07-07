#include<bits/stdc++.h>
using namespace std;

bool compare(char a, char b){
    if(a > b)
        return true;
    return false;
}

int main()
{
    // Define a string;
    string s;

    //Initialise and declare string
    string s1 = "hello";
    cout << s1 << endl;
    // Null character '\0' present in the character array and string;


    //String length
    int len = s1.length();
    cout << "Length is : " << len << endl;


    // Sort a string
    sort(s1.begin(), s1.end());
    cout << s1 << endl;

    // Sort in descending order;
    sort(s1.begin(), s1.end(), compare);
    cout << s1 << endl;

    vector<string> v2;
    v2.push_back("Sanghmitr");
    v2.push_back("Nivedita");
    v2.push_back("Vatsala");

    //Iterate vector of strings directly
    for (int i = 0; i < v2.size(); i++)
    {
        cout << v2[i] <<" "<<v2[i].length()<< endl; // Length() method does not count null character
        cout << endl;
    }

    // Iterate string character by character
    for (int i = 0; i < v2.size(); i++)
    {
        for (int j = 0; j < v2[i].length(); j++)
        {
            cout << v2[i][j];
        }
        cout << endl;
    }

    // For each loop;
    vector<int> v3 = {5, 6, 7, 8};
    for(int x : v3)
    {
        cout << x << " ";
    }
    for(string x : v2){
        cout << x << endl;
    }

    // Auto keyword;
    for(auto x : v2){
        cout << x << endl;
    }
    
    return 0;
}