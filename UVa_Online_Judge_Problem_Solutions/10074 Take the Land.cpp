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
int histogram(int ara[], int n)
{
    stack<pii> st;
    int maxi = 0;
    st.push(pii(ara[0],0));
    int i;
    for(i = 1; i<n ; i++)
    {
        if(st.top().fs<ara[i])st.push(pii(ara[i],i));
        else{
            int x;
            while(!st.empty() && st.top().fs>=ara[i])
            {
                maxi = max(maxi, st.top().fs*(i - st.top().sc));
                x = st.top().sc;
                if(!st.empty())st.pop();
            }
            st.push(pii(ara[i], x));
        }
    }
    while(!st.empty())
            {
                maxi = max(maxi, st.top().fs*(i - st.top().sc));
                st.pop();
            }
    return maxi;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t, tst = 1;
    int n, m;
//    pf("%d*\n",histogram(ara, 7));
    while(sf2(n, m))
    {
        if(n==0 && m==0) return 0;
        int ara[m];
        int maxi = 0;
        mem(ara, 0);
        FOR(i, n){
            FOR(j, m)
            {
                int a;
                sf1(a);
                if(a==0) ara[j]++;
                else ara[j] = 0;
            }
            maxi = max(histogram(ara, m), maxi);
        }
        pf("%d\n", maxi);
    }
    return 0;
}

