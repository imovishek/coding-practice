/*input
3
1 2 3
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    long long ara[n];
    for(int i = 0; i<n; i++) scanf("%lld", &ara[i]);
    long long pref[n+1], suff[n+1];
	pref[0] = suff[n] = 0;
	for(int i = 1; i<=n; i++)
		pref[i] = pref[i-1] ^ ara[i-1];
	for(int i = 1; i<=n; i++)
		pref[i] = max(pref[i], pref[i-1]);
	for(int i = n-1; i>=0; i--)
		suff[i] = suff[i+1] ^ ara[i];
	for(int i = n-1; i>=0; i--)
		suff[i] = max(suff[i], suff[i+1]);
	long long maxi = max(suff[0], pref[n]);
	// for(int i = 0; i<=n; i++)
	// 	maxi = max(maxi, max(pref[i], suff[i]));
	printf("%lld\n", maxi);
	return 0;
}