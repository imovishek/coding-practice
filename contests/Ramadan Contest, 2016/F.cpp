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
#define mp make_pair
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
using namespace std;
typedef long long int lint;
typedef double dbl;
int main()
{
    int t,tst=1;
    sf("%d",&t);
    while(t--)
    {
        int h1,m1,h2,m2,ansh=0,ansm=0;
        sf("%d:%d",&h1,&m1);
        sf("%d:%d",&h2,&m2);
        if(h2<h1 || (h2==h1 && m2<m1)){
            ansh+=24;
        }
        if(m2<m1){h2--;m2+=60;}
        pcase(tst++);
        ansh+=h2-h1;
        ansm+=m2-m1;
        pf("%d hours %d minutes\n",ansh,ansm);
    }
    return 0;
}

