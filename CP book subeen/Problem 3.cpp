#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<sstream>
#include<iostream>
#include<algorithm>
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
int main()
{
    int t,a;
    string st;
    sf1(t);
    getchar();
    while(t--)
    {
        getline(cin, st);
        istringstream ss(st);
        int counti=0;
        while(ss>>a)counti++;
        pf("%d\n",counti);
    }
    return 0;
}
