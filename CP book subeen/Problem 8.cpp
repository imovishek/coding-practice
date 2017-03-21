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
        int sum=0;
        for(i=0;i<5;i++){
            scanf("%d",&a);
            sum+=a;
        }
        pf("%d\n",sum/5);
    }

    return 0;
}

