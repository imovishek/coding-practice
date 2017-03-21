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
#define pi acos(-1)
using namespace std;
typedef long long int lint;
typedef double dbl;
int main()
{
    int t;
    char ara[100];
    sf1(t);
    getchar();
    while(t--)
    {
        gets(ara);
        int flag=0,flag2=0,flag3=0;
        for(int i=0;ara[i];i++){
            if(flag==0 && ara[i]>='0' && ara[i]<='9')flag=1;
            else if(flag && flag2==0 &&ara[i]==' ')flag2=1;
            else if(flag2 && !flag3 && ara[i]>='0' && ara[i]<='9'){flag3=1;break;}
        }
        if(flag3){
            int r1,r2;
            sscanf(ara,"%d %d",&r1,&r2);
            double R=(r1+r2);
            double area=pi*R*R-(double)pi*r1*r1-(double)pi*r2*r2;
            pf("%.4lf\n",area);
        }
        else pf("Impossible\n");
    }
    return 0;
}
