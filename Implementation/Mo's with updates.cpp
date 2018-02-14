#include<bits/stdc++.h>
using namespace std;
#define mx 100005
const int BlockSize = 805;
struct Query{
    int l, r, q, lsq, rsq, idx;
    Query(int l, int r, int q, int idx) : l(l), r(r), q(q), idx(idx){
        lsq = l/BlockSize;
        rsq = r/BlockSize;
    }
    Query(){}
    bool operator<(const Query &a) const{
        if(lsq != a.lsq) return lsq < a.lsq;
        if(rsq != a.rsq) return rsq < a.rsq;
        return q < a.q;
    }
} query[mx];
struct Update{
    int idx, val, prev;
    Update(){}
    Update(int idx, int val, int prev) : idx(idx), val(val), prev(prev){}
}update[mx];
int ara[mx], cnt[mx];
int main()
{
    printf("hi");
    int n, m;
    scanf("%d", &n);
    for(int i = 1; i<=n; i++)
        scanf("%d", &ara[i]);
    scanf("%d", &m);
    int nowQuery = 0, nowUpdate = 0;
    for(int i = 0; i<m; i++){
        char ch;
        int l, r;
        scanf("%c %d %d", &ch, &l, &r);
        if(ch == 'Q'){
            query[nowQuery++] = Query(l, r, nowUpdate, i);
        } else{
            update[nowUpdate++] = Update(l, r, 0);
        }
    }
    sort(query, query + nowQuery);

    return 0;
}
