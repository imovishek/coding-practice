/*
 ID: ovishek1
 LANG: C++11
 TASK: runround
*/

#include<bits/stdc++.h>
using namespace std;
vector <int> vt;
int flag[20];
int n;
int rec(int pos, int num)
{
	// cout << pos << " " << num << endl;
	if(pos==n) {
		if(num) vt.push_back(num);
		return 0;
	}
	for(int i = 1; i<=9; i++){
		if(flag[i]==0){
			flag[i] = 1;
			rec(pos+1, num*10 + i);
			flag[i] = 0;
		}
	}
}

int isok(int ni)
{
	string st;
	while(ni)
	{
		st = st + char('0' + ni%10);
		ni/=10;
	}
	reverse(st.begin(), st.end());
	ni = st.length();
	int vis[ni];
	memset(vis, 0, sizeof vis);
	int pos = 0, cnt = 0;
	while(cnt<ni){
		vis[pos] = 1;
		pos = (pos + st[pos] - '0') % ni;
		cnt++;
	}
	for(int i : vis)
		if(!i) return 0;
	return (pos==0);
}

int main()
{
	freopen("runround.in", "r", stdin);
	freopen("runround.out", "w", stdout);
	int x;
	cin >> x;
	n = 0;
	int t = x;
	while(t){
		n++;
		t/=10;
	}
	// for_each(vt.begin(), vt.end(), [&] (int x){cout << x << endl;});
	int f = 0;
	while(!f){
		rec(0, 0);
		n++;
		int pos = upper_bound(vt.begin(), vt.end() ,x) - vt.begin();
		for(int i = pos; i<vt.size() ; i++)
		{
			int now = vt[i];
			if(isok(now)){
				cout << now << endl;
				f = 1;
				break;
			}
		}
	}

	return 0;
}