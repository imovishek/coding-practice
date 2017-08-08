#include<bits/stdc++.h>

using namespace std;
struct pii{
	int first, second, idx;
	pii(){}
	pii(int a, int b, int c){
		first = a, second = b, idx = c;
	}	
};
int s, n;
int ara[200007];
pii query[200007];
int q, sq;
bool comp(pii a, pii b)
{
	if(a.first/sq == b.first/sq) return a.second<b.second;
	return a.first/sq < b.first/sq;
}
int ans[200007];

void mos()
{
	sq = sqrt(n);
	sort(query, query+q, comp);
	int cnt = 0;
	int l = 0, r = 0;
	int counter[200005];
	memset(counter, 0, sizeof counter);
	counter[0] = -1;
	for(int i = 0; i<q; i++)
	{
		int nl = query[i].first;
		int nr = query[i].second;
		while(l<nl){
			counter[ara[l]]--;
			if(counter[ara[l]]==0) cnt--;
			l++;
		}

		while(l-1>=nl){
			counter[ara[l-1]]++;
			if(counter[ara[l-1]]==1) cnt++;
			l--;
		}
		while(r+1<=nr){
			counter[ara[r+1]]++;
			if(counter[ara[r+1]]==1) cnt++;
			r++;
		}

		while(r>nr){
			counter[ara[r]]--;
			if(counter[ara[r]]==0) cnt--;
			r--;
		}
		ans[query[i].idx] = ((cnt==(nr-nl+1)) ? 1 : 0);
	}
}


int main()
{
	ios :: sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--)
	{
		cin >> s >> n;
		for(int i = 1; i<=n; i++)
			cin >> ara[i];
		q = 0;
		for(int i = n; i>n-s  && i>=1; i--)
		{
			int l = i+1, r = i;
			if(i<n){
				query[q++] = pii(r+1, n, q-1);
			}
			while(1){
				// cout << "hi\n" << endl;
				r = l-1;
				l = l - s;
				if(r<1) break;
				if(l<1) l = 1;
				query[q++] = pii(l, r, q-1);
				if(l==1) break;
			}
		}
		mos();
		q = 0;
		int count_korbo = 0;
		for(int i = n; i>n-s  && i>=1; i--)
		{
			int l = i+1, r = i;
			int f = 0; 
			if(i<n){
				if(ans[q]==0) f = 1;
				q++;
			}
			while(1){
				r = l-1;
				l = l - s;
				if(r<1) break;
				if(l<1) l = 1;
				if(ans[q]==0){f = 1;}
				q++;
				if(l==1) break;
			}
			if(!f) {
				// cout << i << endl;
				count_korbo ++;
			}
		}
		if(n<=s){
			if(n==count_korbo) count_korbo = s;	
		}
		cout << count_korbo << endl;
		memset(ans, 0, sizeof(ans));
	}
	return 0;
}