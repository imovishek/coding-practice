#include<stdio.h>
#define sf scanf
#define pf printf


int main()
{
    int t,i,n;
    int a;
    scanf("%d",&t);
    while(t--)
    {
        sf("%d",&n);
        int sum=0;
        for(i=0;i<n;i++){
            scanf("%d",&a);
            sum+=a;
        }
        pf("%.2lf\n",1.0*sum/n);
    }

    return 0;
}


