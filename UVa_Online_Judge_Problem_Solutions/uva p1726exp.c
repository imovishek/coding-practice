#include<stdio.h>
#include<string.h>
void main()
{
int i,j,ntest,k,l,d,s,nque,count=0;
char r,ziara[50000],ocara[50000];
scanf("%d",&ntest);
for(i=0;i<ntest;i++)
{
    scanf("%d",&nque);
    for(j=0,k=0,l=0;j<nque;j++)
    {
       scanf("%d %d %c",&d,&s,&r);
       if(s==0 && r=='i') {ziara[k]=d; k++;}
       else if(s==1 && r=='c') {ocara[l]=d; l++;}
    }
    d=strlen(ziara);
    s=strlen(ocara);
    for(j=0;j<d;j++)
    {
        for(k=0;k<s;k++)
        {
            if(ziara[j]<ocara[k])count++;
        }
    }
    printf("%d\n",count);
    count=0;
}

}

