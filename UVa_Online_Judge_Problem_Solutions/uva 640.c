#include<stdio.h>


int main()
{
    
    int i,temp,sum;
    char ara[1000000];
     for(i=0;i<1000000;i++)ara[i]='0';
    for(i=1;i<1000000;i++){
            sum=temp=i;
    while(temp>0)
    {
        sum+=temp%10;
        temp/=10;
    }
    if(sum<=1000000)
        ara[sum-1]='1';
        else break;
    }
    ara[999999]='\0';
    for(i=0;i<1000000;i++)if(ara[i]=='0')printf("%d\n",i+1);

    
return 0;

}
