#include<bits/stdc++.h>

using namespace std;
struct pii{
	int first, second, idx;
	pii(){}
	pii(int a, int b, int c){
		first = a, second = b, idx = c;
	}	
};
pii query[200007];
int q, sq;
bool comp(pii a, pii b)
{
	if(a.first/sq == b.first/sq) return a.second<b.second;
	return a.first/sq < b.first/sq;
}
int ans[200007];
int n, m;
void mos(vector<int> ara[])
{
	sq = sqrt(n*m);
	sort(query, query+q, comp);
	int cnt = 0;
	int l = 0, r = 0;
	int counter[n+2][m+2];
	memset(counter, 0, sizeof counter);
	for(int i = 0; i<q; i++)
	{
		int nl = query[i].first;
		int nr = query[i].second;
		while(l<nl){
			for(int i = 1; i<=m; i++){
				counter[l][i] -= ara[l][i];
				if(counter[l][i]<(r-l+1)) cnt--;
			}
			l++;
		}

		while(l-1>=nl){
			for(int i = 1; i<=m; i++){
				counter[l-1][i] += ara[l-1][i];
				if(counter[l-1][i]==(r-l+1)) cnt++;
			}
			
			l--;
		}
		while(r+1<=nr){
			for(int i = 1; i<=m; i++){
				counter[r+1][i] += ara[r+1][i];
				if(counter[r+1][i]==(r-l+1)) cnt++;
			}
			r++;
		}

		while(r>nr){
			for(int i = 1; i<=m; i++){
				counter[r][i] -= ara[r][i];
				if(counter[r][i]<(r-l+1)) cnt--;
			}
			r--;
		}
		ans[query[i].idx] = cnt;
	}
}


int main()
{
	ios :: sync_with_stdio(false);
	int t;
	cin >>  n >> m;
	vector<int> ara[n+1];
	for(int i = 0; i<=m; i++) ara[i] = vector<int>(m+1, 0);
	vector<int> temp[n+1];
	for(int i = 0; i<=m; i++) temp[i] = vector<int>(m+1);
	
	for(int i = 1; i<=n; i++)
		for(int j = 1; j<=m; j++){
			cin >> temp[i][j];
			if(temp[i][j] - temp[i-1][j]>=0)  ara[i][j] = 1;
			else ara[i][j] = 0;
		}
	cin >> q;
	for(int i = 0; i<q; i++)
		cin >> query[i].first >> query[i].second ;
	mos(ara);
	for(int i = 0; i<q; i++)
	{
		if(ans[i]) cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}