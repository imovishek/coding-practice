#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	while(cin >> n)
	{
		int ans = 1;
		int cnt = 0;
		while((ans<<1) <= n) ans <<=1, cnt++;
		cout << cnt+1 << endl;
	}
	return 0;
}