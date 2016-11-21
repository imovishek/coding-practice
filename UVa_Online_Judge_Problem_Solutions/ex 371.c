#include<stdio.h>
#include<inttypes.h>
int func(int64_t n)
{
int x=1;
while(n!=1){x++;
    if(n%2==1){n=n+n/2+1;x++;}
    else n=n/2;
}
return x;
}


int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int64_t i,a,b,j,x,num=0;
    while(scanf("%"PRId64" %"PRId64"",&a,&b)==2){
    if(a==0 && b==0)break;
    if(a>b){x=a;a=b;b=x;}



        for(i=a;i<=b;i++){
            if (i==1 && num<4) {num=4;j=1;}
            else if(num<func(i)) {num=func(i);j=i;}
             }

printf("Between %"PRId64" and %"PRId64", ",a,b);
printf("%"PRId64" generates the longest sequence of %"PRId64" values.\n",j,--num);

num=0;
}
return 0;

}
