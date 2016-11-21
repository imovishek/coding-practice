#include<stdio.h>
const int dig=2570;

void factorial(char ara[],int n);
int main()
{

    int i,n;
    char ara[dig];
    while(scanf("%d",&n)==1){
            if(n==0 || n==1)printf("%d!\n1\n",n);
    else{
    for(i=0;i<dig-1;i++)ara[i]='*';
    ara[2569]='1';

    factorial(ara,n);
    printf("%d!\n",n);
    for(i=0;i<dig;i++)if(ara[i]!='*')printf("%c",ara[i]);
    printf("\n");
    }
    }

return 0;
}
void factorial(char ara[],int n)
{

    if(n!=2){
     factorial(ara,n-1);
    }
    int i,div=0,mult;
    for(i=dig-1;ara[i]!='*';i--)
    {
        mult=(ara[i]-'0')*n+div;
        ara[i]=mult%10+'0';
        div=mult/10;
    }
    while(div>0){ara[i]=div%10+'0';i--;div/=10;}



}
