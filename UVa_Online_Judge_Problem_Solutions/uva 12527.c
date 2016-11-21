#include<stdio.h>
int main()
{
int i,j,n,m,temp,rem,ara[10],count;

while(scanf("%d %d",&n,&m)!=EOF)
{
    count=0;

    for(i=n;i<=m;i++)
    {
        for(j=0;j<10;j++)ara[j]=0;
        temp=i;
        while(temp>0){
                rem=temp%10;
        if(ara[rem]!=0){count--;break;}
            ara[rem]++;temp/=10;
        }
        count++;

    }
    printf("%d\n",count);
}

return 0;
}
