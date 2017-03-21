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
#define hi printf("hi!\n")
#define sf scanf
#define sf1(a) scanf("%d",&a)
#define sf2(a,b) scanf("%d %d",&a,&b)
#define sf3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define pcase(x) printf("Case %d: ",x)
#define REP(i,m) for(int i=0;i<=(m);i++)
using namespace std;
typedef long long int lint;
typedef double dbl;
int main()
{

    vector<int> :: iterator it;
    int n,k,m,a,temp;
    sf3(n,k,m);
    vector<int> vt(m);
    for(int i=m-1;i>-1;i--){
        sf1(a);
        vt[i]=a;
    }
    int ans=0;
    REP(i,n-1){
        REP(j,k-1)
        {
            sf1(a);
            for(it=vt.begin();it<vt.end();it++)
                if(*it==a){
                    ans+=m-(it-vt.begin());
                    temp=*it;

                    vt.erase(it);
                    vt.pb(temp);
                    break;
                }

        }
    }
    pf("%d\n",ans);

    return 0;
}
/*
4 4 4

1 2 3 4

3 4 2 1

4 3 2 1

4 1 2 3

4 1 2 3
*/
