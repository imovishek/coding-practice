#include<stdio.h>
#include<inttypes.h>
#include<math.h>
int main()
{

    int64_t n,c,a,b;
    int i,j,int_sq,digit;

    printf("         6         8\n        35        49\n");
    a=8;
    b=49;
    for(i=2;i<10;i++)
    {
        j=0;
        n=b*6-a+2;
        c=n*(n+1)/2;
        int_sq=(int)sqrt(c);
        digit=int_sq;
        while(digit>0){j++;digit/=10;}
        j=10-j;
        while(j--)printf(" ");
        printf("%d",int_sq);
        digit=n;j=0;
        while(digit>0){j++;digit/=10;}
        j=10-j;
        while(j--)printf(" ");
        printf("%"PRId64"\n",n);
        a=b;
        b=n;

    }

    return 0;
}


