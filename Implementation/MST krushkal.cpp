/*input
4 4
1 2 5
1 3 3
4 3 3
2 4 1
*/

#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define pii pair<int, int>
#define ll long long

struct DisjointSetUnion{
	int n;
	vector<int> parent, rank;
	DisjointSetUnion(int n) : n(n), parent(n+1), rank(n+1){
		for(int i = 0; i<=n; i++)
			parent[i] = i;
	}
	int rootof(int x)
	{
		if(parent[x]!=x) parent[x] = rootof(parent[x]);
		return parent[x];
	}
	bool merge(int x, int y)
	{
		int a = rootof(x);
		int b = rootof(y);
		if(a==b) return false;
		if(rank[a]>rank[b]) parent[b] = a;
		else if(rank[a]<rank[b]) parent[a] = b;
		else{
			rank[a]++;
			parent[b] = a;
		}
		return true;
	}
};

struct Kruskal{
	vector<pair<int, pii> > edges;
	int n;
	Kruskal(int n) : n(n) {}
	void addEdge(int u, int v, int w)
	{
		edges.push_back({w, {u, v}});
	}
	ll getMST(){
		DisjointSetUnion dsu = DisjointSetUnion(n);
		sort(edges.begin(), edges.end());
		ll ret = 0;
		for(int i = 0; i<edges.size(); i++)
		{
			int u = edges[i].sc.fs, v = edges[i].sc.sc, w = edges[i].fs; 
			if(dsu.merge(u, v)) ret += w;
		}
		return ret;
	}
};

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	int u, v, w;
	Kruskal krus(n);
	for(int i = 0; i<m; i++)
	{
		scanf("%d %d %d", &u, &v, &w);
		krus.addEdge(u, v, w);
	}
	printf("%lld\n", krus.getMST());
	
	return 0;
}