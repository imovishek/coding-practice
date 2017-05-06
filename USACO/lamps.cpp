/*
ID: ovishek1
LANG: C++11
PROB: lamps
*/

#include<bits/stdc++.h>
using namespace std;
vector<int> on(1001), off(1001);
vector<int> vt;
int k, n, c;
string get_string(vector<int> v)
{
	string st;
	for(int i = 0; i<n; i++) st = st + '1';
	for(int x : v)
	{
		if(x==1){
			for(int i = 0; i<n; i++)
				st[i] = st[i]=='1' ? '0' : '1';
		}
		else if(x==2){
			for(int i = 0; i<n; i++)
				if(i%2==0) 
					st[i] = st[i]=='1' ? '0' : '1';
		}
		else if(x==3)
		{
			for(int i = 0; i<n; i++)
				if(i%2==1) 
					st[i] = st[i]=='1' ? '0' : '1';
		}
		else if(x==4)
		{
			for(int i = 0; i<n; i++)
				if(i%3==0) 
					st[i] = st[i]=='1' ? '0' : '1';
		}
	}
	return st;
}
set<string> set_st;
int rec(int pos)
{
	if(pos==4){
		if(k-int(vt.size()) >=0 && (k-int(vt.size())) % 2 == 0) {
			string st = get_string(vt);
			// for(int x : vt) cout << x << " ";
			// cout << endl;
			// cout << st << " hi" << endl;
			int i;
			for(i = 0; i<n; i++)
			{
				if(on[i] && st[i]=='0') break;
				if(off[i] && st[i]=='1') break; 
			}
			if(i==n) set_st.insert(st);
		}

		return 0;
	}
	rec(pos+1);
	vt.push_back(pos+1);
	rec(pos+1);
	vt.pop_back();
}

int main()
{
	freopen("lamps.in", "r", stdin);
    freopen("lamps.out", "w", stdout);
    cin >> n >> k;
    int a;
    while(cin >> a && a!=-1){
    	on[a-1] = 1;
    }
    while(cin >> a && a!=-1){
    	off[a-1] = 1;
    }
    rec(0);
    // cout << set_st.size() << endl;
    for(string st : set_st)
    	cout << st << endl;
    if(set_st.size()==0) cout << "IMPOSSIBLE" << endl;
	return 0;
}