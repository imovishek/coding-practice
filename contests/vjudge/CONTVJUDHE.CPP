#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
using namespace std;
int ara[1000000],last;
void setall()
{
    int num=0,now=0;
    for(int i=0;i<100;i++)
    {
        num+=i;
        num%=3;
        if(num==0){ara[i]=++now;}
        else ara[i]=now;
        printf("%d %d\n",i,num);
    }
    last=num;
}
int main()
{
    setall();
    int t,te=1,n,m;
    scanf("%d",&t);
    while(t-- && scanf("%d %d",&n,&m)==2)
    {
        int counti=0;
        if(n<1000000 && m<1000000)
        {
            if(n==0 || (ara[n]!=ara[n-1]))
                printf("Case %d: %d\n",te++,ara[m]-ara[n]+1);
            else printf("Case %d: %d\n",te++,ara[m]-ara[n]);
        }
        else {
                int now=ara[999999],num=last;
                int ni,mi;
            if(n<1000000)ni=ara[n];
            else
            {

                for(int i=1000000;i<=n;i++)
                {
                    num+=i;
                    num%=3;
                    if(num==0)now++;
                }
                ni=now;
                if(num==0)ni--;
            }
            if(m<1000000)mi=ara[m];
            else
            {

                for(int i=n;i<=m;i++)
                {
                    num+=i;
                    num%=3;
                    if(num==0)now++;
                }
                mi=now;
            }
            printf("Case %d: %d\n",te++,ara[m]-ara[n]);
        }

    }
    return 0;
}
