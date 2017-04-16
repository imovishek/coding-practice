#include<bits/stdc++.h>
using namespace std;

struct DisjointSet{
	int n;
	vector<int> parent, rank;
	DisjointSet(int n) : n(n), parent(n), rank(n){
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

int main()
{

	return 0;
}