/*
	ID: ovishek1
	LANG: C++11
	TASK: sprime
*/
#include<bits/stdc++.h>
using namespace std;
int n;
bool isprime(long long int n)
{
	if(n<=1) return 0;
	if(n==2) return 1;
	if(n%2==0) return 0;
	for(long long int i = 3; i*i<=n; i++)
		if(n%i==0) return 0;
	return 1;
}

vector<int> vt;

void rec(int pos, int num)
{
	if(pos==n){
		vt.p.ush_back(num);
		return;
	}

	if(pos==0) {
		rec(1, 2);
		rec(1, 3);
		rec(1, 5);
		rec(1, 7);
	}
	else{
		for(int i = 1; i<10; i+=2)
		{
			if(isprime(num*10 + i)) rec(pos+1, num*10 + i);
		}
	}
}


int main()
{
	freopen("sprime.in", "r", stdin);
	freopen("sprime.out", "w", stdout);
	cin >> n;
	rec(0, 0);
	for(int x : vt)
		cout << x << endl;
	return 0;
}