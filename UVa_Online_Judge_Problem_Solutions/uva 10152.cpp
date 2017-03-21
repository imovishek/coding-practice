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
#define pii pair<int,int>
#define mp make_pair
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
#define forp(a,b,c) for(int a=b;a<=b;a++)
#define form(a,b,c) for(int a=b;a>=b;a--)
using namespace std;
typedef long long int lint;
typedef double dbl;
struct data{
    string name;
    int val;
};
int main()
{

    int t,n;
    string name;
    sf("%d",&t);
    for(int tst=0;tst<t;tst++)
    {

        sf("%d",&n);
        string sara[n],ara[n];
        getchar();
        for(int i=0;i<n;i++)
        {
            getline(cin,ara[i]);
        }
        map<string, int> mp;
        for(int i=0;i<n;i++)
        {
            getline(cin,sara[i]);
            mp[sara[i]]=i;
        }

        int j=n-1;
        string sorted[n+1];
        for(int i=n-1;i>=0;i--)
        {
            if(ara[i]==sara[j])j--;
            else{
                sorted[mp[ara[i]]]=ara[i];
            }
        }
        for(int i=n-1;i>-1;i--){
            if(sorted[i]!="")
                cout << sorted[i] << endl;
        }

        pf("\n");
    }
    return 0;
}
