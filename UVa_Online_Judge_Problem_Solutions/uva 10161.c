#include<stdio.h>
#include<math.h>
int main()
{

    int t,i,sq,n,mid;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d",&n);
        if(n==0)break;
        sq=sqrt(n);
        if(sq*sq!=n)sq++;
        mid=sq*(sq-1)+1;

        if(sq%2){
        if(n>mid ){
        mid=sq-n+mid;
        printf("Case %d: %d %d\n",i,mid,sq);
        }
        else{
                mid=sq+n-mid;
        printf("Case %d: %d %d\n",i,sq,mid);
        }
        }
        else{
            if(n>mid ){
        mid=sq-n+mid;
        printf("Case %d: %d %d\n",i,sq,mid);
        }
        else{
                mid=sq+n-mid;
        printf("Case %d: %d %d\n",i,mid,sq);
        }
        }


    }

    return 0;
}
