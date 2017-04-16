#include<bits/stdc++.h>
using namespace std;

long long f(long long int x)
{
	return 2*x*x - 12*x + 7;
}



int main()
{
	int n;
	cin >> n;
	while(n--)
	{
		int l, r;
		cin >> l >> r;
		long long int ans = 0;
		while(l<=r)
		{
			long long int mid1 = l+(r-l)/3, mid2 = r - (r-l)/3;
			// cout << l << " * " << r << " && " << mid1 << " " << mid2 << endl;
			if(f(mid1)>=f(mid2)) l = mid1+1, ans = f(mid2);
			else r = mid2 - 1, ans = f(mid1);
		}
		cout << ans << endl;
	}
	return 0;
}