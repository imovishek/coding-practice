/*input
all_off
##########
##########
##########
##########
##########
##########
##########
##########
##########
##########
all_on
OOOOOOOOOO
OOOOOOOOOO
OOOOOOOOOO
OOOOOOOOOO
OOOOOOOOOO
OOOOOOOOOO
OOOOOOOOOO
OOOOOOOOOO
OOOOOOOOOO
OOOOOOOOOO
simple
#O########
OOO#######
#O########
####OO####
###O##O###
####OO####
##########
########O#
#######OOO
########O#
end
*/

#include<bits/stdc++.h>
using namespace std;
int grid[15][15];
int n;
vector<int> vt;
int fx[] = {0,0,1,-1};
int fy[] = {1,-1,0,0};
int isvali(int x, int y)
{
	return x<n && y<n && x>-1 && y>-1;
}
int ans = 1000007;

int cal(vector< vector<int> > table)
{
	int cnt = 0;
	for(int i = 1; i<n ; i++)
	{
		for(int j = 0; j<n; j++)
		{
			if(table[i-1][j]==1){
				table[i][j] ^= 1;
				for(int k = 0; k<4; k++)
				{
					int a = i + fx[k];
					int b = j + fy[k];
					if(isvali(a, b)){
						table[a][b] ^= 1;
					}
				}
				cnt++;
			}
		}
	}
	for(int i = 0; i<n; i++)
		if(table[n-1][i]==1) return 1000007;
	return cnt;
}
int rec(int pos)
{
	if(pos==n){
		vector< vector<int> > table(n);
		for(int i = 0; i<n; i++)
			for(int j = 0; j<n; j++) table[i].push_back(grid[i][j]);
		
		for(int i = 0; i<vt.size(); i++)
		{
			int j = vt[i];
			table[0][j] ^= 1;
			for(int k = 0; k<4; k++)
			{
				int a = fx[k];
				int b = j + fy[k];
				if(isvali(a, b)){
					table[a][b] ^= 1;
				}
			}
		}
		ans = min(ans, (int)vt.size() + cal(table));
		return 0;
	}
	vt.push_back(pos);
	rec(pos+1);
	vt.pop_back();

	rec(pos+1);
}
int main()
{
    string tst;
    while(cin >> tst)
    {
    	if(tst=="end") return 0;
    	n = 10;
    	for(int i = 0; i<n; i++)
    		for(int j = 0; j<n; j++)
    		{
    			char ch;
    			scanf(" %c", &ch);
    			grid[i][j] = (ch=='O');
    		}
    	ans = 10000007;
    	rec(0);
    	cout << tst << " ";
    	if(ans>100){
    		cout << "-1" << endl;
    	}
    	else cout << ans << endl;
    }

	return 0;
}