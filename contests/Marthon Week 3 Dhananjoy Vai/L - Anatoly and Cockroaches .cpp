#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	string st;
	cin >> st;
	int ans = 0;
	int a = 0, b = 0;
	for(int i = 0; i<n; i++) 
		if((i&1) && st[i]!='b') b++;
		else if( (i%2==0) && st[i]!='r') a++;
	ans = max(a, b);
	a = 0, b = 0;
	for(int i = 0; i<n; i++) 
		if((i&1) && st[i]!='r') b++;
		else if( (i%2==0) && st[i]!='b') a++;
	ans = min( ans, max(a, b) );
	cout << ans << endl;
	return 0;
}