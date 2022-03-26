// From udemy dsa prateek narang course

/*

Little cute cat loves to writes stories in a github readme document. One day she is given a list of words, 
you want to help her to check if each of these words are present in the readme file.

Sample Input-
document = "little cute cat loves to code in c++, java & python"
words = ["cute cat", "ttle", "cutest", "cat", "quick", "big"]

Sample output-
YES
YES
NO
YES
NO
NO

*/

#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
     char data;
     unordered_map<char, Node*>m;
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
        for(char ch : word)
        {
            if(temp->m.count(ch) == 0)
            {
                Node *n = new Node(ch);
                temp->m[ch] = n;
            }
            temp = temp->m[ch];
        }
        temp->isTerminal = true;
    }
};

void searchHelper(Trie t, string document, int i, unordered_map<string, bool>&mp)
{
    Node *temp = t.root;
    for(int j=i; j<document.length(); j++)
    {
        char ch = document[j];
        if(temp->m.count(ch) == 0)
        {
            return;
        }

        temp = temp->m[ch];
        if(temp->isTerminal)
        {
            string out = document.substr(i, j-i+1);
            mp[out] = true;
        }
    }
    return;
}
void documentSearch(string document, vector<string>&words)
{
    Trie t;
    // 1. Create a trie of words
    for(auto w : words)
    {
        t.insert(w);
    }

    //2. Searching (helper function will be called)
    unordered_map<string, bool>mp;
    for(int i=0; i<document.length() ; i++)
    {
        searchHelper(t, document, i, mp);
    }

    //3. Print result 
    for(auto w : words)
    {
        if(mp[w])
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }    
    return;
}

int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    

    //string document = "little cute cat loves to code in c++, java & python";
    //vector<string>words = {"cute cat", "ttle", "cutest", "cat", "quick", "big"};

    string document;
    getline(cin, document);

    int n;
    cin>>n;
    cin.ignore();

    vector<string>words(n);

    for(int i=0;i<n;i++)
    {
        getline(cin, words[i]);
    }

    // for(auto s : words)
    //     cout<<s<<" , ";
    // cout<<endl;
    documentSearch(document, words);
    return 0;
}