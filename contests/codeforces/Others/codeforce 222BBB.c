#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<inttypes.h>

int main()
{
    int n,h,k,i,j,ans=0,cont=0,a=0;
    scanf("%d %d %d",&n,&h,&k);
    int ara[n];
    for(i=0; i<n; i++)
    {
        scanf("%d",&ara[i]);
    }
    for(i=0; i<n; i++)
    {
        if(cont+ara[i]<=h)cont+=ara[i];
        else
        {
            int x;
            x=ceil((double)((cont-(h-ara[i])))/k)-1;
            ans+=x;
            cont-=x*k;
            while(cont+ara[i]>h)
            {
                ans++;
                if(cont<k)
                    cont=0;
                else
                    cont-=k;



            }
            cont+=ara[i];
        }
    }
    ans+=ceil((double)cont/k);
    printf("%d\n",ans);
    return 0;
}
