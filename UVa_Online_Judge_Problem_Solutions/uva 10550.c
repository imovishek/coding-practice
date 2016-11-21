#include<stdio.h>
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int a,b,c,d,sum;
    while(scanf("%d %d %d %d",&a,&b,&c,&d)!=EOF)
    {
        if(a==0 && b==0 && c==0 && d==0)break;
        sum=720;
        a=(40-b+a)%40;
        sum+=9*a+360;
        b=(40-b+c)%40;
        sum+=9*b;
        c=(40-d+c)%40;
        sum+=9*c;
        printf("%d\n",sum);
    }
    return 0;
}
