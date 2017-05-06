/*
 ID: ovishek1
 LANG: C++11
 TASK: preface
*/

#include<bits/stdc++.h>
using namespace std;
string ara[] = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
int value[]  = {1,   4,   5,  9,   10,  40,  50, 90, 100, 400, 500, 900, 1000};
string findroman(int val)
{
	string ret;
 	for(int i = 12; i>=0; i--)
 	{
 		while(val>=value[i])
 		{
 			val -= value[i];
 			ret = ret + ara[i];
 		}
 	}
 	return ret;
}
int cnt[200];
int main()
{
	freopen("preface.in", "r", stdin);
	freopen("preface.out", "w", stdout);
	string order = "IVXLCDM";
	int n;

	while(cin >> n)
	{
		for(int i = 1; i<=n; i++)
		{
			string st = findroman(i);
			for(int j = 0; j<st.length(); j++)
				cnt[ st[j] ]++;
		}
	}
	char ch;
	for(char i : order){
		if(cnt[i]) printf("%c %d\n", i, cnt[i]);
	}
	return 0;
}