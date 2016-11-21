#include<stdio.h>
int main()
{
int ara[5],n,i,j,temp,rem;
while(scanf("%d",&n)==1)

{
    if(n==0)break;
    ara[0]=0;ara[1]=0;ara[2]=0;ara[3]=0;ara[4]=0;
    for(i=1;i<=n;i++)
    {
        temp=i;
        j=1;
        if(temp!=100){
        while(temp>0)
        {
            rem=temp%10;
            temp/=10;
            if(j==1 && rem>=1 && rem<=3)ara[0]+=rem;
            else if(j==1 &&rem==4){ara[0]++;ara[1]++;}
            else if(j==1 &&rem==5){ara[1]++;}
            else if(j==1 && rem>=6 && rem<=8){ara[0]+=rem-5;ara[1]++;}
            else if(j==1 &&rem==9){ara[0]++;ara[2]++;}
            if(j==2 && rem>=1 && rem<=3)ara[2]+=rem;
            else if(j==2 &&rem==4){ara[3]++;ara[2]++;}
            else if(j==2 &&rem==5){ara[3]++;}
            else if(j==2 && rem>=6 && rem<=8){ara[2]+=rem-5;ara[3]++;}
            else if(j==2 &&rem==9){ara[2]++;ara[4]++;}
            j++;


        }
        //printf("%d: %d i, %d v, %d x, %d l, %d c\n",i,ara[0],ara[1],ara[2],ara[3],ara[4]);

        }
        else ara[4]++;
    }
    printf("%d: %d i, %d v, %d x, %d l, %d c\n",n,ara[0],ara[1],ara[2],ara[3],ara[4]);
}
return 0;
}
