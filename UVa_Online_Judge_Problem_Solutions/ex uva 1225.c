#include<stdio.h>
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int i,ara[10],n,j,t;
    scanf("%d",&t);
    while(t--){
        j=1;
        for(i=0;i<10;i++)ara[i]=0;
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            j=i;
            while(j>0){
            ara[j%10]++;
            j/=10;
            }

        }
        for(i=0;i<9;i++)printf("%d ",ara[i]);
        printf("%d\n",ara[9]);
    }

    return 0;
}

