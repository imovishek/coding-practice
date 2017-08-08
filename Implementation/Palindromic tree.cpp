/*input
3
abacab
abccab
faultydogeuniversity
hasnopalindromeatall
abbacabbaccab
youmayexpectedstrongsamplesbutnow
*/

#include<bits/stdc++.h>
using namespace std;
struct eertree{
	struct Node{
		int st, length, suffixLink;
		long long cnt, lazy;
		int addEdge[26];
	};
	vector< Node > tree;
	vector< int > dp;
	string s;
	int ptr;
	int currNode;
	eertree(string s) : dp(s.length() + 5), s(s), tree(s.length() + 5){
		tree[1].length = -1;
		tree[1].suffixLink = 1;
		tree[2].length = 0;
		tree[2].suffixLink = 1;
		ptr = 2;
		currNode = 2;
		dp[0] = 1;
	} 
	void insert(int idx)
	{
		int tmp = currNode;
		int ch = s[idx] - 'a';
		while(1)
		{
			int pos = idx - tree[tmp].length - 1;
			if(pos>=0 && s[idx]==s[pos]){
				tree[tree[tmp].addEdge[ch]].cnt++;
				break;
			}
			tmp = tree[tmp].suffixLink;
		}
		if(tree[tmp].addEdge[ch] != 0)
		{
			currNode = tree[tmp].addEdge[ch];
			return;
		}
		ptr++;
		currNode = ptr;
		tree[tmp].addEdge[ch] = ptr;
		tree[ptr].length = tree[tmp].length + 2;
		tree[ptr].st = idx - tree[tmp].length - 1;
		tree[ptr].cnt = 1;
		tmp = tree[tmp].suffixLink;
		if(tree[ptr].length==1){
			tree[ptr].suffixLink = 2;
			return;
		}
		while(1)
		{
			int pos = idx - tree[tmp].length - 1;
			if(pos>=0 && s[pos]==s[idx]){
				tree[tree[tmp].addEdge[ch]].cnt++;
				break;
			}
			tmp = tree[tmp].suffixLink;
		}
		tree[ptr].suffixLink = tree[tmp].addEdge[ch];
	}
	void build_tree()
	{
		for(int i = 0; i<s.length(); i++){
			insert(i);
			tree[currNode].lazy++;
		}
	}
	void do_lazy()
	{
		for(int i = ptr; i>=3; i--)
		{
			tree[i].cnt = tree[i].lazy;
			tree[tree[i].suffixLink].lazy += tree[i].lazy;
			tree[i].lazy = 0;
		}
	}
};
long long dfs(eertree &x, eertree &y, int a, int b)
{
	long long ret = 0;
	for(int i = 0; i<26; i++)
	{
		if(x.tree[a].addEdge[i] && y.tree[b].addEdge[i]){
			ret += dfs(x, y, x.tree[a].addEdge[i], y.tree[b].addEdge[i]);
		}
	}
	ret += x.tree[a].cnt * 1ll * y.tree[b].cnt;
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t, tst = 1;
    cin >> t;
    while(t--)
    {
    	string a, b;
    	cin >> a >> b;
    	eertree x(a), y(b);
    	x.build_tree();
    	y.build_tree();
    	x.do_lazy();
    	y.do_lazy();
    	cout << "Case #" << tst++ << ": " << dfs(x, y, 1, 1) + dfs(x, y, 2, 2) << endl;
    }
	return 0;
}