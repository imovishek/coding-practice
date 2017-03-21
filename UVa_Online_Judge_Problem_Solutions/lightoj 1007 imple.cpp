#include<cstdio>
#define M 5000002
using namespace std;

int phi[M];

void cal_phi();

int main()
{
    int t,a,b;
    cal_phi();
    unsigned long long int  sum;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        sum=0;
        scanf("%d %d",&a,&b);
        for(int j=a;j<=b;j++)
        {
            sum+=phi[j]*phi[j];
        }
        printf("Case %d: %llu\n",i,sum);
    }
    return 0;
}

void cal_phi()
{
    for(int i=2;i<M;i++)phi[i]=i;
    for(int i=2;i<M;i++)
    {
        if(phi[i]==i) //prime num
        {
            for(int j=i;j<M;j+=i)
            {
                phi[j]-=phi[j]/i;
            }
        }
    }
}
