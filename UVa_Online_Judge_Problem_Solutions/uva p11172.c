#include<stdio.h>

int main()
{
    int ntest,i,a,b;
    scanf("%d",&ntest);

        for(i=0;i<ntest;i++)
        {
           scanf("%d %d",&a,&b);
           if(a>b) printf(">\n");
           else if(a<b)printf("<\n");
           else printf("=\n");
        }


}
