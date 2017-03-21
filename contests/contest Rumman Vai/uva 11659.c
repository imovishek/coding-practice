#include<stdio.h>
int main()
{

//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int ara[21],n,l,a,b,i,count;
    while(scanf("%d %d",&n,&l)!=EOF && (n || l))
    {
        count=0;
        for(i=0;i<n;i++)ara[i]=1;
        for(i=0;i<l;i++)
        {
            scanf("%d %d",&a,&b);
            if(ara[a-1]==1 && b<0 )ara[-b-1]=0;
        }
        for(i=0;i<n;i++)if(ara[i]==1)count++;
        printf("%d\n",count);
    }
    return 0;
}
