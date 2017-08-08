#include<bits/stdc++.h> 
using namespace std;

int fx[] = {0,0,1,-1};
int fy[] = {1,-1,0,0};
int n;
bool isvali(int x, int y)
{
	return x>-1 && y>-1 && x<n && y<n;
}
char grid[100][100];

bool check(int x, int y, char ch)
{
	for(int i = 0; i<4; i++)
		if(isvali(x+fx[i], y+fy[i]) && grid[x+fx[i]][y+fy[i]]==ch ) return false;
	return true;
}
int bigflag = 0;
int rec(int x, int y){
	if(x==n) {
		bigflag = 1;
		return 0;
	}
	int nx = x + (y+1)/n, ny = (y+1)%n;
	if(grid[x][y]!='.') return rec(nx, ny); 
	for(int i = 0; i<26; i++)
		if(check(x, y, 'A'+i)){
			grid[x][y] = 'A' + i;
			rec(nx, ny);
			if(bigflag) return 0;
			grid[x][y] = '.';
		}
}

int main()
{
	int t, tst = 1;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 0; i<n; i++)
			for(int j = 0; j<n; j++)
				scanf(" %c", &grid[i][j]);
		bigflag = 0;
		rec(0, 0);
		printf("Case %d:\n", tst++);
		for(int i = 0; i<n; i++){
			for(int j = 0; j<n; j++)
				printf("%c", grid[i][j]);
			printf("\n");
		}

	}
	return 0;
}