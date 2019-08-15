#include <bits/stdc++.h>
#define fs first
#define sc second
#define mx 100005
#define mod 1000000007
#define pii pair<int, int>
#define ll long long
using namespace std;
#define vi vector<ll>
#define vl vector<base>
typedef complex<long double> base;
#define pi acos(-1.0)
vl fft(vl a){
	cout << a.size() << endl;
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
	base b = base(cos(2.0*pi/n), sin(2.0*pi/n));
	for(int i = 0; i<n; i++){
		if(i < n/2) a[i] = lft[i] + nw * rght[i];
		else{
			a[i] = lft[i-n/2] + nw * rght[i-n/2];
		}
		nw = nw * b;
	}
	return a;
}

vl inversefft(vl a){
	if(a.size()==1) return a;
	vl lft, rght;
	for(int i = 0; i<a.size(); i++){
		if(i&1) rght.push_back(a[i]);
		else lft.push_back(a[i]);
	}
	lft = inversefft(lft);
	rght = inversefft(rght);
	base nw(-1);
	int n = a.size();
	base b = base(cos(2.0*pi/n), sin(2.0*pi/n));
	for(int i = 0; i<n; i++){
		if(i < n/2) a[i] = lft[i] + nw * rght[i];
		else{
			a[i] = lft[i-n/2] + nw * rght[i-n/2];
		}
		a[i]/=n;
		nw = nw * b;
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
	while(ret.back()==0 && ret.size()) ret.pop_back();
	return ret;
}
int main()
{
	auto ans = multiply({1, 2, 3}, {1, 2, 3});
	for(int x : ans) cout << x << " .. ";
	cout << endl;
	return 0;
}