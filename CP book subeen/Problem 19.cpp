#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<sstream>
#include<map>
#define pii pair<int,int>
#define fs first
#define sc second
#define pb push_back
#define ppb pop_back()
#define pf printf
#define hi printf("hi!\n");
#define sf scanf
#define sf1(a) scanf("%d",&a)
#define sf2(a,b) scanf("%d %d",&a,&b)
#define sf3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define pcase(x) printf("Case %d: ",x)
#define pi acos(-1.0)
using namespace std;
typedef long long int lint;
typedef double dbl;
int fact(int n)
{
    if(n==1 || n==0)return 1;
    return n*fact(n-1);
}
int main()
{
    int t;
    string line, st, ara[11];
    int val[11];
    sf1(t);
    getchar();
    while(t--)
    {
        for(int i=0;i<11;i++)val[i]=1;
        getline(cin, line);
        istringstream ss(line);
        int counti=0,pos=0;
        while(ss >> st)
        {
            int i,flag=1;
            for(i=0;i<pos;i++)
                if(ara[i]==st){
                    flag=0;
                    val[i]++;
                }
            if(flag) {ara[pos++]=st;}
            counti++;
        }
        int ans=fact(counti);
        for(int i=0;i<pos;i++)
            ans/=fact(val[i]);
        pf("1/%d\n",ans);

    }
    return 0;
}
