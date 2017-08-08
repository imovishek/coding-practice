#include<bits/stdc++.h>
using namespace std;

struct dhal{
	int up, down, sign;
	dhal(){
		up = 0, down = 1, sign = 1;
	}
	dhal(int a, int b, int c)
	{
		up = a, down = b, sign = c;
	}
	bool operator<(const dhal &a) const{
		cout << "hi * " << endl;
		int g = __gcd(down, a.down);
		if(g==0) return true;
		int l = down / g * a.down; 
		cout << "hi ** " << endl;
		return up * (l/down) < a.up * (l/a.down);
		// return sign * 1.0 * up / down < a.sign * 1.0 * a.up / a.down;
	}
};

int main()
{
	ios :: sync_with_stdio(false);
	int n, x, y;
	cin >> n >> x >> y;
	set< dhal> st;
	for(int i = 0; i<n; i++)
	{
		int a, b;
		cin >> a >> b;
		int up = a - x;
		int down = b - y;
		int sign = 1;
		if(down<0) {
			up = -up;
			down = -down;
		}
		if(up<0) {
			sign = -1;
			up = -up;
		}
		int g = __gcd(up , down);
		up/=g, down/=g;
		if(down==0 || up==0) sign = 1;
		// cout << up << " * " << down << " " << sign << endl; 
		st.insert( dhal(up, down, sign) );
	}
	cout << st.size() << endl;
	return 0;
}