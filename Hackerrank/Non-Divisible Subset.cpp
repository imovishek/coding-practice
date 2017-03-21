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
#define inf 1000000007
#define mem(arr,x) memset((arr), (x), sizeof((arr)));
#define FOR(i,x) for(int i=0;i<(x); i++)

using namespace std;
typedef long long int lint;
typedef double dbl;


int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t, tst = 1;
    int n, k;
    sf2(n, k);
    int ara[k];
    mem(ara, 0);
    FOR(i, n){
        int a;
        sf1(a);
        ara[a%k]++;
    }

    if(k%2==0 && ara[k/2]) ara[k/2] = 1;
    if(ara[0])ara[0] = 1;
    int sum = 0;
    int x = k/2+1;
    for(int i = 0; i<k ; i++)
        sum+=ara[i];
    for(int i = x ; i<k ; i++)
        if(ara[k-i]){
            sum-=min(ara[i], ara[k-i]);
        }
    pf("%d\n",sum);
    return 0;
}

