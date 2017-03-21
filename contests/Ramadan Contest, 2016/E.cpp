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
    char ara[50];
    int t,n,m;
    sf("%d",&t);
    while(t--)
    {
        sf("%s %d %d",ara,&n,&m);
        int digit,num=0;
        for(int i=0;ara[i];i++)
        {
            if(ara[i]>='0' && ara[i]<='9')digit=ara[i]-'0';
            else digit=ara[i]-'A'+10;
            num=num*n+digit;
        }
        int i;
        for( i=0;num;i++)
        {
            digit=num%m;
            if(digit<=9)ara[i]=digit+'0';
            else ara[i]=digit-10+'A';
            num/=m;
        }
        if(i==0){i++;ara[0]='0';}
        ara[i]=0;
        int len=i;
        char ch;
        for(i=0;i<len/2;i++)
        {
            ch=ara[i];
            ara[i]=ara[len-1-i];
            ara[len-1-i]=ch;
        }
        pf("%s\n",ara);
    }
    return 0;
}
