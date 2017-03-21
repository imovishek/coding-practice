#include<stdio.h>
int is_prime(int n)
{
    if(n==1)return 0;
    else if(n==2)return 1;
    else if(n%2==0)return 0;
    else{
        int i;
        for(i=3;i*i<=n;i+=2)
        {
            if(n%i==0)return 0;
        }
    }
    return 1;
}


int main()
{

int n,m,n2;
while(scanf("%d",&n)==1){
        n2=0;
if(!is_prime(n))printf("%d is not prime.\n",n);
else {  m=n;
        while(n>0){n2=n2*10+n%10;n=n/10;}
        if(m==n2)printf("%d is prime.\n",m);
        else if(is_prime(n2))printf("%d is emirp.\n",m);
        else printf("%d is prime.\n",m);
}


}
return 0;
}
