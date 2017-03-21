#include <stdio.h>


int main()
{
    int i,n,ara[6],flag,res;
    char str[700];
    scanf("%d",&n);
    getchar();
        while (n--)
        {
            flag=0;
            for(i=0;i<6;i++)ara[i]=0;
            gets(str);
            for(i=0;str[i];i++)
            {
                if(str[i]=='M')ara[0]++;
                else if(str[i]=='A')ara[1]++;
                else if(str[i]=='R')ara[2]++;
                else if(str[i]=='G')ara[3]++;
                else if(str[i]=='I')ara[4]++;
                else if(str[i]=='T')ara[5]++;
            }
            ara[1]/=3;ara[2]/=2;
            for(i=0;i<6;i++)if(ara[i]==0)flag=1;
            if(flag)res=0;
            else {
                    res=ara[0];
                    for(i=1;i<6;i++)if(res>ara[i])res = ara[i];

            }
            printf("%d\n",res);
            }

    return 0;
}
