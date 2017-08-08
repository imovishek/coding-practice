#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define inf 1000000007


int main()
{
	int t;
	scanf("%d", &t);
	getchar();
	getchar();
	// cout << "hi" << endl;
	while(t--)
	{
		string st, ara[146];
		int n = 0;
		while(getline(cin, st) && st.length())
		{
			// cout << st << " ** " << endl;
			ara[n++] = st;
		}
		map<string, int> mp;
		for(int i = 0; i<n; i++)
			for(int j = 0; j<n; j++){
				if(i!=j) {
					mp[ ara[i] + ara[j] ]++;
					// cout << ara[i] + ara[j] << " extra hi " << mp[ ara[i] + ara[j] ] << endl;
				}
			}
		for(pair<string, int> x : mp){
			// cout << x.first << " " << x.second << endl;
			if(x.second>=n/2){
				cout << x.first << endl;
				break;
			}
		}
		if(t) cout << endl;
	}
	return 0;
}