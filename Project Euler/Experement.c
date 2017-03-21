#include<stdio.h>
int is_palindrom(int n)
{
    int a,x,ara[6];
    n=a;

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
    if(n/100000<10){
   if(ara[1]==ara[5] && ara[2]==ara[4]) return 1;
   else return 0;
    }
    else
    {
      if(ara[0]==ara[5] && ara[1]==ara[4]&&ara[2]==ara[3]) return 1;
    else return 0;
    }


}

