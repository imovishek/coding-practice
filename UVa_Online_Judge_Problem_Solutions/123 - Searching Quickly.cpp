#include<bits/stdc++.h>
#define pii pair<int,int>
#define psi pair<string,int>
#define mkp make_pair
#define fs first
#define sc second
#define pb push_back
#define ppb pop_back()
#define pf printf
#define pf1(a) printf("%d\n",a)
#define hi printf("hi!\n");
#define sf scanf
#define sf1(a) scanf("%d",&a)
#define sf2(a,b) scanf("%d %d",&a,&b)
#define sf3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define sf1ll(a) scanf("%lld",&a)
#define sf2ll(a,b) scanf("%lld %lld",&a,&b)
#define sf3ll(a,b,c) scanf("%lld %lld %lld",&a,&b,&c)
#define pcase(x) printf("Case %d: ",x)
#define MX 1000000007
#define inf 1000000007
#define pi acos(-1.0)
#define mem(arr,x) memset((arr), (x), sizeof((arr)));
#define FOR(i,x) for(int i=0;i<(x); i++)

using namespace std;
typedef long long int lint;
typedef double dbl;

string toUP(string st)
{
    string up;
    for(int i = 0; i<st.length() ; i++)
        up+=toupper(st[i]);
    return up;
}

string toLO(string st)
{
    string lo;
    for(int i = 0; i<st.length() ; i++)
        lo+=tolower(st[i]);
    return lo;
}
struct comp
{

    bool operator()(psi a, psi b)
    {
        string x = a.fs;
        string y = b.fs;
        if(x.size()!=y.size()) return x.size()<y.size();
        return x>y;
    }
};

int main()
{
    int t, tst = 1;
    map<string, bool> mp;
    string st;
    while(cin>>st)
    {
        if(st=="::") break;
        mp[st] = 1;
    }
    string ara[1000];
    int i = 0;
    priority_queue<psi, vector<psi>, greater<psi> > pQ;
    getline(cin, st);
    while(getline(cin, st))
    {
        ara[i] = st;
        istringstream ss(st);
        while(ss>>st)
        {
            if(mp.find(toLO(st))==mp.end()) pQ.push(psi(toUP(st), i));
        }
        i++;
    }
    map<pii, bool> mp2;
    map<string, int> sarch[1000];
    while(!pQ.empty())
    {
        psi u = pQ.top();
        pQ.pop();
        i = u.sc;
        string w = u.fs, up = toUP(w);
        ara[i] = toLO(ara[i]);
        int pl;
        if(sarch[i].find(up)!=sarch[i].end()) pl = sarch[i][up];
        else pl = 0;
        int xi = ara[i].size();
        for(int j = pl ; j<ara[i].length() ; j++)
        {
            int flag = 0, k;
            if(!j || ara[i][j-1]==' ')
            {
                for(k = j; k<j+up.length() ; k++)
                {
                    if(toupper(ara[i][k])!=up[k-j])
                    {
                        flag = 1;
                        break;
                    }
                }
            }
            else continue;
            if(!flag && (k==ara[i].length() || ara[i][k]==' '))
            {
                xi = j;
                break;
            }
        }
//        pf("%s********\n", ara[i].c_str()+xi);

        sarch[i][up] = (int)(xi+1);
        FOR(j, up.length())
        ara[i][xi+j] = up[j];

        printf("%s\n", ara[i].c_str());
    }
    return 0;
}














