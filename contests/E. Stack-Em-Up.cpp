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
#define ppb pop_back
#define pf printf
#define hi printf("hi!\n");
#define sf scanf
#define sf1(a) scanf("%d",&a)
#define sf2(a,b) scanf("%d %d",&a,&b)
#define sf3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define pcase(x) printf("Case %d:\n",x)
using namespace std;
typedef long long int lint;
typedef double dbl;
int main()
{
    vector<int>U;
    int t,tst=1;
    cin >> t;
    while(t--)
    {
        int n,w,a;
        cin >> n >> w;
        char q;
        pcase(tst++);
        while(w--)
        {
            cin >> q;
            if(q=='P')
            {
                cin >> a;
                if(U.size()==n){
                    pf("Overflow!\n");
                }
                else U.pb(a);
            }
            else if(q=='R')
            {
                if(U.empty()) pf("No plates in stack!\n");
                else U.ppb();
            }
            else if(q=='S')
            {
                if(U.empty()) pf("No plates in stack!\n");
                else {
                    pf("%d",U[U.size()-1]);
                    for(int i=U.size()-2;i>=0;i--)
                        pf(" %d",U[i]);
                    pf("\n");
                }
            }
        }
    }
    return 0;
}
