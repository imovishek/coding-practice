#include<stdio.h>
void main()
{
    int line,i,x,pn=0,nn=0;
    scanf("%d",&line);
    for(i=0;i<line;i++)
    {
        scanf("%d",&x);
        if(x>=0)pn++;
        else nn++;
    }
    printf("%d %d",pn,nn);
}
