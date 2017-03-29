/*
ID: ovishek1
LANG: C++11
PROB: castle
*/


#include<bits/stdc++.h>
using namespace std;

int fx[] = {-1,-1,-1,0,1,1,1,0};
int fy[] = {-1,0,1,1,1,0,-1,-1};
int fx1[] = {1,-1,0,0};
int fy1[] = {0,0,1,-1};
int dir[10];
char grid[200][200];
int vis[200][200];
int ans = 0;
int n, m;
void dfs(int x, int y)
{
	// cout << x << " * " << y << endl;
	if(x==2*n || x==0 || y==2*m || y==0) return;
	vis[x][y] = 1;
	ans+= (x&1) && (y&1);
	for(int i = 0; i<4; i++)
	{
		int a = x + fx1[i];
		int b = y + fy1[i];
		// cout << a << " " << b << endl;
		if(!vis[a][b] && grid[a][b]==' ') dfs(a, b);
	}
	// cout << "back from " << x << " " << y << endl;
}


int main()
{

	freopen("castle.in", "r", stdin);
    freopen("castle.out", "w", stdout);
	cin >> m >> n;
	dir[1] = 6;
	dir[2] = 0;
	dir[4] = 2;
	dir[8] = 4;

	for(int i = 0; i<n; i++)
		for(int j = 0; j<m; j++)
		{
			int a;
			int x = 1 + i*2;
			int y = 1 + j*2;
			cin >> a;
			for(int k = 5; k>=0; k--)
				if(a & (1<<k)){
					int direction = dir[ 1<<k ];
					for(int l = 0; l<3; l++)
					{
						grid[x + fx[direction]][y + fy[direction]] = '#';
						direction = (direction + 1) % 8;
					}
				}
		}
	for(int i = 0; i<=2*n; i++)
	{
		for(int j = 0; j<=2*m; j++){
			if(!grid[i][j]) grid[i][j] = ' ' ;
			 // cout << grid[i][j] ;
		}
		// cout << endl;
	}
	int cnt = 0, maxi = 0;
	for(int i = 0; i<=2*n; i++)
		for(int j = 0; j<=2*m; j++)
			if(!vis[i][j] && grid[i][j]==' ') {
				ans = 0;
				dfs(i, j);
				cnt++;
				maxi = max(maxi, ans);
			}
	cout << cnt << endl << maxi << endl;
	maxi = 0;
	int dira, dirb, sig;
	memset(vis, 0, sizeof vis);
	int sp = 0;
	for(int i = 0; i<n; i++)
		for(int j = 0; j<m; j++)
		{
			int x = 1 + i*2;
			int y = 1 + j*2;
			int direction = 0;
			for(int k = 0; k<4; k++)
			{
				int tmp = direction;
				int f = 0;
				for(int l = 0; l<3; l++)
				{
					if(grid[x + fx[direction]][y + fy[direction]]==' ') f = 1;
					direction = (direction + 1) % 8;
				}
				if(!f){
					// cout << x << " * " << y << endl;
					ans = 0;
					direction = (tmp + 1) % 8;
					grid[x + fx[direction]][y + fy[direction]] = ' ';
					memset(vis, 0, sizeof vis);
					dfs(x, y);

					int ta = i+1, tb = j+1, tsig = (direction + 7) % 8;
					if(tsig==4){
						tsig = 0;
						ta++;
					}
					else if(tsig==6)
					{
						tsig = 2;
						tb--;
					}

					if(ans>maxi){
						maxi = ans;
						dira = ta, dirb = tb;
						sig = tsig;
						// cout << " paisi " << dira << " " << dirb << " " << sig << endl;
					}
					else if(ans==maxi){
						
						// cout << " paisi2 " << ta << " " << tb << " " << tsig << endl;
						if(tb==dirb){
							if(ta==dira)
							{

								dira = ta, dirb = tb, sig = min(tsig, sig);
							}
							else if(ta>dira)
							{
								dira = ta, dirb = tb, sig = tsig;
							}
						}
						else if(tb<dirb){
							dira = ta, dirb = tb, sig = tsig;
						}
					}
					grid[x + fx[direction]][y + fy[direction]] = '#';
				}
				direction = (tmp + 2) % 8;
				// cout << i << " ** " << j << " " << direction << endl;
				// if(sp++==1)
				// {
				// 	for(int i = 0; i<=2*n; i++)
				// 	{
				// 		for(int j = 0; j<=2*m; j++){
				// 			if(!grid[i][j]) grid[i][j] = ' ' ;
				// 			 cout << grid[i][j] ;
				// 		}
				// 		cout << endl;
				// 	}
				// }
				// cout << "*" << endl;
			}
		}
	cout << maxi << endl << dira << " " << dirb << " " ;
	if(sig==0) cout << 'N' ;
	else if(sig==2) cout << 'E';
	else if(sig==4) cout << 'S';
	else if(sig==6) cout << 'W';
	cout << endl;
	return 0;
}