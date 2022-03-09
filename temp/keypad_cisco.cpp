#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'keypadDecode' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. INTEGER N
 *  2. STRING keypad
 */

string keypadDecode(int N, string keypad) {
    vector<vector<char>>v;
    v.push_back({' ','0'});
    v.push_back({',' , '@'});
    v.push_back({'A','B','C','a','b','c','2'});
    v.push_back({'D','E','F','d','e','f','3'});
    v.push_back({'G','H','I','g','h','i','4'});
    v.push_back({'J','K','L','j','k','l','5'});
    v.push_back({'M','N','O','m','n','o','6'});
    v.push_back({'P','Q','R','S','p','q','r','s','7'});
    v.push_back({'T','U','V','t','u','v','8'});
    v.push_back({'W','X','Y','Z','w','x','y','z','9'});
    
    cout<<keypad<<endl;
    int n = keypad.length();
    string ans = "";
    int cnt = 1;
    //cout<<keypad.length();
    for(int i=0;i<keypad.length()-1;i++)
    {
        //cout<<keypad[i]<<" ";
        if(keypad[i] == keypad[i+1])
            cnt++;
        else if(keypad[i] == '_')
        {
            cnt = 1;
        }
        else
        {
            int idx = keypad[i] - '0';
            int len = v[idx].size();
            char c = v[idx][(cnt%len)-1];
            ans.push_back(c);
            cnt = 1; 
        }
    }
    int idx = keypad[n-1] - '0';
    int len = v[idx].size();
    char c = v[idx][(cnt%len)-1];
    ans.push_back(c);
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string N_temp;
    getline(cin, N_temp);

    int N = stoi(ltrim(rtrim(N_temp)));
    
    for(int i=0;i<N;i++)
    {
        string keypad;
        getline(cin, keypad);

        string result = keypadDecode(N, keypad);

        fout << result << "\n";
    }
    
    fout.close();
    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
