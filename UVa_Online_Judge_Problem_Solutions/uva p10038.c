#include<stdio.h>
#include<stdlib.h>
int main()
{
    int i,a,b,ntest,is_jolly=1,abst;

    while(1==scanf("%d",&ntest)){
            char ara[ntest];
    for(i=0;i<ntest;i++)
        ara[i]='0';

    scanf("%d",&b);

  for(i=1;i<ntest;i++)
    {

        scanf("%d",&a);
        abst=abs(a-b);
        if(abst>=1 && abst <ntest && ara[abst-1]=='0') ara[abst-1]='1';
        else {is_jolly=0; scanf("%*[^\n]s"); break; }


         b=a;


    }
    if(1==is_jolly) printf("Jolly\n");
    else printf("Not jolly\n");
    is_jolly=1;

    }

return 0;
}
