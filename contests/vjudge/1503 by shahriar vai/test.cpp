#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<ctime>
#include<vector>
#include<stack>
#include<queue>
using namespace std;
char ara[27]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int flag[26]={0};
vector<char>vt;
int bigflag,counti;
int n , k;
void permutation()
{
    if(vt.size()==n)
    {

        for(int i=0;i<n;i++)
            printf("%c",vt[i]);
        printf("\n");
        counti++;
        if(counti==k)bigflag=1;
    }
    for(int i=0;i<n;i++)
    {
        if(flag[i]==0)
        {
            vt.push_back(ara[i]);
            flag[i]=1;
            permutation();
            flag[i]=0;
            vt.pop_back();
            if(bigflag)break;
        }
    }
}
int main()
{
    int t;
    double l;
    scanf("%d",&t);
    for(int test=1;t--;test++)
    {
        bigflag=0;
        counti=0;
        scanf("%d %d",&n,&k);
        printf("Case %d:\n",test);

//        l=clock();
        permutation();
//        l=clock()-l;
//        printf("time elapsed: %.10lf\n",l/CLOCKS_PER_SEC);
    }
    return 0;
}
