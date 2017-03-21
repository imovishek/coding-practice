#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

int main()
{
    int ara[5],sum=0,mini=10000;
    for(int i=0;i<5;i++){
        scanf("%d",&ara[i]);
        sum+=ara[i];
    }
    sort(ara,ara+5);
    for(int i=4;i>=0;)
    {
        int counti=0,temp=ara[4],j=i,tsum=sum;
        temp=ara[i];

        while(temp==ara[j] && counti<3 && i>=0)
        {
            counti++;
            tsum-=ara[j];
            temp=ara[j];
            j--;
            i--;

        }
        if(mini>tsum && counti>1)mini=tsum;
    }
    if(mini==10000)mini=sum;
    printf("%d\n",mini);
    return 0;
}
