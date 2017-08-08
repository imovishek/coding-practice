/*input
2
3
5 4
7 6
11 3
4
2 1
3 2
5 3
7 1
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll bigmod(ll a, ll p, ll m)
{
	if(p==0) return 1 % m;
	if(p&1) return (a * bigmod(a, p-1, m)) % m;
	ll x = bigmod(a, p/2, m);
	return (x*x) % m;
}

ll CRT(const vector< pair<int, int> > &vt)
{
	ll M = 1;
	for(int i = 0; i<vt.size(); i++)
		M *= vt[i].second;
	ll ret = 0;
	// cout << M << endl;
	for(int i = 0; i<vt.size(); i++)
	{
		ll pi = vt[i].second;
		ll Mi = M / pi;
		ll yi = bigmod(Mi%pi, pi-2, pi);                   // modinv of Mi modulo pi
		ret = (ret + (vt[i].first * ((Mi * yi) % M)) % M) % M;
	}
	return ret;
}
int main()
{
    int t, tst = 1;
    scanf("%d", &t);
    while(t--)
    {
    	int n;
    	scanf("%d", &n);
    	vector< pair<int, int> > vt;
    	for(int i = 0; i<n; i++)
    	{
    		int ri, pi;
    		scanf("%d %d", &pi, &ri);
    		vt.push_back(make_pair(ri, pi));
    	}
    	printf("Case %d: %lld\n", tst++, CRT(vt));
    }
	return 0;
}