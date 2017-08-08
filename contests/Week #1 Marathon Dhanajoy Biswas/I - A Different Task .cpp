#include<bits/stdc++.h>
#define fs first
#define sc second
using namespace std;
typedef vector< stack<int> > vsi;

int bfs(vsi &st, vsi &en)
{
	queue < pair<int, vsi > > Q;
	map< vsi, int> mp;
	Q.push(make_pair(0, st));
	mp[ st ] = 0;
	while(!Q.empty())
	{
		vsi top = Q.front().sc;
		int dist = Q.front().fs;
		Q.pop();
		if(top==en) return dist;
		for(int i = 0; i<3; i++)
		{
			int onn[2];
			onn[0] = (i+1) % 3, onn[1] = (i+2) % 3;
			for(int j = 0; j<2; j++){
				if(top[i].empty()) continue;
				if(top[ onn[j] ].empty() || top[i].top() < top[onn[j]].top())
				{
					vsi temp = top;
					temp[onn[j]].push(temp[i].top());
					temp[i].pop();
					if(mp.find(temp)==mp.end()){
						Q.push(make_pair(dist + 1, temp));
					}
				}
			}
		}
	}
}

int main()
{
	ios :: sync_with_stdio(false);
	int n;
	while(cin>>n && n)
	{
		vsi st, en;
		for(int i = 1; i<=3; i++) {
			st.push_back( stack<int>() );
			en.push_back( stack<int>() );
		}
		vector<int> temp(n);
		for(int i = 0; i<n; i++)
		{
			cin >> temp[i];
		}
		for(int i = n-1; i>=0; i--)
			st[ temp[i] - 1 ]. push(i+1);
		for(int i = 0; i<n; i++)
		{
			cin >> temp[i];
		}
		for(int i = n-1; i>=0; i--)
			en[ temp[i] - 1 ]. push(i+1);
		int ans = bfs(st, en);
		cout << ans << endl;
	}
	return 0;
}