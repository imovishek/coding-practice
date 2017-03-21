#include<stdio.h>
#include<string.h>
#include<math.h>

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int n,m,rem,flag;
    while(scanf("%d %d",&n,&m)==2)
    {

        flag=0;
        printf("[%d",n/m);
        rem=n%m;
if(rem==0)flag=1;

else{

        printf(";%d",m/rem);
        n=rem;
        rem=m%rem;
        m=n;
if(rem==0)flag=1;
}

        while(flag==0)
        {


            printf(",%d",m/rem);
            n=rem;
            rem=m%rem;
            m=n;
            if(rem==0)flag=1;

        }
        printf("]\n");
    }
    return 0;
}
