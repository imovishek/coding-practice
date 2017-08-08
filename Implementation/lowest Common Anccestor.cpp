#include<bits/stdc++.h>
#define mx 500007
using namespace std;
int sp_table[mx][23];
int p[mx], L[mx];
vector<int> edge[mx];
int dfs(int u, int from)
{
	p[u] = from;
	for(int i = 0; i<edge[u].size(); i++)
	{
		int v = edge[u][i];
		if(v!=from){
			L[v] = L[u] + 1;
			dfs(v, u);
		}
	}
}

int findlca( int u, int v)
{
	if(L[u]<L[v]) swap(u, v);
	int waytogo = L[u] - L[v];
	for(int i = 22; i>=0; i--)
		if(waytogo>=(1<<i)){
			waytogo -= (1<<i);
			u = sp_table[u][i];
		}
	// cout << "";
	if(u==v) return u;
	for(int i = 22; i>=0; i--)
		if(sp_table[u][i]!=sp_table[v][i])
			u = sp_table[u][i], v = sp_table[v][i];
	return sp_table[u][0];
}

int main()
{
	int n;
	while(scanf("%d", &n)==1){
		int root = 0;
		if(n>=mx) while(1);
		for(int i = 0; i<n; i++)
		{
			int u, x, v;
			scanf("%d : ( %d )", &u, &x);
			if(!root) root = u;
			while(x--){
				scanf("%d", &v);
				edge[u].push_back(v);
				edge[v].push_back(u);
			}
		}
		dfs(root, -1);
		memset(sp_table, -1 ,sizeof sp_table);
		for(int i = 1; i<=n; i++)
			sp_table[i][0] = p[i];
		for(int j = 1; (1<<j)<=n; j++)
			for(int i = 1; i<=n; i++)
				if(sp_table[i][j-1]!=-1)sp_table[i][j] = sp_table[ sp_table[i][j-1] ][j-1];
		int m;
		scanf("%d", &m);
		int cnt[n+1];
		memset(cnt, 0, sizeof cnt);
		for(int i = 0; i<m; i++)
		{
			int u, v;
			scanf(" ( %d , %d )", &u, &v);
			cnt[findlca(u, v)]++;
		}
		for(int i = 1; i<=n; i++){
			if(cnt[i]) printf("%d:%d\n", i, cnt[i]);
			edge[i].clear();
		}

	}
	return 0;
}

/*

5
5:(3
) 1
 4
  2
1:(


0   )
4
:(
0
)
2:(
1)
 3

3:(0)
6
(1  ,
5
  ) (
1,4) (
4,
2)
(2
,3)
(1,
3) (4,  3)

*/