#include<stdio.h>
#include<inttypes.h>
int mem[1000];
int acfunc(int64_t n)
{
    int i;
    if(n<1000 && mem[n]!=0)return mem[n];
    else if(n==1)return 1;
    else if (n%2==0) i=1+acfunc(n/2);
    else i=2+acfunc((3*n+1)/2);
    return i;
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
int64_t x,n,l,h;
int i,max;

for(i=0;i<1000;i++)mem[i]=0;
while(1){
scanf("%"PRId64" %"PRId64"",&l,&h);
if(l==0 && h==0)break;
if(l>h){x=l;l=h;h=x;}

printf("Between %"PRId64" and %"PRId64", ",l,h);

max=0;

for(;l<=h;l++)
{
    i=0;
    if(l==1)i=4;
    else {i=acfunc(l);
    if(l<1000 && mem[l]==0)mem[l]=i;}
if(i>max){max=i;n=l;}

}
printf("%"PRId64" generates the longest sequence of %"PRId64" values.\n",n,--max);
}

return 0;
}
