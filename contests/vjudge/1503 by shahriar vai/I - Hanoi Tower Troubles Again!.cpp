#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#define pf printf
#define sf scanf
#define pcase(x) printf("Case %d: ",x)
using namespace std;
typedef long long int lint;
typedef double dbl;
int n;
vector<int>emp;
vector<int>st[52];
int getnum(int num)
{
    /*
    if(pos==n+1)return num;
    int b=0;
    if(st[pos].size()!=0)
        b=st[pos][st[pos].size()-1]+num;
    int sq=sqrt(b);
    if(sq*sq==b || st[pos].size()==0){
        st[pos].push_back(num);
        return getnum(pos,num+1);
    }
    else{
        return getnum(pos+1,num);
    }
    */
    int flag=0,siz,b,sq;
    for(int i=1;i<=n;i++)
    {
//        printf("***%d\n",i);
        siz=st[i].size(),b=0;
        if(siz!=0)
            b=st[i][siz-1]+num;
        sq=sqrt(b);
        if(sq*sq==b)
        {
            st[i].push_back(num);
            flag=1;
            break;
        }
    }
    if(flag){
        return getnum(num+1);
    }
    return num-1;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        printf("%d\n",getnum(1));
        for(int i=1;i<=n;i++)
        st[i].clear();
    }
    return 0;
}
