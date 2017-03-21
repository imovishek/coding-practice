#include<stdio.h>
int main()
{
    int i,ara[10],n,m,t,j,rem;
    scanf("%d",&t);
    while(t--){
            j=1;
        for(i=0;i<10;i++)ara[i]=0;

        scanf("%d",&n);
        m=n;
        while(n>0)
        {
            rem=n%10;
            n/=10;
            for(i=1;i<10;i++)ara[i]+=n*j;
            ara[0]+=(n-1)*j;
            ara[rem]+=m%j+1;
            while(rem>0)ara[--rem]+=j;
            j*=10;
        }
        for(i=0;i<9;i++)printf("%d ",ara[i]);
        printf("%d\n",ara[9]);
    }

    return 0;
}
