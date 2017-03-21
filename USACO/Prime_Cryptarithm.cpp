/*
	ID: ovishek1
	LANG: C++11
	TASK: crypt1
*/
#include<bits/stdc++.h>
using namespace std;
vector<int> vt;
int flag[10];
int n;
int ara[15];
map<int, int> mp;
bool isok(int n, int sig)
{
	int digit = 0, cnt = 0;
	while(n)
	{
		digit = n%10;
		n/=10;
		cnt++;
		if(mp.find(digit)==mp.end()) return 0; 
	}
	if(sig==0) return (cnt<=3);
	else return (cnt<=4);
}
int ans = 0;
int rec(int pos)
{
	if(pos==5){
		// for(int i = 0; i<6; i++)
		// 	cout << vt[i] << " ";
		// cout << endl;
		int a = 0, b = 0;
		for(int i = 0; i<3; i++) a = a*10 + vt[i];
		for(int i = 3; i<5; i++) b = b*10 + vt[i];
		int f = 1;
		// if(a==222 && b==22){
		// 	cout << a*vt[4] << " * " << a * vt[3] << endl;
		// 	cout << " * " << a*b << endl;
		// }
		f &= isok(a*vt[4], 0);
		f &= isok(a*vt[3], 0);
		f &= isok(a*b, 1);
		if(f) {
			// cout << a << " * " << b << endl;
			ans++;
		}
		return 0;
	}
	for(int i = 0; i<n; i++){
		vt.push_back(ara[i]);
		rec(pos+1);
		vt.pop_back();
	}
}
int main()
{
	freopen("crypt1.in", "r", stdin);
	freopen("crypt1.out", "w", stdout);
	cin >> n;
	for(int i = 0; i<n; i++){
		cin >> ara[i];
		mp[ara[i]] = 1;
	}
	rec(0);
	cout << ans << endl;
	return 0;
}