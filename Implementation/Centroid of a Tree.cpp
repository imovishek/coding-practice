/*input
10 3
10 7
10 6
1 4
7 8
5 1
6 2
7 5
6 3
7 9
2 9
2 8
2 2

*/

#include <bits/stdc++.h>
using namespace std;

#define mx 100005
#define ll long long
#define MOD 1000000007
vector<int> edge[mx];
int vis[mx], par[mx], sz[mx], sp_table[mx][23];
int dist[mx];
int ans[mx];
void dfs0(int u, int p)
{
	sz[u] = 1;
	for(int v : edge[u])
	{
		if(v == p || vis[v]) continue;
		dfs0(v, u);
		sz[u] += sz[v];
	}
}
void go(int u, int p)
{
	sz[u] = 1;
	for(int v : edge[u])
	{
		if(v == p) continue;
		sp_table[v][0] = u;
		dist[v] = dist[u] + 1;
		go(v, u);
		sz[u] += sz[v];
	}
}
int dfs(int u, int p, int tot)
{
	int f = 0, then;
	for(int v : edge[u])
	{
		if(v == p || vis[v]) continue;
		if(sz[v] > tot/2) {f = 1; then = v; break;}
	}
	if(f){
		return dfs(then, u, tot);
	}
	return u;
}
int find_centroid(int u, int p)
{
	// cout << "center of " << u << " " << p << endl; 
	dfs0(u, p);
	int x = dfs(u, p, sz[u]);
	// cout << "is " << x << endl;
	return x;
}
int build_tree(int u, int p)
{
	int center = find_centroid(u, p);
	vis[center] = 1;
	par[center] = p;
	// cout << "hi" << endl;
	// cout << center << " " << p << endl;
	for(int v : edge[center])
	{
		// cout << center << " - " << v << endl;
		if(v == p || vis[v]) continue;
		else{
			build_tree(v, center);
		}
	}
}

void preprocess()
{
	memset(sp_table, -1, sizeof sp_table);
	go(1, -1);
	for(int j = 1; j<22; j++)
	{
		for(int i = 1; i<mx; i++)
			if(sp_table[i][j-1] != -1)
				sp_table[i][j] = sp_table[ sp_table[i][j-1] ][j-1];
	}
}
int lca(int u, int v)
{
	if(dist[u] > dist[v]) swap(u, v);
	int d = dist[v] - dist[u];
	for(int i = 21; i>=0; i--){
		if(d&(1<<i)){
			v = sp_table[v][i];
		}
	}
	if(u==v) return u;
	for(int i = 21; i>=0; i--){
		if(sp_table[u][i] != sp_table[v][i])
		{
			u = sp_table[u][i];
			v = sp_table[v][i];
		}
	}
	return sp_table[u][0];
}
int distance(int u, int v)
{
	return dist[u] + dist[v] - 2 * dist[lca(u, v)];
}
void update(int u, int idx)
{
	if(u==-1) return;
	ans[u] = min(ans[u], distance(u, idx));
	// cout << u << " " << ans[u] << ", ";
	update(par[u], idx);
}
int query(int u, int idx)
{
	if(u==-1) return MOD;
	int ret = ans[u] + distance(u, idx);
	return min(ret, query(par[u], idx));
}
int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i<n-1; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	preprocess();
	// cout <<  "** " << distance(1, 7) << endl;
	build_tree(1, -1);
	// cout << find_centroid(1, -1) << endl;
	for(int i = 1; i<=n; i++) ans[i] = MOD;
	update(1, 1);
    // cout << " need" << endl;
    // cout << " -> " << distance(1, 7) << endl;
	while(m--)
	{
		int t, u;
		scanf("%d %d", &t, &u);
		if(t==1) update(u, u);
		else printf("%d\n", query(u, u));
	}
	return 0;
}
