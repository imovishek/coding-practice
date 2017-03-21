#include<cstdio>
#include<algorithm>
using namespace std;


int main()
{
    int t,n,i,res;
    scanf("%d",&t);
    while(t--)
    {
        res=0;
        scanf("%d",&n);
        int ara[n];
        for(i=0;i<n;i++)
            scanf("%d",&ara[i]);
        sort(ara,ara+n);
        if(n%3==0)
        {
            for(i=0;i<n;i+=3)
            {
                res+=ara[i];
            }
        }
        else if(n%3==1)
        {
            for(i=1;i<n;i+=3)
            {
                res+=ara[i];
            }
        }
        else if(n%3==2)
        {
            for(i=2;i<n;i+=3)
            {
                res+=ara[i];
            }
        }
        printf("%d\n",res);

    }
    return 0;
}
