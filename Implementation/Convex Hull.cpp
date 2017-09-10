/*input
5
30 60 
100 55 
130 55 
115 20 
75 70 

*/

#include <bits/stdc++.h>
using namespace std;

#define mx 100005
#define ll long long
#define MOD 1000000007
double INF = 1e100;
double EPS = 1e-12;

struct PT { 
  ll x, y; 
  PT() {}
  PT(ll x, ll y) : x(x), y(y) {}
  PT(const PT &p) : x(p.x), y(p.y)    {}
  PT operator + (const PT &p)  const { return PT(x+p.x, y+p.y); }
  PT operator - (const PT &p)  const { return PT(x-p.x, y-p.y); }
  PT operator * (ll c)     const { return PT(x*c,   y*c  ); }
  PT operator / (ll c)     const { return PT(x/c,   y/c  ); }
};

ll dot(PT p, PT q)     { return p.x*q.x+p.y*q.y; }
ll dist2(PT p, PT q)   { return dot(p-q,p-q); }
ll cross(PT p, PT q)   { return p.x*q.y-p.y*q.x; }
ostream &operator<<(ostream &os, const PT &p) {
  os << "(" << p.x << "," << p.y << ")"; 
}
PT ara[mx];
bool cmp(const PT &a, const PT &b)
{
	if(cross(a - ara[0], b - ara[0])) return cross(a - ara[0], b - ara[0]) > 0;
	else return dist2(a, ara[0]) < dist2(b, ara[0]);
}
vector<PT> convex_hull(vector<PT> ara)
{
	int n = ara.size();
	int l = 0;
	for(int i = 0; i<n; i++)
	{
		if((ara[l].y == ara[i].y && ara[l].x > ara[i].x) || ara[l].y > ara[i].y) l = i;
	}
	swap(ara[0], ara[l]);
	sort(ara.begin() + 1, ara.end(), cmp);
		
	stack<PT> st;
	st.push(ara[0]);
	st.push(ara[1]);

	for(int i = 2; i<n; i++)
	{
		PT c = ara[i];
		while(st.size() >= 2)
		{
			PT b = st.top();
			st.pop();
			PT a = st.top();
			if(cross(b-a, c-b) > 0) {
				st.push(b);
				break;
			}
		}
		st.push(c);
	}
	vector< PT > vt;
	while(!st.empty())
	{
		vt.push_back( st.top() );
		st.pop();
	}
	if(vt.size() == 2) vt.erase(vt.begin()); // no convex
	return vt;
}
int main()
{
		int n;
		scanf("%d", &n);
		vector< PT > ara(n);
		for(int i = 0; i<n; i ++){
			scanf("%lld %lld", &ara[i].x, &ara[i].y);
		}
		vector<PT> convex = convex_hull(ara);
		for(PT a : convex)
			cout << a.x << " " << a.y << endl;
	return 0;
}