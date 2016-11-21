#include<stdio.h>
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int i,ara[4],n;
    scanf("%d",&n);
    while(n--)
    {
        for(i=0;i<4;i++)scanf("%d",&ara[i]);
        for(i=0;i<4;i++)
            if(ara[i]>=ara[(i+1)%4]+ara[(i+2)%4]+ara[(i+3)%4])break;
        if(i==4){
            if(ara[0]==ara[1] && ara[1]==ara[2] && ara[2]==ara[3]&& ara[3]==ara[0])printf("square\n");
            else if ((ara[0]==ara[1]&& ara[2]==ara[3]) ||(ara[0]==ara[2]&& ara[1]==ara[3]))printf("rectangle\n");
            else printf("quadrangle\n");
        }
        else printf("banana\n");
    }
    return 0;
}
