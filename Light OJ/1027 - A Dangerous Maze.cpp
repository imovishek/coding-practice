#include<bits/stdc++.h>

using namespace std;
typedef long long int lint;
class fraction{
public:
	lint up, down;
	int sign;
	fraction(){
		up = 0, down = 1;
		sign = 1;
	}
	fraction(lint a, lint b, int c = 1){
		up = a, down = b;
		sign = c;
	}
	fraction operator+(const fraction &a) const{
		lint lcm = down/__gcd(down, a.down)*a.down;
		lint nup = sign * (lcm/down) * up + a.sign * (lcm/a.down) * a.up; 
		lint ndown = lcm;
		int nsign = nup / abs(nup);
		nup = abs(nup);
		lint g = __gcd(nup, ndown);
		if(g==0) {
			cerr << "undefined fraction\n" << endl;
			return fraction(nup, ndown, nsign);
		}
		return fraction(nup/g, ndown/g, nsign);
	}

	fraction operator*(const fraction &a) const{
		lint g1 = __gcd(up, a.down);
		lint g2 = __gcd(down, a.up);
		int nsign = sign * a.sign;
		if(g1==0 || g2==0){
			cerr << "undefined fraction\n" << endl;
			return fraction(0, 0, 1);
		}
		lint nup = (up/g1) * (a.up/g2);
		lint ndown = (a.down/g1) * (down/g2);
		return fraction(nup, ndown, nsign);
	}
	fraction operator-(const fraction &a) const{
		return (*this) + fraction(a.up, a.down, -a.sign);
	}
	fraction operator/(const fraction &a) const{
		return (*this) * fraction(a.down, a.up, a.sign);
	}
	bool operator<(const fraction &a) const{
		return sign*1.0*up/down < a.sign*1.0*a.up/a.down;
	}
	void print()
	{
		if(sign==-1) cout << "-" ;
		cout << up << "/" << down;
	}

};
int main()
{
	ios :: sync_with_stdio(false);
	int t, tst = 1;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		int neg = 0, sum_pos = 0, sum_neg = 0;
		for(int i = 0; i<n; i++)
		{
			int a;
			cin >> a;
			if(a<0){				
				neg++;
				sum_neg += abs(a);
			}
			else sum_pos += a;
		}
		cout << "Case " << tst++ << ": ";
		if(neg==n) cout << "inf" << endl;
		else{
			fraction ex = fraction(1, 1) - fraction(neg, n);
			fraction rhs = fraction(sum_pos, n) + fraction(sum_neg, n);
			(rhs/ex).print();
			cout << endl;
		}
	}
	return 0;
}