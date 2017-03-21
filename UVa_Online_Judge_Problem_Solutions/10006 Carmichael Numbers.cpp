#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<climits>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#define pii pair<int,int>
#define mp make_pair
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
bool mark[65010];
int pirme[65010];
void sieve()
{
    int sq = sqrt(65010);
    for(int i=4; i<65010; i+=2) mark[i] = 1;
    for(int i = 3; i<=sq ; i+=2)
        if(!mark[i])
            for(int j = i*i; j<65010; j+=i+i)
                mark[j] = 1;
}
int mod(int b, int p, int m)
{
    if(p==0) return 1;
    if(p%2==1)
        return (b*mod(b, p-1, m))%m;
    int mo = mod(b, p/2, m);
    return (mo*mo)%m;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t, tst = 1;
    int n;
    sieve();
//   for(n = 2; n<=65000; n++)
    while(sf1(n) && n)
    {
        if(mark[n]){
                int f = 0;
                for(int i = 2; i<n ; i++)
                    if(__gcd(i,n)==1 && 1!=mod(i, n-1, n)){f++;pf("%d\n",i);}
//                    else if(__gcd(i, n)==1 && i==mod(i, n, n)) pf("%d Carmichael for %d\n",n,i);
                if(!f)pf("%d\n",n);
//                else pf("%d is normal\n",n);
        }
//        else pf("%d is normal\n",n);
    }
    return 0;
}


//#include<cstdio>
//#include<cstring>
//#include<cstdlib>
//#include<cmath>
//#include<climits>
//#include<iostream>
//#include<algorithm>
//#include<vector>
//#include<stack>
//#include<queue>
//#include<map>
//#define pii pair<int,int>
//#define mp make_pair
//#define fs first
//#define sc second
//#define pb push_back
//#define ppb pop_back()
//#define pf printf
//#define pf1(a) printf("%d\n",a);
//#define hi printf("hi!\n");
//#define sf scanf
//#define sf1(a) scanf("%d",&a)
//#define sf2(a,b) scanf("%d %d",&a,&b)
//#define sf3(a,b,c) scanf("%d %d %d",&a,&b,&c)
//#define pcase(x) printf("Case %d: ",x)
//#define MX 1000000007
//#define inf 2147483647
//#define mem(arr,x) memset((arr), (x), sizeof((arr)));
//#define FOR(i,x) for(int i=0;i<(x); i++)
//
//using namespace std;
//typedef long long int lint;
//typedef double dbl;
//
//int main()
//{
////    freopen("input.txt", "r", stdin);
////    freopen("output.txt", "w", stdout);
//    int t, tst = 1;
//    int n;
//    int ara[]={
//        561,
//        1105,
//        1729,
//        2465,
//        2821,
//        6601,
//        8911,
//        10585,
//        15841,
//        29341,
//        41041,
//        62745
//    };
//    while(sf1(n) && n)
//    {
//        int f=0;
//        FOR(i, 12)
//            if(ara[i]==n){f=1;break;}
//        if(f) pf("The number %d is a Carmichael number.\n",n);
//        else pf("%d is normal.\n",n);
//    }
//    return 0;
//}


