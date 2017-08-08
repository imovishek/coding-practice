#include<bits/stdc++.h>
#define mx 5007
using namespace std;
vector<int> edge[mx];
int vis[mx];
int par[mx];
int lca = -1;
int bigflag = 0;
int parent[mx];
int dfs(int u, int ulti)
{
	vis[u] = 1;
	par[u]++;
	if(u==ulti){
		if(lca==-1 && par[u]==2) lca = u;
		bigflag = 1;
		return 0;
	}
	for(int i = 0; i<edge[u].size(); i++)
	{
		int v = edge[u][i];
		if(!vis[v]){
			dfs(v, ulti);
			if(bigflag) {
				if(lca==-1 && par[u]==2) lca = u;
				return 0;
			}
		}
	}
	par[u]--;
}
int dist[mx];
int dfs2(int u)
{
	vis[u] = 1;
	for(int i = 0; i<edge[u].size(); i++)
	{
		int v = edge[u][i];
		if(!vis[v]){
			dist[v] = dist[u] + 1;
			parent[v] = u;
			dfs2(v);
		}
	}
}

int main()
{
	ios :: sync_with_stdio(false);
	int n;
	while(cin >> n && n){
		for(int i = 0; i<n-1; i++)
		{
			int u, v;
			cin >> u >> v;
			edge[u].push_back(v);
			edge[v].push_back(u);
		}
		int m;
		cin >> m;
		memset(vis, 0, sizeof vis);
		memset(dist, 0, sizeof dist);
		dfs2(1);
		for(int i = 0; i<m; i++)
		{
			int u, v;
			cin >> u >> v;
			memset(vis, 0, sizeof vis);
			memset(par, 0, sizeof par);
			bigflag = 0;
			lca = -1;
			dfs(1, u);
			// for(int i = 1; i<=n; i++) cout << i << " " << par[i] << "*" << endl;
			memset(vis, 0, sizeof vis);
			bigflag = 0;
			dfs(1, v);
			int d = dist[u] + dist[v] - 2 * dist[lca];
			int p;
			if((d+1)/2 <= dist[u] - dist[lca]) p = u;
			else p = v;
			int x;
			for(int j = 0; j<(d+1)/2; j++)
			{
				x = p;
				p = parent[p];
			}
			if(d%2==1){
				cout << "The fleas jump forever between " << min(x, p) << " and " << max(x, p) << ".\n";				
			}
			else cout << "The fleas meet at " << p << ".\n";
		}

		for(int i = 1; i<=n; i++) edge[i].clear();
	}
	return 0;
}