/*input
-15 -10 15 10 5
-20 7 9
-2 3 6
8 -3 4
-1 -8 3
-9 -1 3
2 10 18 30 3
10 20 5
10 29 5
10 11 5
2 10 18 30 3
10 20 5
10 25 5
10 10 5

*/

#include<bits/stdc++.h>
using namespace std;
#define EPS 1e-6
#define pi acos(-1.0)
int cmp(double x)
{
    if(fabs(x) < EPS) return 0;
    return x < 0 ? -1 : 1;
}
struct PT{
    double x, y;
    PT(){x = y = 0; }
    PT(double _x, double _y) {x = _x, y = _y; }
    PT operator-(const PT &a) const{
        return PT(x - a.x, y - a.y);
    }
    PT operator+(const PT &a) const{
        return PT(x + a.x, y + a.y);
    }
    PT operator*(double a) const{
        return PT(x * a, y * a);
    }
    PT operator/(double a) const{
        return PT(x / a, y / a);
    }
    double val()
    {
        return sqrt(x * x + y * y);
    }
    PT unit()
    {
        return (*this) / val();
    }
    void scan()
    {
        scanf("%lf %lf", &x, &y);
    }
    void print()
    {
        printf("(%.4f, %.4f)", x, y);
    }
};
struct line{
    double a, b, c;
};

double dist(PT a, PT b)
{
    return (a - b).val();
}

double dist2(PT a, PT b)
{
    a = a - b;
    return a.x * a.x + a.y * a.y;
}
double dot(PT a, PT b)
{
    return a.x * b.x + a.y * b.y;
}
double cross(PT a, PT b)
{
    return a.x * b.y - a.y * b.x;
}
PT RotateCCW90(PT p)
{
    return PT(-p.y,p.x);
}
PT RotateCW90(PT p)
{
    return PT(p.y,-p.x);
}
PT RotateCCW(PT p, double t)
{
    return PT(p.x*cos(t)-p.y*sin(t), p.x*sin(t)+p.y*cos(t));
}
PT RotateCW(PT p, double t)
{
    return PT(p.x*cos(t)+p.y*sin(t), -p.x*sin(t)+p.y*cos(t));
}
vector<PT> CircleCircleIntersection(PT a, PT b, double r, double R)
{
    vector<PT> ret;
    double d = sqrt(dist2(a, b));
    if (d > r+R || d+min(r, R) < max(r, R)) return ret;
    double x = (d*d-R*R+r*r)/(2*d);
    double y = sqrt(r*r-x*x);
    PT v = (b-a)/d;
    ret.push_back(a+v*x + RotateCCW90(v)*y);
    // if (y > 0)
        ret.push_back(a+v*x - RotateCCW90(v)*y);
    return ret;
}
struct Circle
{
	PT c;
	double r;

	void scan()
	{
		c.scan();
		scanf("%lf", &r);
	}
};
double distFromSeg(PT a, PT b, PT c)
{
	if(dot(b-a, c-a) < 0) return dist(c, a);
	if(dot(a-b, c-b) < 0) return dist(c, b);
	if(cmp((b-a).val()) == 0) while(1);
	return fabs(cross(b-a, c-a)) / (b-a).val();
}
bool doesIntersect(Circle c, PT a, PT b)
{
	if(cmp(distFromSeg(a, b, c.c) - c.r) < 0) return true;
	return false;
}

int main()
{
	PT a, b;
	int n;
	while(scanf("%lf %lf %lf %lf %d", &a.x, &a.y, &b.x, &b.y, &n) == 5){

		Circle ara[n];
		pair<PT, PT> rec[4];
		rec[0] = {PT(a.x, a.y), PT(b.x, a.y)};
		rec[1] = {PT(b.x, a.y), PT(b.x, b.y)};
		rec[2] = {PT(b.x, b.y), PT(a.x, b.y)};
		rec[3] = {PT(a.x, b.y), PT(a.x, a.y)};
		if(cmp(dist(a, b)) == 0) {
			assert(0);
			continue;
		}
		for(int i = 0; i<4; i++)
		{
			if(cmp(dist(rec[i].first, rec[i].second)) == 0){
				while(1);
			}
		}
		int x = 0;
		for(int i = 0; i<n; i++)
		{
			Circle nw;
			nw.scan();
			if(cmp(nw.c.x - a.x) <= 0 || cmp(nw.c.x - b.x) >= 0 || cmp(nw.c.y - a.y) <= 0 || cmp(nw.c.y - b.y) >= 0)
			{
				int f = 0;
				for(int j = 0; j<4; j++){
					if(cmp(cross(rec[j].second-rec[j].first, nw.c-rec[j].first)) < 0 && cmp(distFromSeg(rec[j].first, rec[j].second, nw.c) - nw.r ) >= 0) f = 1;
				}
				if(f) continue; 
			}
			ara[x++] = nw;
		}
		n = x;
		if(n == 0){
			printf("YES\n");
			continue;
		}
		// cout << n << endl;
		// for(int i = 0; i<n; i++)
		// 	ara[i].c.print();
		// cout << endl;
		vector<int> edge[n];
		for(int i = 0; i<n; i++)
		{
			for(int j = i+1; j<n; j++)
			{
				if(cmp(dist(ara[i].c, ara[j].c) - (ara[i].r + ara[j].r)) < 0){
					int cnt = 0;
					vector<PT> vt = CircleCircleIntersection(ara[i].c, ara[j].c, ara[i].r, ara[j].r);
					if(vt.empty()) {
						edge[i].push_back(j);
						edge[j].push_back(i);
						continue;
					}
					int ej = 0;
					for(auto tm : vt){
						int f = 0;
						if(cmp(tm.x - a.x) <= 0 || cmp(tm.x - b.x) >= 0 || cmp(tm.y - a.y) <= 0 || cmp(tm.y - b.y) >= 0) f = 1;
						if(cmp(tm.x - a.x) == 0 || cmp(tm.x - b.x) == 0 || cmp(tm.y - a.y) == 0 || cmp(tm.y - b.y) == 0) ej++;
						cnt += f;
					}
					if(cnt < 2 || (cnt==2 && ej==cnt)){
						edge[i].push_back(j);
						edge[j].push_back(i);
						// cout << i << " " << j << endl;
					}

				}
			}
		}
		// cout << n << endl;
		int vis[n];
		memset(vis, 0, sizeof vis);
		queue<int> Q;
		set<int> st;
		for(int i = 0; i<n; i++)
		{
			if(doesIntersect(ara[i], rec[0].first, rec[0].second)){
				Q.push(i);
				vis[i] = 1;
			} else if(doesIntersect(ara[i], rec[1].first, rec[1].second)){
				Q.push(i);
				vis[i] = 1;
			}
			if(doesIntersect(ara[i], rec[2].first, rec[2].second)){
				st.insert(i);
			} else if(doesIntersect(ara[i], rec[3].first, rec[3].second)){
				st.insert(i);
			}
		}
		int ans = 1;
		while(!Q.empty())
		{
			int u = Q.front();
			Q.pop();
			if(st.count(u)) {ans = 0; break;}
			for(int v : edge[u])
			{
				if(vis[v] == 0){
					vis[v] = 1;
					Q.push(v);
				}
			}
		}
		if(ans) printf("YES\n");
		else printf("NO\n");

	}

	return 0;
}