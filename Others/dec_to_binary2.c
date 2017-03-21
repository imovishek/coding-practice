#include<stdio.h>
#include<math.h>
typedef unsigned int uint;



void main()
{
 uint dec,bin,ara[35];
 double x;
 int i;
 while(1){

 printf("Enter a decimal number(0 to exit):");
 dec=getche();
bin=0;
 if(dec<1){break;}
 for(i=0;dec>0;i++)
     {
     ara[i]=dec%2;
     dec=floor(dec/2);
     uint x;
     x=pow(10,i);
     printf("\n%d",x);
if(i>0 && i%2==0)x+=1;
     bin+=ara[i]*x;

     }
     i--;
      printf("\n");
for(;i>=0;i--)
     {
printf("%d",ara[i]);
     }
     printf("\nAnother: %d\n",bin);


 }

}



