/*
ID: ovishek1
LANG: C++11
PROB: sort3
*/


#include<bits/stdc++.h>
using namespace std;


int main()
{

	freopen("sort3.in", "r", stdin);
    freopen("sort3.out", "w", stdout);
	int n;
	cin >> n;
	int ara[n];
	int sara[n];
	for(int i = 0; i<n; i++){
		cin >> ara[i];
		sara[i] = ara[i];
	}
	sort(sara, sara+n);
	int cnt = 0;
	for(int i = 0; i<n; i++)
	{
		int should_be = sara[i];
		int its = ara[i];
		if(should_be==its) continue;
		int f = 0;
		int pos = 0;
		for(int j = i+1; j<n; j++)
			if(ara[j]==should_be){
				pos = j;
				if(sara[j]==its){
					break;
				}
			}
		cnt++;
		swap(ara[i], ara[pos]);
	}
	cout << cnt << endl;
	return 0;
}