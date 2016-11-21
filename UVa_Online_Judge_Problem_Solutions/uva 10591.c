#include<stdio.h>

int orn;
char ara[729];

int is_happy(int temp)
{
    int sum=0;

    while(temp>0)
    {
        sum+=(temp%10)*(temp%10);
        temp/=10;
    }
    if(sum==1)return 1;
    else if(sum==orn || '1'==ara[sum-1])return 0;
    else return is_happy(sum);

}
int main()
{

    int i,t;

    for(i=4;i<=729;i++){orn=i;if(is_happy(i))ara[i-1]='0';else ara[i-1]='1';}
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d",&orn);
        if(is_happy(orn))printf("Case #%d: %d is a Happy number.\n",i,orn);
        else printf("Case #%d: %d is an Unhappy number.\n",i,orn);
    }

    return 0;
}
