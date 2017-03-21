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
        int n;
        sf1(n);
        pcase(tst++);
        stack < int > st;
        int flag = 0;
        int i;
        for(i = 1; i*i<n; i++)
        if(n%i==0){
            if(flag) pf(" ");
            flag = 1;
            pf("%d",i);
            st.push(n/i);
        }
        if(i*i==n){
            if(flag) pf(" ");
            flag = 1;
            pf("%d",i);
        }
        while(!st.empty())
        {
            pf(" %d",st.top());
            st.pop();
        }
        puts("");
    }
    return 0;
}

