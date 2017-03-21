#include<stdio.h>

void main()
{
    int num1=2,x,num2=1,n=4000000,sum=0;
    for(;;)
    {
       if(num2>n){break;}
       if(num2%2==0) sum=sum+num2;
      printf("%4d",num2);  //1 2 3 5 8 13 21

        x=num1;

      num1=num1+num2;

      num2=x;

    }
    printf("\n%4d",sum);
}
