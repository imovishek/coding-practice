#include<stdio.h>
#include<math.h>

typedef unsigned int uint;

uint dec_bin(uint dec);

int main()
{
 uint dec,bin;
 while(1)
 {
 printf("Enter a decimal number(0 to exit):");
 scanf("%d",&dec);
 if(dec<=0){break;}
 bin=dec_bin(dec);
 printf("Binary: %d\n",bin);
 }
 return 0;
}


uint dec_bin(uint dec)
{
    uint i,bin=0;
    for(i=0;dec>0;i++)
    {
     bin+=(dec%2)*pow(10,i);
     dec=dec/2;
    }
    return bin;
}
