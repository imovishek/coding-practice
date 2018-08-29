/*input
2

3 1 2
32.0 54.7 -2

3 1 2
32.0 54.7 -2
*/

#include <bits/stdc++.h>
using namespace std;

#define mx 100005
#define ll long long
#define MOD 1000000007
#define fs first
#define sc second


int main()
{
	int t;
	scanf("%d\n", &t);
	while(t--)
	{
		scanf(" ");
		string line;
		getline(cin, line);
		stringstream ss(line);
		// cout << line << endl;
		int n = 0, a;
		vector<int> vt;
		while(ss >> a)
		{	
			vt.push_back(a);
		}
		n = vt.size();
		// cout << n << endl;
		string ans[n];
		for(int i = 0; i<n; i++)
		{
			string st;
			cin >> st;
			ans[vt[i]-1] = st;
		}
		for(int i = 0; i<n; i++)
			cout << ans[i] << endl;
		if(t) cout << endl;
	}	
	return 0;
}
