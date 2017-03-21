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
#define pi acos(-1.0)
using namespace std;
typedef long long int lint;
typedef double dbl;

int main()
{
    int n,k;
    sf2(k,n);
    pii ara[n+1], mon[k+1];
     for(int i=0;i<k;i++)
        sf2(mon[i].fs, mon[i].sc);
    for(int i=0;i<n;i++)
        sf2(ara[i].fs, ara[i].sc);

    double slop,slop2;
    int x1,y1,x2,y2;
    int flag=0, counti=n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<k;j++)
        {
            slop=atan2((ara[i].sc-mon[j].sc),(ara[i].fs-mon[j].fs));
            flag=0;
            for(int m=0;m<n;m++)
            {
                if(m==i)continue;
                slop2=atan2((ara[m].sc-mon[j].sc),(ara[m].fs-mon[j].fs));
                if(slop==slop2){
                        x1=ara[i].fs - mon[j].fs;
                        x2=ara[i].fs - ara[m].fs;
                        y1=ara[i].sc - mon[j].sc;
                        y2=ara[i].sc - ara[m].sc;
                    if(((x1>=0 && (ara[m].fs>=mon[j].fs && ara[m].fs<=ara[i].fs)) ||
                        (x1<=0 && (ara[m].fs<=mon[j].fs && ara[m].fs>=ara[i].fs))) /*&& ((y1>=0 && (ara[m].sc>=mon[j].sc && ara[m].sc<=ara[i].sc)) || (y1<=0 && (ara[m].sc<=mon[j].sc && ara[m].sc>=ara[i].sc)))*/
                       ) {flag=1; pf("%d %d -- %d %d -- %d %d**\n",ara[i].fs,ara[i].sc,ara[m].fs,ara[m].sc,mon[j].fs,mon[j].sc);break;}
                }
            }
            if(!flag)break;
        }
        if(flag) counti--;
    }
    pf("%d\n",counti);

    return 0;
}
