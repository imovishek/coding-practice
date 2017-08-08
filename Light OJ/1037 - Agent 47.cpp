#include<bits/stdc++.h>
using namespace std;

int n;
int ara[20];
int shots[20][20];
int dp[1<<15];
int rec(int mask)
{
	if(mask==(1<<n)-1) return 0;
	int &ret = dp[mask];
	if(ret!=-1) return ret;
	ret = 1000000007;
	for(int i = 0; i<n; i++)
		if(!(mask&(1<<i))){
			int mini = ara[i];
			for(int j = 0; j<n; j++)
				if(mask&(1<<j) && shots[j][i]) mini = min(mini, (ara[i] + shots[j][i] - 1)/shots[j][i]); 
			ret = min(ret, mini + rec(mask|(1<<i)));
		}
	return ret;
}
int main()
{
	int t, tst = 1;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		for(int i = 0; i<n ; i++)
			scanf("%d", &ara[i]);
		printf("Case %d: %d\n", tst++, rec(0));
	}
	return 0;
}