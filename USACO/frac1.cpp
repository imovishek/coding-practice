/*
ID: ovishek1
LANG: C++11
PROB: frac1
*/



#include<bits/stdc++.h>
using namespace std;
template<typename T1, typename T2> class tair{
public:
	T1 first;
	T2 second;

	bool operator<(const tair<int, int> &b) const
	{
		return first*b.second < second*b.first;
	}
};

int main()
{
	freopen("frac1.in", "r", stdin);
    freopen("frac1.out", "w", stdout);
	int n;
	cin >> n;
	set< tair<int, int> > st;
	st.insert({0, 1});
	for(int i = 1; i<=n; i++)
		for(int j = i; j<=n; j++)
		{
			int g = __gcd(i, j);
			// cout << "hi hi" << endl;
			st.insert({i/g, j/g});
		}
	for(tair<int, int> p : st){
		// cout << "hi" << endl;
		cout << p.first << '/' << p.second << endl;
	}
	return 0;
}