#include <bits/stdc++.h>
#define ll long long
#define fs first
#define sc second

using namespace std;

int vis[500005];
int counti[500005];
int casio;

int main()
{
	int n;
	scanf("%d", &n);
	int sq = max((int)sqrt(n), 316);
	pair<int, int> ara[n];
	int a[n*2], ps = 0;
	for(int i = 0; i<n; i++){
		scanf("%d %d", &ara[i].fs, &ara[i].sc);
		a[ps++] = ara[i].fs;
		a[ps++] = ara[i].sc;
	}
	sort(a, a+ps);
	int m = unique(a, a+ps) - a;
	// cout << m << "*" << endl;
	vector<int> vt[m+1], vt2[m+1], vt3[m+1];
	for(int i = 0; i<n; i++){
		ara[i].fs = lower_bound(a, a+m, ara[i].fs) - a;
		ara[i].sc = lower_bound(a, a+m, ara[i].sc) - a;
		// cout << ara[i].fs << " " << ara[i].sc << endl;
		vt[ara[i].fs].push_back(ara[i].sc);
	}
	ll ans = 0;
	for(int i = 0; i<m; i++)
	{
		if(vt[i].size() > sq){
			casio++;
			for(int x : vt[i]) vis[x] = casio;
			
			for(int j = 0; j<m; j++){
				if(i == j) continue;
				if(j < i && vt[j].size() > sq) continue;
				int cnt = 0;
				for(int y : vt[j]){
					if(vis[y] == casio) cnt++;
				}
				ans += 1ll * cnt * (cnt - 1) / 2;
			}
		} else{
			for(int x : vt[i]){
				vt2[x].push_back(i);
			}
		}
	}
	// for(int i = 0; i<m; i++) vt[i].clear();
	vector<int > nw;
	for(int i = 0; i<m; i++)
	{
		if(vt2[i].size() > sq){
			casio++;
			for(int x : vt2[i]) vis[x] = casio;
			
			for(int j = 0; j<m; j++){
				if(i == j) continue;
				if(j < i && vt2[j].size() > sq) continue;
				int cnt = 0;
				for(int y : vt2[j]){
					if(vis[y] == casio) cnt++;
				}
				ans += 1ll * cnt * (cnt - 1) / 2;
			}
		} else if(vt2[i].size()){
			nw.push_back(i);
			for(int x : vt2[i]){
				vt[x].push_back(i);
			}
		}
	}
	
	m = nw.size();
	// cout << m << endl;
	// cout << ans << endl;
	for(int i = 0; i<m; i++)
	{
		casio++;
		//cout << nw[i] << " " ;
		int c = 0;
		for(int x : vt2[nw[i]]) {
			for(int y : vt[x]) {
				if(y <= nw[i]) continue;
				//cout << "(" << y << ")" << " ";
				if(vis[y] == casio){
					// vis[y] = casio;
					counti[y]++;
				} else{
					vis[y] = casio;
					counti[y] = 1;
				}
				ans += counti[y] - 1;
				c += counti[y]-1;
			}
		}
		//cout << c << endl;

		
		
	}
	printf("%lld\n", ans);
	return 0;
}