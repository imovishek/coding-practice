#include<stdio.h>
void main()
{
    int i,j,k,n=1;
   int ara[13]={2,5,6,7,12,15,17,45,65,74,81,90,91};

        while(scanf("%d",&n)==1){
        for(i=0,j=13;;)
        {
            if(i==j){printf("%d Not found\n",n);break;}
            k=(i+j)/2;
            if(ara[k]<n)i=k;
            else if (ara[k]>n)j=k;
            else if (ara[k]==n) {printf("Found %d: %d\n",k,n);break;}
            else {printf("Not found %d: %d\n",k,n);break;}
        }
}








}
