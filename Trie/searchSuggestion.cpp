// https://leetcode.com/problems/search-suggestions-system/

#include<bits/stdc++.h>
using namespace std;
     
int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    
    return 0;
}


// Using Trie
    /*
        TC: Sorting + Trie Creation + Trie Query
        TC: O(m*nlogn + m*n + L^2), L: length of word to find, m: length of longest word,
                                        n: No. of words
                                        
        We create a Trie where for each of the nodes we also save the suggestions for that char.
        In order to give 3 lexographically sorted suggestions, we sort the array before hand and then 
        insert the words in that order in Trie so that the suggestions gets filled with releveant words.
        
    */
    struct Trie {
        unordered_map<char, Trie*> leaves;
        // Lexographically sorted suggestion till each char 
        vector<string> suggestions;
    };
    
    void insertTrie(Trie* root, string word) {
        for(const char& c: word) {
            if(root->leaves.find(c) == root->leaves.end())
                root->leaves[c] = new Trie();
            root = root->leaves[c];
            
            // Add the current word as suggestion if we dont have enough suggestions
            if(root->suggestions.size() < 3)
                root->suggestions.emplace_back(word);
        }
    }
    
    
class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> result(searchWord.size());
        // sort the words 
        sort(begin(products), end(products));
        // Create the Trie, since the words are sorted
        // so the suggestions are also lexographically sorted
        Trie *root = new Trie();
        for(const string &word: products)
            insertTrie(root, word);
        
        string prefix;
        for(int i = 0; i < searchWord.size(); i++) {
            auto it = root->leaves.find(searchWord[i]);
            if(it != root->leaves.end()) {
                root = it->second;
            }
            else
                break;
            // add suggestions if any for the current char
            result[i] = root->suggestions;
        }
        return result;
    }
};