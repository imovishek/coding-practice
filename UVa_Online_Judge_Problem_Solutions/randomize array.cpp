#include<bits/stdc++.h>
#define pii pair<int,int>
#define mkp make_pair
#define fs first
#define sc second
#define pb push_back
#define ppb pop_back()
#define pf printf
#define pf1(a) printf("%d\n",a);
#define hi printf("hi!\n");
#define sf scanf
#define sf1(a) scanf("%d",&a)
#define sf2(a,b) scanf("%d %d",&a,&b)
#define sf3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define pcase(x) printf("Case %d: ",x)
#define MX 1000000007
#define inf 2147483647
#define mem(arr,x) memset((arr), (x), sizeof((arr)));
#define FOR(i,x) for(int i=0;i<(x); i++)

using namespace std;
typedef long long int lint;
typedef double dbl;
void randarray(int a[], int n)
{

    srand(time(NULL));
    map<int, int>mp;
    int pos = 0;
    int ara[n];
    while(pos<n)
    {
        int x = rand()%n;
       if(mp[x]==0){
            mp[x]++;
            ara[pos++] = a[x];
       }
    }
    FOR(i, n) a[i] = ara[i];
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t, tst = 1;
    int n;
    sf1(t);
    while(t--)
    {
        sf1(n);
        int ara[n];
        FOR(i, n) sf1(ara[i]);
        randarray(ara, n);
        FOR(i, n) pf("%d ",ara[i]);
        pf("\n");

    }
    return 0;
}

