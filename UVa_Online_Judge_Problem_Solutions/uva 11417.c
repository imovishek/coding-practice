#include<stdio.h>
int ara[502][502];
int GCD(int i, int j)
{
int x;
if(i>j){x=i;i=j;j=x;}

if(j%i==0)return i;
x=1;
while(x>0)
{
    x=j%i;
    j=i;i=x;
}
return j;
}
int main()
{
    int n,i,j,sum;
    while (scanf("%d",&n)==1)
    {
        if(n==0)break;
        for(i=1;i<501;i++)
        for(j=i+1;j<=501;j++)ara[i][j]=0;
        sum=0;
        for(i=1;i<n;i++){
        for(j=i+1;j<=n;j++)
        {
            if(i<501 && j<501 && ara[i][j]!=0)sum+=ara[i][j];
        else {ara[i][j]=GCD(i,j);sum+=ara[i][j];}

        }
        }
        printf("%d\n",sum);
    }


    return 0;
}



