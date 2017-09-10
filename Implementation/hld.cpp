/*input
1
3
1 2 5
2 3 10
QUERY 2 2
DONE
*/

#include <bits/stdc++.h>
using namespace std;

#define mx 100005
#define ll long long
#define MOD 1000000007
vector<int> edge[mx];
int chainNo[mx], newName[mx], chainHead[mx], par[mx];
int sz[mx];
int lev[mx], sp[mx][21];  // lca
map<pair<int, int>, int > niche;
int Name = 0, chain = 0;
int n;

void clear()
{
	Name = 0, chain = 0;
	niche.clear();
	for(int i = 1; i <= n; i++) edge[i].clear();
}
void get_sz(int u, int p)
{
	sz[u] = 1;
	for(int i = 0; i < edge[u].size(); i++){
		int v = edge[u][i];
		if( v != p ){
			par[v] = u, sp[v][0] = u, lev[v] = lev[u] + 1;
			niche[make_pair(u, v)] = v;
			niche[make_pair(v, u)] = v;
			get_sz(v, u);
			sz[u] += sz[v];
		}
	}
}

//lca starts
void process()
{
	memset(sp, -1,sizeof sp);
	memset(lev, 0, sizeof lev);
	for(int i = 1; i<=n; i++) if(!lev[i]) get_sz(i, -1);
	for(int j = 1; (1<<j) <= n; j++)
		for(int i = 1; i<=n; i++)
			if(sp[i][j-1] != -1) sp[i][j] = sp[ sp[i][j-1] ][j-1];
}
int lca(int u, int v)
{
	int d;
	if(lev[u] < lev[v]) swap(u, v);
	d = lev[u] - lev[v];
	for(int i = 20; i>=0; i--)
		if(d & (1 << i)) u = sp[u][i];
	if(u==v) return u;
	for(int i = 20; i>=0; i--)
		if(sp[u][i] != sp[v][i]) u = sp[u][i], v = sp[v][i];
	return sp[u][0];
}

// segment tree
int tree[mx*4];
void update(int node, int b, int e, int i, int val)
{
	if(i < b || e < i) return;
	if(b==e) { tree[node] = val; return;}
	int lson = node * 2, rson = lson + 1, mid = (b+e)/2;
	update(lson, b, mid, i, val);
	update(rson, mid+1, e, i, val);
	tree[node] = max(tree[lson], tree[rson]);
}

int query(int node, int b, int e, int i, int j)
{
	if(j < b || e < i) return INT_MIN;
	if(i <= b && e <= j) return tree[node];
	int lson = node * 2, rson = lson + 1, mid = (b+e)/2;
	return max(query(lson, b, mid, i, j), query(rson, mid+1, e, i, j));
}

// hld starts
void hld(int u, int p, bool ishead)
{
	newName[u] = ++Name;
	if(ishead) chain++, chainHead[chain] = u;
	chainNo[u] = chain;
	int mxi = -1, bigChild = 0;
	for(int i = 0; i < edge[u].size(); i++){
		int v = edge[u][i]; if( v != p && mxi < sz[v] ) mxi = sz[v], bigChild = v;
	}
	if(bigChild) hld(bigChild, u, 0);
	for(int i = 0; i < edge[u].size(); i++){
		int v = edge[u][i]; if(v != p && v != bigChild) hld(v, u, 1);
	}
}

int query_up(int u, int v)
{
	int ret = 0;
	while(1)
	{
		if(chainNo[u] == chainNo[v])
		{
			ret = max(ret, query(1, 1, n, newName[v]+1, newName[u]));
			break;
		}
		else{
			ret = max(ret, query(1, 1, n, newName[chainHead[chainNo[u]]], newName[u]));
			u = par[ chainHead[ chainNo[u] ] ];
		}
	}
	return ret;
}

int hld_query(int u, int v)
{
	int LCA = lca(u, v);
	return max(query_up(u, LCA), query_up(v, LCA));
}


int main()
{
	int t;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		pair<int, int> ara[n];
		int weight[n];
		clear();
		for(int i = 1; i<n; i++)
		{
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);
			ara[i] = make_pair(u, v);
			weight[i] = w;
			edge[u].push_back(v);
			edge[v].push_back(u);
		}
		get_sz(1, -1);
		hld(1, -1, 1);
		process();
		for(int i = 1; i<n; i++)
		{
			int ni = niche[ara[i]];
			update(1, 1, n, newName[ ni ], weight[ i ]);
		}

		// cout << hld_query(2, 7) << endl;
		char sig[100];
		while(scanf("%s", sig) && strcmp(sig, "DONE"))
		{
			int u, v;
			scanf("%d %d", &u, &v);
			if(strcmp(sig, "QUERY")==0)
				printf("%d\n", hld_query(u, v));
			else{
				int ni = niche[ara[u]];
				update(1, 1, n, newName[ ni ], v);
			}
		}
	}

	return 0;
}
