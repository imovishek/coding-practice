#include<stdio.h>
int main()
{
    int t,n,cb,cx,tmp;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        tmp=n;
        cb=0;
        cx=0;
        while(tmp)
        {
            if(tmp%2)cb++;
            tmp/=2;
        }
        while(n)
        {
            tmp=n%10;
            while(tmp)
            {
                if(tmp%2)cx++;
                tmp/=2;
            }
            n/=10;

        }
        printf("%d %d\n",cb,cx);

    }
    return 0;
}
