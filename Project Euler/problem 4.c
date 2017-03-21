#include<stdio.h>

 int is_palindrom(int n);
 void main()
 {
     int i,j,x,pnum=0,x1,y1;
     for(i=999;i>=100;i--)
     {
         for(j=999;j>=100;j--)
         {
            x=i*j;
            if(is_palindrom(x)==1){if(pnum<x){pnum=x;x1=i;y1=j;}} //12521
         }
     }

printf("%d %d %d",pnum,x1,y1);
 }



 int is_palindrom(int n)
{
    int a,x,ara[6];
    a=n;

    x=a/100000;
    ara[0]=x;
    x=a-x*100000;
    a=x;
    x=a/10000;
    ara[1]=x;

    x=a-x*10000;
    a=x;
    x=a/1000;
    ara[2]=x;

    x=a-x*1000;
    a=x;
    x=a/100;
    ara[3]=x;

    x=a-x*100;
    a=x;
    x=a/10;
    ara[4]=x;

    x=a-x*10;
    a=x;
    x=a;
    ara[5]=x;
    if(n/100000==0){
   if(ara[1]==ara[5] && ara[2]==ara[4]) return 1;
   else return 0;
    }
    else
    {
      if(ara[0]==ara[5] && ara[1]==ara[4]&&ara[2]==ara[3]) return 1;
    else return 0;
    }


}
