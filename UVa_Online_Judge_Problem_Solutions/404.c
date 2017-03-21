#include<stdio.h>
int is_prime(int n)
{
    int i;
    if(n%2==0)return 0;
    for(i=3;i<n;i+=2)
        if(n%i==0)return 0;
    return 1;
}
int main()
{
    freopen("output.txt","w",stdout);
    int i,c=24;
    for(i=97;i<150;i++)if(is_prime(i)){printf("%d,",i);c++;}
    printf(" %d",c);
    return 0;
}
