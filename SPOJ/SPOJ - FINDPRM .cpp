#include<bits/stdc++.h> 
#define mx 10000007
using namespace std;
typedef long long int lint;

bool mark[mx];
int prime[mx];
void sieve()
{
	for(int i = 3; i*i<mx; i++)
		if(!mark[i])
			for(int j = i*i; j<mx; j+=i+i)
				mark[j] = 1;
	int pos = 1;
	prime[0] = 0;
	prime[1] = 0;
	prime[2] = 1;
	for(int i = 3; i<mx; i++)
		if( (i&1) && !mark[i]) prime[i] = prime[i-1] + 1;
		else prime[i] = prime[i-1];
	//cout << pos << endl;
}

int main()
{
	ios :: sync_with_stdio(false);
	sieve();
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		cout << prime[n] - prime[n/2] << endl;
	}
	return 0;
}