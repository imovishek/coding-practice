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
vector<int> rEdge[mx];
stack<int> topOrder;


int vis1[mx];
void dfs1(int u) {
	if (vis1[u]) {
		return;
	}

	vis1[u] = 1;

	for (int v : edge[u]) {
		dfs1(v);
	}
	topOrder.push(u);
}


vector<vector<int>> scc;

int vis2[mx];
int currentIndex = 0;
void dfs2(int u) {
	if (vis2[u]) {
		return;
	}

	vis2[u] = 1;

	if (currentIndex < scc.size()) {
		scc[currentIndex].push_back(u);
	} else {
		scc.push_back({ u });
	}

	for (int v : rEdge[u]) {
		dfs2(v);
	}

}


int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i<m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		edge[u].push_back(v);
		rEdge[v].push_back(u);
	}

	for (int i = 1; i<=n ;i++) {
		if (!vis1[i]) {
			dfs1(i);
		}
	}

	while(!topOrder.empty()) {
		int u = topOrder.top();
		topOrder.pop();

		if (!vis2[u]) {
			dfs2(u);
			currentIndex ++;	
		}
	}
    
  cout << "SCC gulo holo:\n";
	for (auto s : scc) {
		for (int x : s) {
			cout << x << " ";
		}
		cout << endl;
	}

	return 0;
}