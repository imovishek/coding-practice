/*input
6
pasha 0
gerald 1
gerald 1
valera 2
igor 3
olesya 1
5
1 1
1 2
1 3
3 1
6 1
*/

#include <bits/stdc++.h>
using namespace std;

#define mx 100005
#define ll long long
#define MOD 1000000007
int sz[mx], lev[mx];
int par[mx];
string name[mx];
vector<int> edge[mx];
void getsz(int u, int p)
{
	sz[u] = 1;
	for(auto v : edge[u])
		if(v != p){
			lev[v] = lev[u] + 1, getsz(v, u), sz[u] += sz[v];
		}
}

vector<int> *vec[mx];
int res[mx];
vector< pair<int, int> > query[mx];
map<string, int> h[mx];

void dfs(int u, int p, bool keep)
{
	int mxi = -1, bigChild = -1;
	for(auto v : edge[u])
		if(v!=p && sz[v] > mxi)
			mxi = sz[v], bigChild = v;
	for(auto v : edge[u])
		if(v!=p && v != bigChild)
			dfs(v, u, 0);
	if(bigChild != -1)
		dfs(bigChild, u, 1), vec[u] = vec[bigChild];
	else
		vec[u] = new vector<int> ();
	vec[u] -> push_back(u);
	
	h[ lev[u] ][name[u]]++;

	for(auto v : edge[u])
		if(v != p && v != bigChild)
			for(auto x : *vec[v])
			{
				h[ lev[x] ][ name[x] ]++;
				vec[u] -> push_back(x);
			}

	//	 query start
	// cout << u << " ********** " << endl;
	// for(int i = 0; i<7; i++)
	// 	cout << i << " -> " << h[i] << endl;
	for(auto x : query[u]){
		if(lev[u] + x.first >= mx) {
			res[x.second] = 0;
			continue;
		}
		res[x.second] = h[lev[u] + x.first].size();
		// cout << "q " << x.first << endl;
	}

	//	 query end

	
	if(keep == 0){
		for(auto x : *vec[u]){
			h[lev[x]].clear();
		}
	}
		
}



int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i<=n; i++)
	{
		int u;
		cin >> name[i];
		scanf("%d", &u);
		if(u) edge[u].push_back(i);
		par[i] = u;
		// cout << i << " " << u << endl;
	}


	
	
	int m;
	scanf("%d", &m);
	for(int i = 0; i<m; i++)
	{
		int u, p;
		scanf("%d %d", &u, &p);
		query[u].push_back({p, i});
	} 
	for(int i = 1; i<=n; i++)
	{
		if(par[i] == 0)
		{
			getsz(i, -1);
			dfs(i, -1, 0);
		}
	}
	for(int i = 0; i<m; i++)
		printf("%d\n", res[i]);
	return 0;
}
