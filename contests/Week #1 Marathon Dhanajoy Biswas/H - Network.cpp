#include<bits/stdc++.h>
#define mx 1007
using namespace std;
typedef pair<int, vector<int> > piv;
vector<int> edge[mx];
vector<int> canGo[mx];
int start = 0;
int n, s, k;
int vis[mx];
int dokhol[mx];

int dfs(int u, int p, int dist)
{
	if(dist>k) return 0;
	if(vis[u]==0 && edge[u].size()==1) canGo[start].push_back(u);
	for(int i = 0; i<edge[u].size(); i++)
	{
		int v = edge[u][i];
		if(v==p) continue;
		dfs(v, u, dist + 1);
	}
}

void clear()
{
	for(int i = 1; i<=n ; i++)
	{
		edge[i].clear();
		canGo[i].clear();
		vis[i] = 0;
		dokhol[i] = 0;
	}
}

int main()
{
	ios :: sync_with_stdio(false);

	int t;
	cin >> t;
	while(t--)
	{
		cin >> n >> s >> k;
		for(int i = 0; i<n-1 ; i++)
		{
			int u, v;
			cin >> u >> v;
			edge[u].push_back(v);
			edge[v].push_back(u);
		}
		start = s;
		dfs(s, -1, 0);
		for(int i = 0; i<canGo[s].size(); i++)
			vis[ canGo[s][i] ] = 1;
		priority_queue<  piv, vector<piv> , greater<piv> > pQ; 
		for(int i = 1; i<=n; i++)
		{
			if(i==s) continue;
			start = i;
			if(edge[i].size()>1) {
				dfs(i, -1, 0);
				for(int j = 0; j<canGo[i].size(); j++)
					dokhol[ canGo[i][j] ]++;
				pQ.push( piv(canGo[i].size(),  canGo[i]));
			}
		}
		int x = pQ.size();
		while(!pQ.empty())
		{
			piv top = pQ.top();
			pQ.pop();
			vector<int> &vt = top.second;
			int f = 0;
			for(int i = 0; i<vt.size(); i++)
				if(dokhol[ vt[i] ]==1) {f = 1; break;}
			if(!f){
				for(int i = 0; i<vt.size(); i++)
					dokhol[ vt[i] ] --;
				x--;
			}
		}
		cout << x << endl;
		clear();
	}
	return 0;
}