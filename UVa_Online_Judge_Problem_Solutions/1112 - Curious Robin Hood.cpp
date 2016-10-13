#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#define pii pair<int,int>
#define fs first
#define sc second
#define pb push_back
#define ppb pop_back()
#define pf printf
#define hi printf("hi!\n");
#define sf scanf
#define sf1(a) scanf("%d",&a)
#define sf2(a,b) scanf("%d %d",&a,&b)
#define sf3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define pcase(x) printf("Case %d:\n",x)
#define pi acos(-1.0)
using namespace std;
typedef long long int lint;
typedef double dbl;
lint ara[100007];
lint tree[300007];
void update(int node , int b, int e, int i, int newval,int sig)
{
    if(b==e)
    {
        if(i==-1) tree[node]=ara[b];
        else if(sig==1 && b==i) {tree[node]=0;ara[i]=0;}
        else if(b==i) {
                tree[node]+=newval;
                ara[i]+=newval;
        }
        return;
    }
    if(i!=-1 && (b>i || e<i))return;
    int mid=(b+e)/2, Left=node*2;
    update(Left, b, mid, i, newval, sig);
    update(Left+1, mid+1, e, i, newval, sig);
    tree[node]=tree[Left]+tree[Left+1];
}

lint query(int node, int b, int e, int i, int j)
{
    if(j<b || i>e) return 0;
    if(i<=b && j>=e) return tree[node];
    int mid=(b+e)/2, Left=node*2;
    return query(Left, b, mid, i, j) + query(Left+1, mid+1, e, i, j);
}
int main()
{
    int t, tst=1;
    sf1(t);
    while(t--)
    {
        int n,q,sig,b,e,indx,newval;
        sf2(n,q);
        for(int i=1;i<=n;i++)sf("%I64d",&ara[i]);
        update(1, 1, n, -1, 0,0);
        pcase(tst++);
        for(int i=0;i<q;i++)
        {
            sf1(sig);
            switch(sig){
            case 1:
                sf1(indx);
                pf("%I64d\n",ara[indx+1]);
                update(1, 1, n, indx+1, 0, 1);
                break;
            case 2:
                sf2(indx,newval);
                update(1, 1, n, indx+1, newval, 0);
                break;
            case 3:
                sf2(b, e);
                pf("%I64d\n",query(1,1,n,b+1,e+1));
                break;
            }
        }
    }
    return 0;
}
