#include<stdio.h>
int func(int n)
{
int x=1;
while(n!=1){x++;
    if(n%2==1)n=3*n+1;
    else n=n/2;
}
return x;
}


int main()
{
    int i,a,b,num=0;
    while(scanf("%d %d",&a,&b)==2){


if (a>b){
        for(i=b;i<=a;i++)
            if(num<func(i)) num=func(i);

        }
else if(a<b) {
        for(i=a;i<=b;i++){
            if(num<func(i)) num=func(i);
             }

             }
else num=func(a);
printf("%d %d %d\n",a,b,num);
num=0;
}
return 0;

}
