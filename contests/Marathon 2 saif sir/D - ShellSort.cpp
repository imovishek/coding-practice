#include<bits/stdc++.h>
#define pii pair<int,int>
#define mkp make_pair
#define fs first
#define sc second
#define pb push_back
#define ppb pop_back()
#define pf printf
#define pf1(a) printf("%d\n",a)
#define hi printf("hi!\n");
#define sf scanf
#define sf1(a) scanf("%d",&a)
#define sf2(a,b) scanf("%d %d",&a,&b)
#define sf3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define pcase(x) printf("Case %d: ",x)
#define MX 1000000007
#define inf 1000000007
#define pi acos(-1.0)
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
        string a[n], b[n];
        getchar();
        FOR(i, n) getline(cin, a[i]);
        FOR(i, n) getline(cin, b[i]);
        int x = n-1;
        for(int i = n-1; i>=0 ; i--)
        {
            int j;
            for( j = x ; j>=0; j--)
            {
                if(a[j]==b[i]){x=j-1; break;}
            }
            if(j==-1) {
                for(int k = i; k>=0 ; k--)
                    pf("%s\n", b[k].c_str());
                break;
            }
        }
        pf("\n");
    }
    return 0;
}














