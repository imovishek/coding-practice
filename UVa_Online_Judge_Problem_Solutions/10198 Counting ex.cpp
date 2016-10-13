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
char fib[2007][1007];
char sumi[1007], sumi2[1007];
void strsum(char a[], char b[], char sum[])
{
    int c = 0, i;
    for(i = 0; a[i] ; i++)   // a[] er shob digit jug kora hobe
    {
        int temp = 0;
        if(b[i]==0) temp = '0';   // jodi b[] shesh hoye jay? tai...
        temp += a[i] - '0' + b[i] - '0' + c;
        sum[i] = temp%10 + '0';
        c = temp/10;
    }
    while(c)   // jodi carry thake
    {
        int temp = 0;
        if(b[i]==0) temp = '0';
        temp += b[i] - '0' + c;
        sum[i] = temp%10+'0';
        c = temp/10;
        i++;
    }
    while(b[i]) sum[i] = b[i++];   // jodi b[] onek lomba hoy a[] shesh  carry o shesh but b[] roise... tai b[] direct sum[] cole asbe
}
void fibo()
{
    fib[0][0] = '1';
    fib[1][0] = '2';
    fib[2][0] = '5';
    for(int i = 3; i<2007 ; i++)
    {
        strsum(fib[i-1], fib[i-1], sumi);
        strsum(fib[i-2], fib[i-3], sumi2);
        strsum(sumi2, sumi, fib[i]);
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t, tst = 1;
    int n;
    fibo();
    while(sf1(n)!=EOF)
    {
        char *p = fib[n];
        int l = strlen(p);
        while(l--) pf("%c",p[l]);
        pf("\n");
    }

    return 0;
}

