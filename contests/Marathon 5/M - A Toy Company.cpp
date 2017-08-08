#include<bits/stdc++.h>
#define pii pair<int,int>
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
int ara[100][3][26];
int dist[26][26][26];
int fx[] = {1, -1};
int isvali(int a, int b, int c)
{
    return a>-1 && b>-1 && c>-1 && a<26 && b<26 && c<26;
}
int n;
bool check(string u)
{
    int a[3], x, y, z;
    x = a[0] = u[0] - 'a', y = a[1] = u[1] - 'a', z = a[2] = u[2] - 'a';
}
int bfs(string st, string en)
{
    queue<string> Q;
    int f = 0;
    FOR(k, n)
    {
        f = 0;
        FOR(l, 3)
        {
            if(ara[k][l][st[l]-'a']==0)
            {
                f = 1;
                break;
            }
        }
        if(!f) break;
    }
    if(!f)
    {

        return -1;
    }
    Q.push(st);
    dist[st[0] - 'a'][st[1] - 'a'][st[2] - 'a'] = 0;
    while(!Q.empty())
    {
        string u = Q.front();
        Q.pop();

        int a[3], x, y, z;
        x = a[0] = u[0] - 'a', y = a[1] = u[1] - 'a', z = a[2] = u[2] - 'a';
        if(u==en) return dist[x][y][z];
        FOR(i, 2)
        {
            FOR(j, 3)
            {
                a[j]+=fx[i] + 26;
                a[j]%=26;
                if(dist[a[0]][a[1]][a[2]]==-1)
                {
                    string s = "aaa";
                    s[0]+=a[0];
                    s[1]+=a[1];
                    s[2]+=a[2];
                    f = 0;
                    FOR(k, n)
                    {
                        f = 0;
                        FOR(l, 3)
                        {
                            if(ara[k][l][s[l]-'a']==0)
                            {
                                f = 1;
                                break;
                            }
                        }
                        if(!f) break;
                    }
                    if(!f)
                    {
                        if(j==0) a[j] = x;
                        else if(j==1) a[j] = y;
                        else a[j] = z;
                        continue;
                    }
//                    cout << s << '*' << endl;
                    dist[a[0]][a[1]][a[2]] = dist[x][y][z] + 1;
                    Q.push(s);
                }
                if(j==0) a[j] = x;
                else if(j==1) a[j] = y;
                else a[j] = z;
            }
        }
    }
    return -1;
}
int main()
{
    int t, tst = 1;
    sf1(t);
    while(t--)
    {
        string st, en;
        cin >> st >> en;
        sf1(n);
        mem(ara, 0);
        FOR(i, n)
        {
            string a[3];
            cin >> a[0] >> a[1] >> a[2];
            FOR(k, 3)
            {
                FOR(j, a[k].length())
                ara[i][k][a[k][j] - 'a'] = 1;
            }

        }
        mem(dist, -1);
        pcase(tst++);
        pf("%d\n", bfs(st, en));
    }
    return 0;
}





/*


aaa
akk
3
a nmmkjl kljnbk
b a cd
akjl bjlk lkjc

*/







