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
#define pcase(x) printf("Case %d: ",x)
#define pi acos(-1.0)
using namespace std;
typedef long long int lint;
typedef double dbl;
#define mx 100
int ara[mx]={};
int tree[mx*3];
void init(int node, int b, int e)
{
    if(b==e)
    {
        tree[node]=ara[b];
        return;
    }
    int Left=node*2;
    int Right=Left+1;
    int mid=(b+e)/2;
    init(Left,b,mid);
    init(Right,mid+1,e);
    tree[node]=tree[Left]+tree[Right];
}

int query(int node, int b, int e, int i, int j)
{
    if(j<b || i>e) return 0;
    if(i<=b && j>=e)
        return tree[node];
    int Left=node*2;
    int Right=Left+1;
    int mid=(b+e)/2;
    return query(Left, b, mid, i, j) + query(Right, mid+1, e, i, j);
}

void update(int node, int b, int e, int i, int newval)
{
    if(i!=-1 && b>i || e<i) return;
    if(b==e)
    {
        if(i!=-1 && b==i)
            tree[node]=newval;
        else if(i==-1)
            tree[node]=ara[b];
        return;
    }
    int Left=node*2;
    int Right=Left+1;
    int mid=(b+e)/2;
    update(Left, b, mid, i, newval);
    update(Right, mid+1, e, i, newval);
    tree[node]=tree[Left]+tree[Right];
}
int main()
{
    int t,n,b,e;
    while(sf1(n)!=EOF)
    {
        for(int i=1;i<=n;i++)
            sf1(ara[i]);
        update(1,1,n,-1, 0);
        for(int i=1;i<=13;i++) pf("%d ",tree[i]); pf("\n");
        int indx, newval;
        while(sf2(indx,newval) && (indx && e))
        {
            update(1,1,n,indx, newval);
            for(int i=1;i<=13;i++) pf("%d ",tree[i]); pf("\n");

            sf2(b,e);
            pf("%d\n",query(1,1,n,b,e));
        }

    }
    return 0;
}

/*
7
4 -9 3 7 1 0 2
1 2
*/
