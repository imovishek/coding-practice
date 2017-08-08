/*input

*/

#include<bits/stdc++.h>
using namespace std;

template<typename T> class Fraction{
public:
    T up, down;
    int sign;
    Fraction(){
        up = T(0), down = T(1);
        sign = 1;
    }
    Fraction(T a, T b, int c = 1){
        up = T(a), down = T(b);
        sign = c;
    }
    Fraction operator+(const Fraction &a) const{
        T lcm = down/__gcd(down, a.down)*a.down;
        T nup = sign * (lcm/down) * up + a.sign * (lcm/a.down) * a.up;
        T ndown = lcm;
        int nsign = nup / abs(nup);
        nup = abs(nup);
        T g = __gcd(nup, ndown);
        if(g==0) {
            cerr << "undefined Fraction\n" << endl;
            return Fraction(nup, ndown, nsign);
        }
        return Fraction(nup/g, ndown/g, nsign);
    }
 
    Fraction operator*(const Fraction &a) const{
        T g1 = __gcd(up, a.down);
        T g2 = __gcd(down, a.up);
        int nsign = sign * a.sign;
        if(g1==0 || g2==0){
            cerr << "undefined Fraction\n" << endl;
            return Fraction(0, 0, 1);
        }
        T nup = (up/g1) * (a.up/g2);
        T ndown = (a.down/g1) * (down/g2);
        return Fraction(nup, ndown, nsign);
    }
    Fraction operator-(const Fraction &a) const{
        return (*this) + Fraction(a.up, a.down, -a.sign);
    }
    Fraction operator/(const Fraction &a) const{
        return (*this) * Fraction(a.down, a.up, a.sign);
    }
    bool operator<(const Fraction &a) const{
        return sign*1.0*up/down < a.sign*1.0*a.up/a.down;
    }
    friend ostream& operator << (ostream &os, const Fraction &a)
    {
    	if(a.sign==-1) os<<'-';
    	os << a.up;
    	if(a.down!=T(1)) os << '/' << a.down;
    }
 
};

int main()
{
    cout << Fraction<int> (1, 3) << endl;
	return 0;
}