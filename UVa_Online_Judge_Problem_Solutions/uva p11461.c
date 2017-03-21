#include<stdio.h>
#include<math.h>
int main()
{
    int a,b,x,count=0;
    double c;
    while(1)
    {
        count=0;
        scanf("%d %d",&a,&b);
        if(a==0 && b==0) break;
        for(;a<=b;a++)
        {
            c=sqrt(a);
            x=c;
            if(x==c){count++;}
        }
        printf("%d\n",count);
    }
    return 0;

}
