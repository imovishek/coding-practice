#include<stdio.h>
int main()
{
    int i,t,n,p,k,a,count;
    scanf("%d",&t);
    for(i=1;i<=t;i++){
    scanf("%d %d %d",&n,&p,&k);
    count=0;
    while(n--)
    {
        scanf("%d",&a);
        k=k-a;
        if(k>=0 && count<p)count++;
        else {scanf("%*[^\n]s");break;}
    }
    printf("Case %d: %d\n",i,count);
    }
    return 0;
}
