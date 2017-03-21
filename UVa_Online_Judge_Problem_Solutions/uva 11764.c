#include<stdio.h>
int main()
{

    int i,n,a1,a,b,h,l;
scanf("%d",&n);
for(i=1;i<=n;i++)
{
    h=0;l=0;
    scanf("%d",&a1);
    scanf("%d",&b);
    a1--;
    while(a1--)
    {
        scanf("%d",&a);
        if(a>b)h++;
        else if(a<b)l++;
        b=a;
    }
    printf("Case %d: %d %d\n",i,h,l);
}
    return 0;

}
