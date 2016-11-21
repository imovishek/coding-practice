#include<stdio.h>
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int test,i,j,min,ara[7];
    double sum;
    scanf("%d",&test);
    for(i=1;i<=test;i++)
    {
        sum=0;
        for(j=0;j<7;j++){scanf("%d",&ara[j]);if(j<4)sum+=ara[j];}
        min=ara[4];
        if(min>ara[5]){min=ara[5];}
        if(min>ara[6]){min=ara[6];}
        sum=sum+(ara[4]+ara[5]+ara[6]-min)/2.0;
        if(sum>=90)printf("Case %d: A\n",i);
        else if(sum>=80)printf("Case %d: B\n",i);
        else if(sum>=70)printf("Case %d: C\n",i);
        else if(sum>=60)printf("Case %d: D\n",i);
        else printf("Case %d: F\n",i);

    }

    return 0;
}
