/*input
5 5
1 2 1 1 2
1 2
1 3
2 4
2 5
1 2 3
1 1 2
2 1
2 2
2 4
*/ // Propagating tree Codeforces

#include <bits/stdc++.h>
using namespace std;

#define mx 200005
#define ll long long
#define MOD 1000000007

vector<int> edge[mx];
int st[mx], en[mx], lev[mx], intval[mx];
int T = 0;
int dfs(int u, int p)
{
	st[u] = ++T;
	for(int v : edge[u])
	{
		if(v != p){
			lev[v] = (lev[u] + 1) % 2;
			dfs(v, u);
		}
	}
	en[u] = T;
}

struct SegTree{
	int lazy[mx*4];
	void update(int node, int b, int e, int i, int j, int val)
	{
	    if(j<b || i>e) return;
	    if(i<=b && e<=j) lazy[node] += val;
	    int lson = node*2, rson = lson + 1, mid = (b+e)/2;
	    if(lazy[node] && b!=e){
	        lazy[lson] += lazy[node];
	        lazy[rson] += lazy[node];
	        lazy[node] = 0;
	    }
	    if(i<=b && e<=j) return;
	    update(lson, b, mid, i, j, val);
	    update(rson, mid+1, e, i, j, val);
	}
	 
	int query(int node, int b, int e, int i)
	{
	    if(i<b || i>e) return 0;
	    int lson = node*2, rson = lson + 1, mid = (b+e)/2;
	    if(lazy[node] && b!=e){
	        lazy[lson] += lazy[node];
	        lazy[rson] += lazy[node];
	        lazy[node] = 0;
	    }
	    if(b==e && b==i) return lazy[node];
	    int x = query(lson, b, mid, i);
	    int y = query(rson, mid+1, e, i);
	    return x+y;
	}
} Seg[2];


int main()
{
	int n, q;
	scanf("%d %d", &n, &q);
	for(int i = 1; i<=n; i++)
	{
		scanf("%d", &intval[i]);
	}
	for(int i = 1; i<n; i++)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	dfs(1, -1);
	for(int i = 1; i<=n; i++)
		Seg[lev[i]].update(1, 1, n, st[i], st[i], intval[i]);
	while(q--)
	{
		int sig, x, val;
		scanf("%d %d", &sig, &x);
		int level = lev[x];
		if(sig == 1){
			scanf("%d", &val);
			Seg[level].update(1, 1, n, st[x], en[x], val);
			Seg[!level].update(1, 1, n, st[x], en[x], -val);
		}
		else{
			printf("%d\n", Seg[level].query(1, 1, n, st[x]));
		}
	}
	return 0;
}
