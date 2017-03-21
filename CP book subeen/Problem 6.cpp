#include<stdio.h>
#define sf scanf
#define pf printf
int main()
{
    int t,i;
    int a;
    scanf("%d",&t);
    while(t--)
    {
        int maxi=0, mini=105;
        for(i=0;i<5;i++){
            scanf("%d",&a);
            if(a>maxi)maxi=a;
            if(a<mini)mini=a;
        }
        pf("%d %d\n",maxi,mini);
    }

    return 0;
}
