/*
OVISHEK PAUL, CSE - 15, SUST

*/

#include<bits/stdc++.h>
#define pii             pair<int,int>
#define mkp             make_pair
#define fs              first
#define sc              second
#define pb              push_back
#define ppb             pop_back()
#define pf              printf
#define pf1(a)          printf("%d\n",a)
#define hi              printf("hi!\n");
#define sf              scanf
#define sf1(a)          scanf("%d",&a)
#define sf1ll(a)        scanf("%lld",&a)
#define pcase(x)        printf("Case %d: ",x)

using namespace std;
typedef long long int lint;
typedef double dbl;


int main()
{
#ifdef OVI
        // freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
#endif // OVI

    int t, tst = 1;
    sf1(t);
    while(t--)
    {
        lint n;
        sf1ll(n);
        pcase(tst++);
        pf("%lld\n", n/2);
    }
    return 0;
}














