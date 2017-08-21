/*
	ID: ovishek1
	LANG: C++11
	TASK: concom
*/
#include <bits/stdc++.h>
using namespace std;
#define MX 105
bool share[MX][MX];
int pshare[MX][MX];
int actual[MX][MX];
int main()
{
	freopen("concom.in", "r", stdin);
    freopen("concom.out", "w", stdout);
	int n;
	scanf("%d", &n);
	for(int i = 0; i<n; i++)
	{
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		pshare[u][v] = w;
		actual[u][v] = w;
	}
	n = MX-1;
	for(int k = 0; k<n; k++)
	{
		// for(int uu = 1; uu<=n; uu++){
		// 	for(int vv = 1; vv<=n; vv++)
		// 		printf("%d ", pshare[uu][vv]);
		// 	printf("\n");
		// }
		for(int u = 1; u<=n; u++)
		{
			for(int v = 1; v<=n; v++)
			{

						
				if(u!=v && share[u][v] != 1 && pshare[u][v] > 50) {
					share[u][v] = 1;
					for(int i = 1; i<=n; i++)
					{
						pshare[u][i] += actual[v][i];
					}
				}
			}
		}
	}
	for(int u = 1; u<=n; u++)
		for(int v = 1; v<=n; v++)
			if(u!=v && share[u][v]) printf("%d %d\n", u, v);
			
	return 0;
}