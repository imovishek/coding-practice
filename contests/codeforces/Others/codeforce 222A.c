#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<inttypes.h>

int main()
{
    int n,h,a,i,ans;
    scanf("%d %d",&n,&h);
    ans=n;
    for(i=0;i<n;i++)
    {
        scanf("%d",&a);
        if(a>h)ans++;
    }
    printf("%d\n",ans);
    return 0;
}
