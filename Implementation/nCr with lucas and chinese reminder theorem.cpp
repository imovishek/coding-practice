/*input
4
5 2 1001
5 2 6
20 6 210
13 4 39
*/
/*
solution to problem:
http://www.spoj.com/problems/DCEPC13D/

finding nCr % m
n , r, m <= 10^9 and m is square free and has prime factors
less than 50

complexity : 50 log( 50 ) per test case  

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
ll nCr(int n, int r, int p)
{
	if(n<r) return 0;
	r = min(n-r, r);
	ll up = 1, down = 1;
	for(ll i = n; i >= n-r+1; i--)
		up = (up * i) % p;
	for(ll i = 1; i<=r; i++)
		down = (down * i) % p;
	for(ll i = 1; i<=p-2; i++)
	{
		up = (up * down) % p;
	}
	return up;
}

ll lucas(ll n, ll r, ll p)
{
	vector<int> np, rp;
	while(n)
	{
		np.push_back(n%p);
		n/=p;
	}
	while(r)
	{
		rp.push_back(r%p);
		r/=p;
	}
	ll ans = 1;
	for(int i = 0; i<np.size() && i<rp.size(); i++)
	{
		ans *= nCr(np[i], rp[i], p);
		ans %= p;
	}
	return ans;
}

ll CRT(const vector<pair<int, int> > &vt)
{
	int n = vt.size();
 	ll M = 1;
 	for(int i = 0; i<n; i++)
 		M *= vt[i].second;
 	ll ret = 0;
 	for(int i = 0; i<n; i++)
 	{
 		ll ai = vt[i].first;
 		ll Mi = (M/vt[i].second);
 		ret += ai * Mi * bigmod(Mi % vt[i].second, vt[i].second-2, vt[i].second);
 		ret %= M;
 	}
 	return ret;
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
    	int n, r, m;
    	scanf("%d %d %d", &n, &r, &m);
    	vector< pair<int, int> > vt;
    	for(int i = 2; i<=50; i++)
    	{
    		if(m%i==0){
    			m/=i;
    			vt.push_back(make_pair(lucas(n, r, i), i));
    		}
    	}
    	printf("%lld\n", CRT(vt));
    }
	return 0;
}