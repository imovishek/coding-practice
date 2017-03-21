#include<stdio.h>
int main()
{
    int i,j,k,n=5,m=1;
    char hs='#',sp=' ';
    for(i=n; i>0; i--)
    {
        printf("hi\n");
        for(j=i-1; j>0; j--)
        {
            printf("%c",sp);
            printf("hi****\n");
        }
        printf("%c",hs);
        if(i==n )
        {
            printf("\n");
            continue;
        }
        for(k=1; k<=m; m+=2,k++)
        {
            printf("%c",sp);
            printf("%d %d hi****\n", k, m);
        }
        printf("%c\n",hs);
        if(i==1)
            for(j=1; j<=n; j++)
            {
                printf("%c ",hs);
                printf("hi\n");
            }
        printf("hi\n");
    }
    return 0;
}
