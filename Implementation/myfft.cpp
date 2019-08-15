#include <bits/stdc++.h>
#define fs first
#define sc second
#define mx 100005
#define mod 1000000007
#define pii pair<int, int>
#define ll long long
using namespace std;
#define vi vector<int>
#define vl vector<base>
typedef complex<long double> base;
#define pi acos(-1.0)
vl fft(vl a){
	if(a.size()==1) return a;
	vl lft, rght; 
	for(int i = 0; i<a.size(); i++){
		if(i&1) rght.push_back(a[i]);
		else lft.push_back(a[i]);
	}
	lft = fft(lft);
	rght = fft(rght);
	base nw(1);
	int n = a.size();
	long double angle = 2.0*pi/n;
	base b = base(cos(angle), sin(angle));
	for(int i = 0; i<n/2; i++){
		a[i] = lft[i] + nw * rght[i];
		a[i+n/2] = lft[i] - nw * rght[i];
		nw *= b;
	}
	return a;
}

vl inversefft(vl a){
	if(a.size()==1) {
		return a;
	}
	vl lft, rght;
	for(int i = 0; i<a.size(); i++){
		if(i&1) rght.push_back(a[i]);
		else lft.push_back(a[i]);
	}
	lft = inversefft(lft);
	rght = inversefft(rght);
	base nw(1);
	int n = a.size();
	long double angle = -2.0*pi/n;
	base b = base(cos(angle), sin(angle));
	for(int i = 0; i<n/2; i++){
		a[i] = lft[i] + nw * rght[i];
		a[i+n/2] = lft[i] - nw * rght[i];
		a[i]/=n;
		a[i+n/2]/=n;
		nw *= b;
	}
	return a;
}

vi multiply(vi a, vi b){
	int n = max(a.size(), b.size());
	while(n&(n-1)) n++;
	n*=2;
	a.resize(n);
	b.resize(n);
	// cout << n << endl;

	vl ai = fft(vl(a.begin(), a.end())), bi = fft(vl(b.begin(), b.end()));
	vl c(n);
	for(int i = 0; i<n; i++){
		c[i] = ai[i] * bi[i];
	}
	c = inversefft(c);
	vi ret(n);
	for(int i = 0; i<n; i++) ret[i] = floor(c[i].real() + 0.5);
	//while(ret.back()==0 && ret.size()) ret.pop_back();
	return ret;
}
int main()
{
	vector<int> res, a = {1, 2, 3}, b = {1, 2, 3};
	auto ans = multiply(a, b);
	for(int x : ans) cout << x << " ";
	cout << endl;
	return 0;
}