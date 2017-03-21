#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<inttypes.h>
typedef long long int lint;
int main()
{
    int n,i,j,t,b,a,w,ti;
    scanf("%d",&t);
    t++;
    for(i=1;i<t;i++)
    {
        a=0;
        w=0;
        b=0;
        ti=0;
        scanf("%d",&n);
        char ara[n+1];
        scanf("%s",ara);
        for(j=0;j<n;j++)
        {
            if(ara[j]=='B')b++;
            else if(ara[j]=='W')w++;
            else if(ara[j]=='A')a++;
            else if(ara[j]=='T')ti++;
        }
        printf("Case %d: ",i);
        if(a==n)printf("ABANDONED\n");
        else if(b==w)printf("DRAW %d %d\n",b,ti);
        else if(b+a==n)printf("BANGLAWASH\n");
        else if(w+a==n)printf("WHITEWASH\n");
        else if(b>w)printf("BANGLADESH %d - %d\n",b,w);
        else if(b<w)printf("WWW %d - %d\n",w,b);


    }

    return 0;
}
