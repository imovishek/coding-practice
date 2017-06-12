/*input
2
5 3
1 2 3 4 1
6 2
1 2 1 2 1 2
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
    	int n, k;
    	cin >> n >> k;
    	int ara[n];
    	for(int i = 0; i<n; i++)
    		cin >> ara[i];
    	ara[0]%=k;
    	int cnt[k+1];
    	memset(cnt, 0, sizeof cnt);
    	cnt[0] = 1;
    	for(int i = 1; i<n; i++){
    		ara[i] = (ara[i-1] + ara[i]) % k;
    	}
    	long long ans = 0;
    	for(int i = 0; i<n; i++)
    	{
    		ans += cnt[ara[i]];
    		cnt[ ara[i] ]++;
    	}
    	cout << ans << endl;
    }
	return 0;
}