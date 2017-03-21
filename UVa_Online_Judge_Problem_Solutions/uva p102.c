#include<stdio.h>
int main()
{
    int i,ara[9],j,sum[6],sum2=0,k;
    while(1==scanf("%d",&ara[0]))
    {
       for(i=1;i<9;i++)
        {
            scanf("%d",&ara[i]);
        }
        for(i=0;i<6;i++){
        sum[i]=0;
        }
        /*BCG*/
       sum[0]=ara[3]+ara[6]+ara[2]+ara[8]+ara[1]+ara[4];
       /*BGC*/
       sum[1]=ara[3]+ara[6]+ara[1]+ara[7]+ara[2]+ara[5];

        /*GBC*/
       sum[4]=ara[4]+ara[7]+ara[0]+ara[6]+ara[2]+ara[5];
       /*GCB*/
       sum[5]=ara[4]+ara[7]+ara[2]+ara[8]+ara[0]+ara[3];
       //CGB
       sum[3]=ara[5]+ara[8]+ara[1]+ara[7]+ara[0]+ara[3];

       //CBG
       sum[2]=ara[5]+ara[8]+ara[0]+ara[6]+ara[1]+ara[4];

       sum2=sum[0];
for(k=0,j=1;j<6;j++)
{
    if(sum2>sum[j]) {sum2=sum[j]; k=j;}
}
switch(k)
{
case 0:
printf("BCG %d\n",sum2);
break;
case 1:
printf("BGC %d\n",sum2);
break;
case 2:
printf("CBG %d\n",sum2);
break;
case 3:
printf("CGB %d\n",sum2);
break;
case 4:
printf("GBC %d\n",sum2);
break;
case 5:
printf("GCB %d\n",sum2);
break;
default:
    break;
    }

}

 return 0;
}
