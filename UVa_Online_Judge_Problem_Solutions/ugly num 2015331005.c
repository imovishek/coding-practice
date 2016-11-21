#include<stdio.h>
int main()
{
   int i,j,k,n,x,mid,count=5;
   int ara[1499];
   ara[0]=2;ara[1]=3;ara[2]=4;ara[3]=5;
   for(i=6;;i++)
   {
       if(i%2==0 ){n=i/2;x=count/5;}
        else if(i%3==0){n=i/3;x=count/5;}
        else if (i%5==0){n=i/5;x=count/5;}
        else continue;
        for(k=x,j=count-2;k<=j;)
        {
            mid=(k+j)/2;
            if(ara[mid]<n)k=mid+1;
            else if (ara[mid]>n)j=mid-1;
            else if(ara[mid]==n) {
                    ara[count-1]=i;count++;
            printf("%d: %d\n",count,i); break;
            }
        }

        if(count==100)break;


   }

}
