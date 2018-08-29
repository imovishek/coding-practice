/*input
1
7
a 3
W 10
A 100
, 10
k 7
. 3
I 13
7


t
t
t



*/

#include <bits/stdc++.h>
using namespace std;

#define mx 100005
#define ll long long
#define MOD 1000000007
#define fs first
#define sc second

ll cost[4000];
int main()
{
	int n;
	scanf("%d", &n);
	while(n--)
	{
		int k;
		scanf("%d", &k);
		memset(cost, 0, sizeof cost);
		for(int i = 0; i < k; i++){
			getchar();
			unsigned char ch;
			ll cst;
			scanf("%c %lld", &ch, &cst);
			// cout << ch << " " << cst << endl;
			int now = ch;
			assert(now >= 0);
			cost[now] = max(cost[now], cst);
		}
		int m;
		scanf("%d", &m);
		// cout << m << endl;
		getchar();
		ll totalCost = 0;
		for(int i = 0; i<m; i++)
		{
			string line;
			getline(cin, line);
			// cout << line << endl;
			for(int j = 0; j<line.size(); j++){
				int now = line[j];
				assert(now >= 0);
				totalCost += cost[now];
			}
			//totalCost += cost['\n'];
		}
		printf("%.2lf$\n", totalCost/100.0);
		
	}
	return 0;
}
