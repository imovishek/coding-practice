#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define inf 2000000007


int main()
{
	ios :: sync_with_stdio(false);
	int n;
	while(cin >> n && n){
		int ara[n];
		map<  int , pii > mp2;
		map<  int , vector<pii> > mp1;
		for(int i = 0; i<n; i++)
			cin >> ara[i];
		for(int i = 0; i<n; i++)
			for(int j = 0; j<n; j++)
				if(i!=j) mp1[ara[i] - ara[j]].push_back(pii(ara[i], ara[j]));
		
		for(int i = 0; i<n; i++)
			for(int j = i+1; j<n; j++)
				mp2[ara[i] + ara[j]] = (pii(ara[i], ara[j]));
		
		int ans = -inf;
		for(pair< int, pii> x : mp2)
		{
			int ax = x.second.first;
			int ay = x.second.second;
			vector<pii> &vt = mp1[x.first];
			for(pii y : vt)
				if(!(ax == y.first || ax==y.second || ay==y.first || ay==y.second)) ans = max(ans, ax+ay+y.second);
		}
		if(ans==-inf) cout << "no solution" << endl;
		else cout << ans << endl;
	}
	return 0;	
}