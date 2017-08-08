#include<bits/stdc++.h>
using namespace std;
typedef long long int lint;
int main()
{
	ios :: sync_with_stdio(false);
	int n, m, b;
	cin >> n >> b;
	lint numa = 0, numb = 0;
	for(int i = 0; i<n; i++)
	{
		int a;
		cin >> a;
		numa = numa * b + a;
	}
	cin >> n >> b;
	for(int i = 0; i<n; i++)
	{
		int a;
		cin >> a;
		numb = numb * b + a;
	}
	if(numa==numb) cout << "=" << endl;
	else if(numa<numb) cout << "<" << endl;
	else cout << ">" << endl;
	return 0;
}