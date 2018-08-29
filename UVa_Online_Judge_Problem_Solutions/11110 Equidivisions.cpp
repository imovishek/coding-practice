/*input

2
1 2 2 1
5
1 1 1 2 1 3 3 2 2 2
2 1 4 2 4 1 5 1 3 1
4 5 5 2 5 3 5 5 5 4
2 5 3 4 3 5 4 3 4 4
5
1 1 1 2 1 3 3 2 2 2
2 1 3 1 4 1 5 1 4 2
4 5 5 2 5 3 5 5 5 4
2 4 1 4 3 5 4 3 4 4
0
*/

#include <bits/stdc++.h>
using namespace std;

#define mx 100005
#define ll long long
#define MOD 1000000007
#define fs first
#define sc second
int g[105][105];
bool vis[105][105];
int cnt = 0;
int n;
int fx[] = {1,-1,0,0};
int fy[] = {0,0,1,-1};

void dfs(int x, int y, int color)
{
	if(vis[x][y]) return;
	if(color != g[x][y]) return;
	cnt++;
	vis[x][y] = 1;
	for(int i = 0; i<4; i++)
	{
		int a = x + fx[i];
		int b = y + fy[i];
		if(a <= n && a >= 1 && b <= n && b >= 1)
			dfs(a, b, color);
	}
}

int main()
{
	while(scanf("%d", &n)==1 && n)
	{
		memset(vis, 0, sizeof vis);
		memset(g, 0, sizeof g);
		int f = 0;
		getchar();
		for(int i = 1; i<n; i++)
		{
			string line;
			getline(cin, line);
			stringstream ss(line);
			int x, y;
			while(ss >> x >> y)
				g[x][y] = i;
		}
		for(int i = 0; i<n; i++)
		{
			cnt = 0;
			for(int j = 1; j<=n; j++){
				for(int k = 1; k<=n; k++)
					if(g[j][k] == i){
						dfs(j, k, i);
						break;
					}
				if(cnt) break;
			}
			if(cnt!=n) f = 1;
		}
		if(f) printf("wrong\n");
		else printf("good\n");
	}
	return 0;
}
