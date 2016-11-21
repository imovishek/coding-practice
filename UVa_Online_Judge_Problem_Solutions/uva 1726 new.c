#include<stdio.h>

int main()
{

    int test,j,i,n,aralc[10],araui[10],d,l,sum;
    char a;
    scanf("%d",&test);
    while(test--)
    {
        sum=0;
        for(i=0;i<10;i++){aralc[i]=0;araui[i]=0;}
        scanf("%d",&n);
        while(n--)
        {
            scanf("%d %d %c",&d,&l,&a);
            if(l==1 && a=='c')aralc[d-1]++;
            else if(l==0 && a=='i')araui[d-1]++;
        }
        for(i=0;i<10;i++)
            for(j=i+1;j<10;j++)
                sum=sum+aralc[j]*araui[i];
            printf("%d\n",sum);
    }


return 0;
}
