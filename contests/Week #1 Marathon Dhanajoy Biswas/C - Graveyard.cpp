#include<bits/stdc++.h>
using namespace std;
typedef pair<double, pair<int, int> > pdpii;

int main()
{
	ios :: sync_with_stdio(false);
	int n, m;
	while(cin >> n >> m)
	{
		vector<double> newpos(1);
		double gap = 10000.0/(n+m);
		double initgap = 10000.0/(n);
		for(int i = 1; i<=n+m-1; i++)
			newpos.push_back(gap*i);
		priority_queue< pdpii, vector<pdpii> , greater<pdpii> > pQ;
		for(int i = 1; i<n; i++)
			for(int j = 1; j<=n+m-1 ; j++)
				pQ.push( pdpii( min(fabs(newpos[j] - i*initgap), fabs(fabs(newpos[j] - i*initgap) - 10000.0)), make_pair(i, j) ) );
		int newflag[n+m+2], initflag[n+1];
		memset(newflag, 0, sizeof(newflag));
		memset(initflag, 0, sizeof(initflag));
		double ans = 0.0;
		while(!pQ.empty()){
			pdpii top = pQ.top();
			pQ.pop();
			// cout << top.first << ' ' << top.second.first << ' ' << top.second.second << '*' << endl;
			if(initflag[top.second.first] || newflag[top.second.second]) continue;
			initflag[top.second.first] = newflag[top.second.second] = 1;
			ans += top.first;
		}
		cout << fixed << setprecision(10) << ans << endl;
	}
	return 0;
}