#include<stdio.h>
#include<string.h>
int main()
{

    char ara[1050];
    int i,j,k,min,frq[128],nf=0;
    while(gets(ara))
    {
        if(nf)printf("\n");
        nf=1;
        memset(frq,0,sizeof(frq));
        for(i=0;ara[i];i++)
        {
            frq[ara[i]]++;
        }
        for(i=32;i<128;i++)
        {
            if(frq[i]==0)frq[i]=2147483647;
        }
        for(i=127;i>31;i--)
        {
            min=2147483647;
            for(j=127;j>31;j--)
            {
                if(frq[j]<min){min=frq[j];k=j;}
            }
            if(min==2147483647)break;
            printf("%d %d\n",k,min);
            frq[k]=2147483647;

        }

    }

    return 0;
}
