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


int main()
{
    int t, tst = 1;
    sf1(t);
    while(t--)
    {
        int a, b, c;
        sf3(a, b, c);
        int flag = 0;
        if(b-a == c-b){
            flag = 1;
            if((double)b/a == (double)c/b) flag = 3;
        }
        else if((double)b/a == (double)c/b){
                flag = 2;
        }
        pcase(tst++);
        switch(flag)
        {
            case 0:
                pf("None\n");
                break;
            case 1:
                pf("Arithmetic Progression\n");
                break;
            case 2:
                pf("Geometric Progression\n");
                break;
            case 3:
                pf("Both\n");
                break;
        }

    }
    return 0;
}

