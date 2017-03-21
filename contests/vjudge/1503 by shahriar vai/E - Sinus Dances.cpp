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
using namespace std;
typedef long long int lint;
typedef double dbl;
char str[50]="\0";
char ara[10000]="",ch,wh[1000000]="";
int n,z=1;
void consA(int now)
{
    if(now&1)ch='-';
    else ch='+';
    sprintf(str,"sin(%d%c",now,ch);
    if(n==now){
        sprintf(str,"sin(%d",now);
        strcat(ara,str);
        strcat(ara,")");
        return;
    }
    strcat(ara,str);
    consA(now+1);
    strcat(ara,")");
}
void cosS(int now)
{
    n=z;
    consA(1);
    z++;
    sprintf(str,"+%d",now);
    strcat(wh,ara);
    strcat(wh,str);
    ara[0]=0;
    str[0]=0;
    if(now==1)
    {
        return;
    }
    strcat(wh,")");
    cosS(now-1);
}
int main()
{
    int temp;
    scanf("%d",&n);
        temp=n-1;
        cosS(n);
        for(int i=0;i<temp;i++)printf("(");
        printf("%s\n",wh);
        ara[0]=0;
        wh[0]=0;
        z=1;

    return 0;
}
