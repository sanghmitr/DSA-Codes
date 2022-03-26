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

class SuffTrie
{
    public:
    Node *root;
    SuffTrie()
    {
        root = new Node('\0');
    }
    bool search(string word)
    {
        Node *temp = root;
        for(char ch : word)
        {
            if(temp->m.count(ch) == 0)
                return false;
            temp = temp->m[ch];
        }
        return temp->isTerminal;
    }

    void insert(string word)
    {
        // pick all substrings from (i, end of string) and insert_helper
        for(int i=0;i<word[i] != '\0'; i++)
        {
            insert_helper(word.substr(i));
        }
    }

    void insert_helper(string word)
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

int main()
{
    SuffTrie t;
    string input = "hello";
    string suffixes[] = {"lo", "ell", "hello"};

    t.insert(input);
    for(auto s : suffixes)
    {
        cout<<s<<" : ";
        if(t.search(s))
            cout<<"Found"<<endl;
        else
            cout<<"Not found"<<endl;
    }

    return 0;
}