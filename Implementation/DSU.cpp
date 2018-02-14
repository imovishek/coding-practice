#include<bits/stdc++.h>
using namespace std;

struct DSU{
	int n;
	vector<int> parent, rank;
	DSU(int n) : n(n), parent(n), rank(n){
		for(int i = 0; i<n; i++)
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

struct Krushkal{
    vector< pair<int, pair<int, int> > > edges;
    int n;
    Krushkal(){n = 0;}
    Krushkal(vector<pair<int, pair<int, int> > > e, int n) : n(n) {edges = e;}
    void addEdge(int u, int v, int w)
    {
        edges.push_back({u, {v, w}});
        n = max(n, u); n = max(n, v);
    }
    long long find_min()
    {
        sort(edges.begin(), edges.end());
        DSU dsu = DSU(n);
        long long ans = 0;
        for(int i = 0; i<edges.size(); i++)
            if(dsu.merge(edges[i].first, edges[i].second.first)) ans += edges[i].second.second;
    }
};

int main()
{

	return 0;
}
