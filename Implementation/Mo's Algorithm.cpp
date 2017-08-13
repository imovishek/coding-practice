/*input
5 3 1
1 1 1 1 1
1 5
2 4
1 3
*/

#include<bits/stdc++.h>
using namespace std;
#define mx 200005
int SQ;
struct data{
	int l, r, idx;
	bool operator < (const data &a) const{
		if(l/SQ == a.l/SQ) return r < a.r;
		else return l/SQ < a.l/SQ;
	}
}Q[mx];
int ara[mx];
int cnt[7000005];
long long ans[mx];
long long counti = 0;
int k;
inline void add(int i)
{
	counti += 0ll + cnt[ara[i] ^ k];
	cnt[ara[i]]++;
}
inline void remove(int i)
{
	cnt[ara[i]]--;
    counti -= 0ll + cnt[ara[i] ^ k];
}

int main()
{
    int n, m;
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 1; i<=n; i++){
    	scanf("%d", &ara[i]);
        ara[i] ^= ara[i-1];
    }
    for(int i = 0; i<m; i++){
    	scanf("%d %d", &Q[i].l, &Q[i].r);
        Q[i].l--;
    	Q[i].idx = i;
    }
    SQ = sqrt(n);
    sort(Q, Q+m);
    
    int prevL = 0, prevR = 0;
    cnt[0] ++;
    for(int i = 0; i<m; i++)
    {
    	while(prevL < Q[i].l)
    		remove(prevL++);
    	while(prevL > Q[i].l)
    		add(--prevL);
    	while(prevR < Q[i].r)
    		add(++prevR);
    	while(prevR > Q[i].r)
    		remove(prevR--);
    	ans[Q[i].idx] = counti;
    }

    for(int i = 0; i<m; i++)
    	printf("%lld\n", ans[i]);

	return 0;
}