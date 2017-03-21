
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int nbook,i,j,i1,j1,bprice,abst;
    while(1==scanf("%d",&nbook)){




    int ara[nbook];
    for(i=0;i<nbook;i++)
    {
        scanf("%d",&ara[i]);
    }
    scanf("%d",&bprice);
    abst=bprice;
    for(i=0;i<nbook-1;i++)
    {
        for(j=i+1;j<nbook;j++)
        {
            if(ara[i]+ara[j]==bprice && abst>abs(ara[i]-ara[j])){i1=i;j1=j;abst=abs(ara[i]-ara[j]);}
        }


    }

    if(ara[i1]>ara[j1]) printf("Peter should buy books whose prices are %d and %d.\n\n",ara[j1],ara[i1]);
    else printf("Peter should buy books whose prices are %d and %d.\n\n",ara[i1],ara[j1]);
    }
    return 0;
}
