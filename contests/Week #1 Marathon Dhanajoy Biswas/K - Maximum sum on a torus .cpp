#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);

	int n;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n;
		int grid[n+1][n+1];
		memset(grid, 0, sizeof grid);
		for(int i = 1; i<=n; i++)
			for(int j = 1; j<=n; j++){
				cin >> grid[i][j];
				grid[i][j] += grid[i-1][j];
			}
		int ans = 0, a, b;
		for(int i = 1; i<=n ; i++)
			for(int j = 1; j<=n ; j++)
			{
				vector<int> temp;
				int whole_sum = 0;
				// cout << i << '*' << j << endl; 
				for(int k = 1; k<=n ; k++){
					if(j<i) temp.push_back( grid[j][k] - grid[0][k] + grid[n][k] - grid[i-1][k] );
					else temp.push_back( grid[j][k] - grid[i-1][k]);
					// cout << temp[k-1] << ' ' ;
					whole_sum += temp[k-1];
				}
				// cout << endl;
				int sum = 0, maxi = 0;
				for(int k = 0; k<n; k++)
				{
					if(sum + temp[k]<0) sum = 0;
					else sum += temp[k];
					ans =  max(ans, sum);
					temp[k] *= -1;
				}
				sum = 0;
				for(int k = 0; k<n; k++)
				{
					if(sum + temp[k]<0) sum = 0;
					else sum += temp[k];
					maxi =  max(maxi, sum);
				}
				// cout << whole_sum << ' ' << maxi << ' ' << ans << " ke tui bol? \n";
				ans = max(ans, whole_sum + maxi);
			}
		// cout << a << ' ' << b << '*' << endl;
		cout << ans << endl;

	}
	return 0;
}