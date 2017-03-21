/*
	ID: ovishek1
	LANG: C++11
	TASK: skidesign
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("skidesign.in", "r", stdin);
 	freopen("skidesign.out", "w", stdout);
	int n;
	cin >> n;
	int ara[n];
	for(int i = 0; i<n; i++) {
		cin >> ara[i];
	}
	sort(ara, ara+n);
	int st = 0, en = 17, mini = 1000000007;
	while(en<=ara[n-1])
	{
		int ans = 0;
		for(int i = 0; i<n; i++)
		{
			if(ara[i]>en) ans += (ara[i] - en) * (ara[i] - en);
			if(ara[i]<st) ans += (st - ara[i]) * (st - ara[i]); 
		}
		mini = min(ans, mini);
		st++, en++;
	}
	cout << mini << endl;
    return 0;
}

/*
50
50
84
22
44
38
0
46
66
22
73
25
92
5
56
13
73
48
32
42
91
3
100
97
8
27
34
73
58
42
80
53
59
55
52
3
30
84
100
31
80
79
11
70
55
64
92
29
77
71
72



*/