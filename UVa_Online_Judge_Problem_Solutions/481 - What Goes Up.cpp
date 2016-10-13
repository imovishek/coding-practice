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
#define pcase(x) printf("Test #%d:\n",x)
#define pi acos(-1.0)
#define mem(arr,x) memset((arr), (x), sizeof((arr)));
#define FOR(i,x) for(int i=0;i<(x); i++)
using namespace std;
typedef long long int lint;
typedef double dbl;
int ara[100007],endi[100007],dir[100007];
int n;
bool compare(int u, int v)
{
    if(ara[u]< ara[v]) return true;
    return false;
}
int binary_s(int p, int q, int key)
{
    int mid;
    while(p<q){
        mid=(p+q)/2;
        if(ara[endi[mid]] > key) q = mid-1;
        else if(ara[endi[mid]] < key) p = mid+1;
        else return mid;
    }
    if(ara[endi[q]]>=key)return q;
    if(ara[endi[q]]<key) return q+1;

}
int LIS()
{
    int length=1,l;
    endi[0]=0;
    dir[0]=-1;
    for(int i=1;i<n;i++)
    {
        if(ara[i]<ara[endi[0]]){
            endi[0]=i;
            dir[i]=-1;
        }
        else if(ara[i]>ara[endi[length-1]]){
            dir[i]=endi[length-1];
            endi[length++]=i;
        }
        else {
            l=binary_s(0,length-1,ara[i]);
            dir[i]=endi[l-1];
            endi[l]=i;
        }
    }
    return length;
}
void printpath(int u)
{

    if(u==-1)return;
    printpath(dir[u]);
    pf("%d\n",ara[u]);
}
int main()
{
        int x;
        n=0;
        while(sf1(ara[n])!=EOF)n++;
        if(n==0)return 0;
            int maxi=0;
            int pos=0;

            maxi=LIS();
            pf("%d\n-\n", maxi);
            printpath(endi[maxi-1]);

        return 0;
    }
    /*
2
5
3
7
11
8
10
13
6
0
1
2
3
4
5
-1

    */
