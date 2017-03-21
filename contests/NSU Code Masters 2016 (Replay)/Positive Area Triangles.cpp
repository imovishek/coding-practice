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
#define pf printf
#define sf scanf
#define pcase(x) printf("Case %d: ",x)
#define mini(x,y) (x<y)?x:y
using namespace std;
typedef long long int lint;
typedef double dbl;

lint nC(int n)
{
    if(n<3)return 0;
    return n*(n-1)*(n-2)/6;
}
int main()
{
    int n,m,mult;
    lint ans;
    while(scanf("%d %d",&n,&m)==2)
    {
        ans=0;
        n++,m++;
        mult=n*m;
        ans+=nC(mult)%1000000007;
        int mino=mini(n,m),diff=abs(m-n);
        lint sum=0;
        ans-=(m*nC(n)+n*nC(m));
        ans=ans%1000000007;
        if(ans<0)ans+=1000000007;
        if(ans<0)ans+=1000000007;
        for(int i=1;i<mino;i++)
        {
            sum+=nC(i);
            sum%=1000000007;
        }
        sum*=2;
        sum%=1000000007;
        sum+=nC(mino);
        sum+=(diff*nC(mino));
        sum%=1000000007;
        ans-=(2*sum);
        ans=ans%1000000007;
    if(ans<0)ans+=1000000007;
        printf("%lld\n",ans);

    }
    return 0;
}
