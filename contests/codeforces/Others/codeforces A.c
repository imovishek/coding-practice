#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<inttypes.h>
int maax(int a,int b)
{
    if(a>b)
        return a;
    else return b;
}
int main()
{
    int n,i;
    scanf("%d",&n);
    int ara[n],ma[4];
    for(i=0;i<n;i++)
        scanf("%d",&ara[i]);
    int mini=2147483647,maxi=0,mn,mx;
    for(i=0;i<n;i++)
    {
        if(mini>ara[i]){mini=ara[i];mn=i;}
        if(maxi<ara[i]){maxi=ara[i];mx=i;}
    }
    mini=2147483647;
    ma[0]=mn+1;
    ma[1]=n-mn;
    ma[2]=mx+1;
    ma[3]=n-mx;
    for(i=0;i<4;i++)
    {
        if(mini>ma[i] && ma[i]>0 ){mini=ma[i];mx=i;}
    }

    printf("%d\n",n-mini);
//    if(mx==0)
//        printf("%d\n",maax(ma[3]-ma[0],ma[2]-ma[0]));
//    else if(mx==1)
//        printf("%d\n",maax(ma[3]-ma[1],ma[2]-ma[1]));
//    else if(mx==2)
//        printf("%d\n",maax(ma[0]-ma[2],ma[1]-ma[2]));
//    else if(mx==3)
//        printf("%d\n",maax(ma[0]-ma[3],ma[1]-ma[3]));


    return 0;
}
