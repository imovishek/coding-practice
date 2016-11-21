#include<stdio.h>
int main()
{

    int q,p,x,y,mult1,mult2;
    while(scanf("%d %d %d %d",&x,&y,&p,&q)==4){
    mult1=(q-y)*p;
    mult2=(x-p)*y;
    if(mult1<mult2)printf("First One.\n");
    else printf("Second One.\n");
}
    return 0;
}
