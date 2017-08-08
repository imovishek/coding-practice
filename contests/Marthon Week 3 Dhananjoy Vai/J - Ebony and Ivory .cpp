#include<bits/stdc++.h>
using namespace std;
typedef long long int lint; 
int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	int f = 0;
	for(int i = 0 ; i<=c; i++)
		if(c - a*i>=0 && (c - a*i)%b==0){f = 1; break;}
	if(f) cout << "Yes\n";
	else cout << "No\n";
	return 0;
}