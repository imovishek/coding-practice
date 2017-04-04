/*
	ID: ovishek1
	LANG: C++11
	TASK: pprime
*/
#include<bits/stdc++.h>
using namespace std;
int ara[100005];
int super_pos = 0;
long long int a, b;
vector<int> vt;
bool isprime(long long int n)
{
	if(n<=1) return 0;
	if(n%2==0) return 0;
	for(long long int i = 3; i*i<=n; i++)
		if(n%i==0) return 0;
	return 1;
}

void rec(int pos)
{
	if(pos>=1)
	{
		long long int numa = 0, numb = 0;
		for(int i = 0; i<vt.size(); i++)
			numa = numa * 10LL + vt[i];
		numb = numa;
		numb = numb * 10 + vt.back();
		for(int i = vt.size()-2; i>=0; i--)
			numa = numa * 10LL + vt[i], numb = numb * 10LL + vt[i];
		if(numa>b) return;
		if(numa>=a) ara[super_pos++] = numa;
		if(numb<=b && numb>=a) ara[super_pos++] = numb;
	}
	if(pos==0){
		for(int i = 1; i<10; i+=2)
		{
			if(i==5) continue;
			vt.push_back(i);
			rec(pos+1);
			vt.pop_back();
		}
	}
	else{
		for(int i = 0; i<10; i++)
		{
			vt.push_back(i);
			rec(pos+1);
			vt.pop_back();
		}
	}
}
int main()
{
	freopen("pprime.in", "r", stdin);
    freopen("pprime.out", "w", stdout);
	cin >> a >> b;
	rec(0);
	sort(ara, ara+super_pos);
	if(a==5) cout << 5 << endl;
	for(int i = 0; i< super_pos; i++)
		if(isprime(ara[i])) cout << ara[i] << endl;
	return 0;
}