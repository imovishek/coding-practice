
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<map>
#define pii             pair<int,int>
#define fs              first
#define sc              second
#define pf              printf
#define sf              scanf
#define sf1(a)          scanf("%d",&a)
#define sf2(a,b)        scanf("%d %d",&a,&b)
#define FOR(i,x)        for(int i=0;i<(x); i++)
#define mx              1000007

using namespace std;
typedef long long int lint;
typedef double dbl;

int flag[mx];
int main()
{
    int t, tst = 1;
    double tau = 1.61803399;
    for(int i = 1;; i++)
    {
        int x = floor(tau * double(i));
        x+=i+1;
        if(x>1000000)
            break;
        flag[x] = 1;
    }
    flag[1] = 1;
    // keda?
    int x = 0, y = 0, l = 5;
    map<pii, bool> mp;
    mp[pii(x, y)] = 1;
    for(int i = 1;  ; i++)
    {
        if(flag[i]) x+=1, y+=2;
        else x+=2, y+=3;
        if(x > mx || y>mx) break;
        mp[pii(x, y)] = mp[pii(y, x)] = 1;
        l++, l--;
    }

    sf1(t);
    while(t--)
    {
        int a, b;
        sf2(a, b);
        l = 5;
        if(mp.find(pii(a, b))!=mp.end()) pf("Bob\n");
        else pf("Alice\n");

    }
    return 0;
}














