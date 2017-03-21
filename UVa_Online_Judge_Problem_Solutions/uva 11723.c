#include<stdio.h>
int main()
{
    int i,r,n,rem,div,ans;

    for(i=1;scanf("%d %d",&r,&n)!=EOF;i++)
    {
        if(r==0 && n==0)break;
       div=r/n;
       rem=r%n;
       if(rem==0)ans=div-1;
       else ans=div;
       if(r==0)ans=0;
       if(ans<=26)printf("Case %d: %d\n",i,ans);
       else printf("Case %d: impossible\n",i);

    }
    return 0;
}
