#include<stdio.h>
int main()
{

 freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int i,j,b,p,m,mod,mult;
    char ara[35];
    while(scanf("%d %d %d",&b,&p,&m)!=EOF)
    {
        ara[0]='0';
        mult=1;
        for(i=0;p>0;i++)
        {
            ara[i]=p%2+'0';
            p/=2;
        }

        mod=b%m;
        if(ara[0]=='1')mult=mod;
        for(j=1;j<i;j++)
        {
            mod=(mod*mod)%m;
            if(ara[j]=='1'){
                    mult=mult*mod;
                    if(mult>=m)mult=mult%m;
            }

        }

        printf("%d\n",mult);
    }
    return 0;
}
