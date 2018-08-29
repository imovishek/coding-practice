/*input
5 5
5 1
5 9
5 10
117 348
288 10000
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
	int n, k;
	while(scanf("%d %d", &n, &k)==2){
		auto comp = [](pair<int, int> a, pair<int, int> b){return a.fs*b.sc < a.sc*b.fs;};
		set< pair<int, int> , decltype(comp)> st(comp);
		for(int i = 1; i<=n; i++)
		{
			for(int j = i; j<=n; j++)
			{
				int a = i / __gcd(i, j);
				int b = j / __gcd(i, j);
				st.insert({a, b});
			}
		}		 
		k--;
		while(k--) st.erase(st.begin());
		auto p = *st.begin();
		cout << p.first << "/" << p.second << endl;
	}
	return 0;
}
