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
    lint sum=0,n;
    char sig;
    lint counti=0,num;
    cin >> n >> sum;
    while(n--)
    {
        cin >> sig >> num;
        if(sig=='-')
        {
            if(sum<num)counti++;
            else sum-=num;
        }
        else if(sig=='+') sum+=num;
    }
    pf("%I64d %I64d\n",sum,counti);
    return 0;
}
