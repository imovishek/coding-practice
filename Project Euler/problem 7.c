#include<stdio.h>
#include<math.h>
int is_prime(int n)
{
    int i;
    if(n==2||n==3)return 1;
    if(n%2==0)return 0;
    for(i=3;i<=sqrt(n);i+=2)
    {
      if(n%i==0) return 0;
    }
    return 1;
}

int main()
{
    int i,x=1,n=10001;
    for(i=3;x<=n;i+=2)
    {
        if(is_prime(i)){
                x++;
        if(x==n) printf("%d",i);
        }

    }

}
