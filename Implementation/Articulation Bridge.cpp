// #include<bits/stdc++.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <string>
#include <sstream>
#include <stack>
#define mod 1000000007
#define ll long long

using namespace std;

#define mx 100005

vector<int> edge[mx];
int low[mx], st[mx];
vector<pair<int, int>> articulationBridges;
int vis[mx];

int cnt = 1;

int root = 1;

void dfs(int u, int p) {
	if (vis[u]) {
		return;
	}

	vis[u] = 1;
	st[u] = cnt++;
	low[u] = st[u];

	for (int v : edge[u]) {
		if (v == p) continue;

		if (!vis[v]) { // child case
			dfs(v, u);
			low[u] = min(low[u], low[v]);
		} else { // back edge
			low[u] = min(low[u], st[v]);
		}

		// if u articulation point
		// u know low[v]

		if (st[u] < low[v]) {
			articulationBridges.push_back({u, v});
		}
	}

	
}



int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i<m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		edge[u].push_back(v);
		edge[v].push_back(u);
	}

	dfs(root, -1);

	for (auto bridge : articulationBridges) {
		cout << bridge.first << "," << bridge.second << " ";
	}

	cout << endl;

	
	return 0;
}