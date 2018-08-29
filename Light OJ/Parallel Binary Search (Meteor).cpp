#include<bits/stdc++.h>
using namespace std;
#define mx 300005
#define ll long long
ll tree[mx];
inline void update(int idx, int val){
    while(idx < mx) tree[idx] += val, idx += idx & -idx;
}
inline ll query(int idx){
    ll ret = 0;
    while(idx > 0) ret += tree[idx], idx -= idx & -idx;
    return ret;
}
int main()
{
//    double sum = 0;
//    for(int i = 1; i<=1000; i++){
//        double naturalLog = log(i*1.0);
//        sum += 1.0/i;
//        printf("%.10lf %.10lf\n", sum, naturalLog);
//        if(abs(sum - naturalLog) <= .58f){
//            printf("%d YES\n", i);
//        } else{
//            printf("%d NO\n", i);
//        }
//    }
    int n, m;
    scanf("%d %d", &n, &m);
    int ara[n+1], o[m+1];
    vector<int> sector[n+1];
    for(int i = 1; i<=m; i++)
    {
        scanf("%d", &o[i]);
        sector[o[i]].emplace_back(i);
    }
    for(int i = 1; i<=n; i++){
        scanf("%d", &ara[i]);
    }
    int q;
    scanf("%d", &q);
    int ql[q+1], qr[q+1], qw[q+1];
    for(int i = 1; i<=q; i++){
        scanf("%d %d %d", &ql[i], &qr[i], &qw[i]);
    }
    vector<int> v[q+1];
    int l[n+1], r[n+1];
    for(int i = 1; i<=n; i++) {
        l[i] = 1;
        r[i] = q;
    }
    for(int iter = 0; iter < 20; iter++)
    {
        for(int i = 1; i<=n; i++){
            if(l[i] > r[i]) continue;
            v[(l[i] + r[i])/2].emplace_back(i);
        }
        for(int i = 1; i<=m; i++) tree[i] = 0;
        for(int i = 1; i<=q; i++){
            if(ql[i] <= qr[i]){
                update(ql[i], qw[i]);
                update(qr[i]+1, -qw[i]);
            } else{
                update(ql[i], qw[i]);
                update(1, qw[i]);
                update(qr[i]+1, -qw[i]);
            }
            for(int idx : v[i]){
                ll sum = 0;
                if(l[idx]>r[idx]) continue;
                for(int x : sector[idx])
                {
                    sum += query(x);
                    if(sum >= ara[idx]) break;
                }
                if(sum >= ara[idx]) r[idx] = i - 1;
                else l[idx] = i + 1;
            }
            v[i].clear();
        }
    }
    for(int i = 1; i<=n; i++){
        if(r[i] == q) printf("NIE\n");
        else printf("%d\n", r[i]+1);
    }
    return 0;
}
