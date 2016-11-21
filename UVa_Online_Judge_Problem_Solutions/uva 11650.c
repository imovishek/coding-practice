#include<stdio.h>
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
int h,m,t;
char ara[6];
scanf("%d",&t);
while(t--)
{
    scanf("%s",ara);

        h=(ara[0]-'0')*10+ara[1]-'0';
        m=(ara[3]-'0')*10+ara[4]-'0';
        if(m!=0) {h=12-h-1;if(h<=0)h+=12;
        m=60-m;}
        else {if(h==12)h=12;else h=12-h;}
        if(h<10)printf("0%d",h);
        else printf("%d",h);
        printf(":");
        if(m<10)printf("0%d",m);
        else printf("%d",m);
        printf("\n");

}
return 0;
}
