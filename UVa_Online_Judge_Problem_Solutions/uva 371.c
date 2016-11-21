#include<stdio.h>
#include<inttypes.h>
int i=0;
int mem[10000];
int acfunc(int64_t n)
{
    if(n<10000 && mem[n]!=0)return mem[n];
    else if(n==1){return 1;}
    else if (n%2==0) { i=acfunc(n/2)+1;if(n<10000) mem[n]=i;}
    else { i=2+acfunc(n+n/2+1);if(n<10000)mem[n]=i;}
return i;
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
int x,n,max;
int64_t l,h;
for(i=0;i<10000;i++)mem[i]=0;
while(1){
scanf("%"PRId64" %"PRId64"",&l,&h);
if(l==0 && h==0)break;
if(l>h){x=l;l=h;h=x;}
printf("Between %"PRId64" and %"PRId64", ",l,h);

max=0;

for(;l<=h;l++)
{
    i=0;
    if(l==1)i=3;
    else {i=acfunc(l)-1;}
if(i>max){max=i;n=l;}

}
printf("%d generates the longest sequence of %d values.\n",n,max);
}
return 0;
}
