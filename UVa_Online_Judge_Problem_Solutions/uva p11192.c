#include<stdio.h>
#include<string.h>

int main()
{
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
char ch,ara[100];
int n,i,k,j,m,l,len;
while(1){
scanf("%d",&n);
if (n==0) break;
scanf("%s",ara);
len=strlen(ara);


for(k=1;k<=n;k++)
{
    j=k*(len/n);
    i=j-(len/n);
    m=i;
    for(l=0;i<(m+j)/2;i++,l++)
    {
        ch=ara[i];
        ara[i]=ara[j-1-l];
        ara[j-1-l]=ch;
    }
}
printf("%s\n",ara);
}
return 0;
}
