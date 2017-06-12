/*
ID: ovishek1
LANG: C++11
PROB: zerosum
*/

#include<bits/stdc++.h>
using namespace std;
int n;
vector<char> vt;
int rec(int pos)
{
	if(pos==n) {
		int sum = 0, prev = 1, num = 2;
		char p = '+';
		for(auto x : vt)
		{
			if(x==' ') prev = prev*10 + num++;
			else{
				if(p=='+') sum += prev;
				else if(p=='-') sum -= prev;
				p = x;
				prev = num++;
			}
		}
		if(p=='+') sum += prev;
		else if(p=='-') sum -= prev;
		num = 2;
		if(sum==0) {
			cout << 1;
			for(auto x : vt)
			{
				cout << x << num++ ;
			}
			cout << endl;
		}
		return 0;
	}
	vt.push_back(' ');
	rec(pos+1);
	vt.pop_back();
	vt.push_back('+');
	rec(pos+1);
	vt.pop_back();
	vt.push_back('-');
	rec(pos+1);
	vt.pop_back();
}

int main()
{
	freopen("zerosum.in", "r", stdin);
    freopen("zerosum.out", "w", stdout);
	n = 7;
	cin >> n;
	rec(1);
	return 0;
}