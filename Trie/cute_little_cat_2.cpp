#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define loop(i, a, b) for (int i = a; i < b; i++)
#define rev_loop(i, a, b) for (int i = a; i > b; i--)
#define pb push_back
#define inf 1e18 + 5
#define endl "\n"

#define pll pair<ll, ll>
#define pii pair<int, int>
#define vi vector<int>
#define vl vector<ll>

struct trie{
	trie* arr[26];
};

struct trie* getNode()
{
	struct trie* temp = new trie;
	loop(i,0,26)
		temp -> arr[i] = NULL;
	return temp;
}

void insert(string s , struct trie*root)
{
	struct trie*temp = root;
	int n = s.length();
	loop(i,0,n)
	{
		int ind = s[i] - 'a';
		if(!temp -> arr[ind])
			temp -> arr[ind] = getNode();
		temp = temp -> arr[ind];
	}
}

bool check(struct trie*root , string&s , int n)
{
	struct trie*temp = root;
	loop(i,0,n)
	{
		int ind = s[i] - 'a';
		if(!temp -> arr[ind])
			return false;
		temp = temp -> arr[ind];
	}
	return true;
}

int main()
{
	vector<string>v;
	string s;
	getline(cin , s);
	s += " ";
	string str = "";
	int n1 = s.length();
	loop(i,0,n1)
	{
		if(s[i] == ' ')
			v.pb(str) , str = "";
		else
			str += s[i];
	}
	

	struct trie* root = getNode();
	int n = v.size();
	loop(i,0,n)
	{
		string s = v[i];
		int m = s.length();
		loop(i,0,m)
			insert(s.substr(i) , root);
	}

	int q;
	cin >> q;
	while(q--)
	{
		string s;
		cin >> s;
		int m = s.length();
		if(check(root , s , m))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}
