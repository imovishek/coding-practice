#include<bits/stdc++.h>
using namespace std;

int main()
{
	unsigned long long int  t;
	cin >> t;
	while(t--)
	{
		unsigned long long int n, temp, mult = 1;
		cin >> n;
		int cnt = 0;
		while(n>=1)
		{
			if(n & (n-1)){
				for(int i = 63; i>=0; i--)
					if((1LL<<i) & n){
						n -= (1ll << i);
						break;
					}
			}
			else n/=2;
			cnt ++;
		}
		if(cnt%2==1) cout << "Richard" << endl;
		else cout << "Louise" << endl;

	}
	return 0;
}