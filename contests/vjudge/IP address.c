#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<inttypes.h>

int main()
{
    int t,test,i;
    scanf("%d",&t);
    t++;
    char ara[100];
    int num[4],num2[4],k=0;
    for(test=1;test<t;test++)
    {
        for(i=0;i<4;i++){num[i]=0;num2[i]=0;}
        scanf("%s",ara);
        k=0;
        for(i=0;ara[i];i++)
        {
            if(ara[i]=='.'){k++;continue;}
            num[k]=num[k]*10+ara[i]-'0';
        }

        scanf("%s",ara);
        k=0;
        for(i=0;ara[i];i++)
        {
            if(ara[i]=='.'){k++;continue;}
            num2[k]=num2[k]*2+ara[i]-'0';
        }
        printf("Case %d: ",test);
        if(num[0]==num2[0] &&  num[1]==num2[1] && num[2]==num2[2] && num[3]==num2[3])printf("YES\n");
        else printf("NO\n");

    }
    return 0;
}
