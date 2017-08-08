#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios :: sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--)
	{
		int n, f;
		cin >> n >> f;
		double ara[n], maxi = 0;
		for(int i = 0; i<n; i++){
			cin >> ara[i];
			ara[i]*=ara[i];
			maxi = max(maxi, ara[i]);
		}
		int iteration = 0;
		double l = 0, r = maxi, ans = 0;
		while(iteration<1005){
			double mid = (l+r)/2;
			int frnd = 0;
			for(int i = 0; i<n; i++)
				frnd += (int)floor(ara[i]/mid);
			if(frnd>=f+1) l = mid, ans = mid;
			else r = mid;
			iteration++;
		}
		cout << fixed << setprecision(10) << acos(-1.0) * ans<< endl;
	}
	return 0;
}