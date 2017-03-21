#include<stdio.h>
int main()
{
    int ntest,i,sum,a,b;
    scanf("%d",&ntest);
    for(i=0;i<ntest;i++)
    {
        sum=0;
        scanf("%d %d",&a,&b);
        for(;a<=b;)
        {
            if(a%2==0) a++;
            else {sum+=a; a+=2;}
        }
        printf("Case %d: %d\n",i+1,sum);

    }
    return 0;
}
