/*input
3 2
McBride, John
Smith, Peter
Brown, Anna
Brown, Anna
Smith, Peter
Smith, Peter
Brown, Anna
3 2
McBride, John
Smith, Peter
Brown, Anna
Brown, Anna
Smith, Peter
McBride, John
Smith, Peter
0 0
*/

#include <bits/stdc++.h>
using namespace std;

#define mx 100005
#define ll long long
#define MOD 1000000007
#define fs first
#define sc second

vector<int> edge[mx], cur;
int cnt, low[mx], st[mx], vis[mx], T = 1;

int dfs(int u)
{
	if(vis[u]) return 0;
	vis[u] = 1;
	st[u] = low[u] = T++;
	cur.push_back(u);
	for(int v : edge[u])
	{
		if(vis[v]==0){
			dfs(v);
			low[u] = min(low[u], low[v]);
		} else if(vis[v]==1){
			low[u] = min(low[u], low[v]);
		}
	}
	if(st[u]==low[u]) {
		int v;
		do{
			v = cur.back();
			cur.pop_back();
			vis[v] = 2;
		}while(v != u);
		cnt++;
	}
}
int main()
{
	int p, t;
	while(scanf("%d %d", &p, &t)){
		if(p==t && p==0) return 0;
		map<pair<string, string>, int> mp;
		for(int i = 1; i<=p; i++)
		{
			string a, b;
			cin >> a >> b;
			mp[{a, b}] = i;
		}
		for(int i = 1; i<=p; i++) edge[i].clear();
		for(int i = 0; i<t; i++)
		{
			string a, b, x, y;
			cin >> a >> b >> x >> y;
			int u = mp[{a, b}], v = mp[{x, y}];
			edge[u].push_back(v);
		}
		cnt = 0, T = 1;
		memset(vis, 0, sizeof vis);
		for(int i = 1; i<=p; i++){
			if(!vis[i]){
				dfs(i);
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}
