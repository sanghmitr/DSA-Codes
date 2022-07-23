#include <bits/stdc++.h>
using namespace std;

int cnt;
class Node
{
public:
    char data;
    unordered_map<char, Node *> m;
    bool isTerminal;

    Node(char d)
    {
        data = d;
        isTerminal = false;
    }
};

class Trie
{
public:
    Node *root;
    Trie()
    {
        root = new Node('\0');
    }

    void insert(string word)
    {
        Node *temp = root;
        for (char ch : word)
        {
            if (temp->m.count(ch) == 0)
            {
                cnt++;
                Node *n = new Node(ch);
                temp->m[ch] = n;
            }
            temp = temp->m[ch];
        }
        temp->isTerminal = true;
    }

    bool search(string word)
    {
        Node *temp = root;
        for (char ch : word)
        {
            if (temp->m.count(ch) == 0)
                return false;
            temp = temp->m[ch];
        }
        return temp->isTerminal;
    }
};


int main()
{
    Trie t;

    vector<string> v;

    for (int i = 0; i < 4; i++){
        string s;
        cin >> s;
        sort(s.begin(), s.end());
        v.push_back(s);
    }

    cnt = 1;
    for(auto s : v){
        t.insert(s);
    }

    cout << cnt << endl;
    return 0;
}

/*

testcase -

ab
ac
ad
ae

output = 6

rlrliy
rrrlihipqhl
ryplihypp
lytli

output = 21

*/