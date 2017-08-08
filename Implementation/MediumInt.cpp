/*input

*/

#include<bits/stdc++.h>
using namespace std; 
#define CONST 1000000000000000000
typedef long long ll;
struct mInt{
	ll a, b;
	mInt(ll b = 0) : b(b), a(0) {}
	mInt(ll a, ll b) : a(a), b(b) {}
	void operator=(const ll &f)
	{
		this->b = f;
	}
	mInt operator+(const mInt &f)
	{
		ll x = (f.a + a + (f.b + b) / CONST);
		ll y = (b + f.b) % CONST;
		return mInt(x, y);
	}
	mInt operator+(const ll &f)
	{
		ll x = (a + (f + b) / CONST);
		ll y = (b + f) % CONST;
		return mInt(x, y);
	}
	mInt operator-(const mInt &f)
	{
		ll y = a - f.a;
		ll x = b - f.b;
		if(y<0)
		{
			x--;
			y += CONST;
		}
		return mInt(x, y);
	}
	// mInt mult(mInt a, int b)
	// {
	// 	if(b==0) return mInt(0, 0);
	// 	if(b&1) return 
	// }
	mInt operator*(mInt f)
	{
		mInt tmp = *this;
		ll y = ((tmp.b/1000000000) * (f.b/1000000000)) / CONST;
		tmp.b /= 10000000;  // 1e7
		f.b /= 10000000;  // 1e7
		ll x = (tmp.b * f.b) / 10000; // 1e4
	}
	friend ostream & operator<<(ostream &os, mInt &f)
	{
		if(f.a) {
			os << f.a; 
			os << setfill('0') << setw(18) << f.b;
		}
		else os << f.b ; 
	}
};


int main()
{
    mInt a = 100;
    cout << a << endl;
	return 0;
}