/*input

*/

#include<bits/stdc++.h>
using namespace std;

struct BoardEscapeDiv2{
	int n, m;
	bool isvali(int x, int y)
	{
		return x >=0 && y>=0 && x<n && y<m;
	}
	vector<int> fx ;
	vector<int> fy ;
	vector<string> grid;
	BoardEscapeDiv2(){
		fx = {1,-1,0,0};
		fy = {0,0,1,-1};
	}
	int dp[55][55][105];
	int rec(int x, int y, int now)
	{
		if(now==0) return 0;
		int &ret = dp[x][y][now];
		if(ret!=-1) return ret;
		int f = 0;
		ret = 0;
		for(int i = 0; i<4; i++)
		{
			int a = x + fx[i];
			int b = y + fy[i];
			if(isvali(a, b) && grid[a][b]=='E') {f = 1; break;}
		}
		if(f) return ret = 1;
		else{
			for(int i = 0; i<4; i++)
			{
				int a = x + fx[i];
				int b = y + fy[i];
				if(isvali(a, b) && grid[a][b]!='#') {
					f |= !rec(a, b, now-1);
					if(f) break;
				}
			}
			return ret = f;
		}
	}
	string findWinner(vector<string> gridx, int t)
	{
		n = gridx.size();
		m = gridx[0].length();
		grid = gridx;
		memset(dp, -1, sizeof dp);
		int ans = 0;
		for(int i = 0; i<n; i++)
			for(int j = 0; j<m; j++)
				if(grid[i][j]=='T'){
					ans = rec(i, j, t);
				}
		if(ans) return "Alice";
		else return "Bob";
	}
};


int main()
{
	BoardEscapeDiv2 x;
	cout << x.findWinner({
		".##.#..###..#.", 
		"#..T..#.###..#", 
		".######.###..#", 
		"#.E#.#.####.##", 
		"#.###.#E#...##", 
		"#.###..#.#.###", 
		"#..#.#.#E##.#."}, 8) << endl;
}