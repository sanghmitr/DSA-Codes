#include<bits/stdc++.h>
using namespace std;

class Node{
    public :
    char data;
    unordered_map<char, Node*>mp;
    int val;

    Node(char d){
        this->data = d;
        this->val = 1;
    }
};

class Trie{
    public :
        Node *root;
        Trie(){
            root = new Node('\0');
        }

    void insert(string word){
        Node *t = root;
        for(auto c : word){
            if(t->mp.count(c)){
                t = t->mp[c];
                t->val += 1;
            }
            else{
                Node *newNode = new Node(c);
                t->mp[c] = newNode;
                t = t->mp[c];
            }
        }
    }

    int score(string word){
        int ans = 0;
        Node *t = root;
        string s = "";
        for(auto c : word){
            t = t->mp[c];
            ans += t->val;
            // s += c;
            // cout << s << " : " << t->val << endl;
        }
        return ans;
    }
};

int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, len;
    cin >> n >> len;

    vector<string> v(n);
    Trie t;
    for (int i = 0; i < n; i++){
        cin >> v[i];
        t.insert(v[i]);
    }

    for (int i = 0; i < n; i++){
        cout <<"score of "<<v[i]<<" "<< t.score(v[i]) <<endl;
    }
    cout << endl;
    return 0;
}

/*

Testcases- 

2 3
aab
aac

output - 5 5


3 3
abd
bcd
abc

output - 5 3 5


*/