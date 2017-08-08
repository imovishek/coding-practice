#include<bits/stdc++.h>
using namespace std;
#define mx 1000040
typedef long long int lint;
bool mark[mx];
void sieve()
{
	for(int i = 4; i<mx; i+=2) mark[i] = 1;
	for(int i = 3; i*i<mx; i+=2)
		if(!mark[i])
			for(int j = i*i; j<mx; j+=i+i)
				mark[j] = 1;
}

int main()
{
	int n;
	cin >> n;
	sieve();
	for(int i = 0; i<n; i++)
	{
		lint a;
		cin >> a;
		lint sq = sqrt(a);
		if( sq<2 || sq*sq!=a || mark[sq]) cout << "NO\n" ;
		else cout << "YES\n";
	}
	return 0;
}