#include<stdio.h>
#include<math.h>
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,dif,i,j,qin;
    double q;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)break;
        q=pow(n,.3333334);

        qin=(int)q;

        if(qin*qin*qin==n)printf("No solution\n");
        else{
        for(i=qin+1;;i++)
        {
            j=i-1;
            dif=i*i*i-j*j*j;

            if(dif>n){printf("No solution\n");break;}
            for(;i*i*i-j*j*j<n && j>0;j--);
            if(i*i*i-j*j*j==n){printf("%d %d\n",i,j);break;}
        }
        }
    }
    return 0;
}
