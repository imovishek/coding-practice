/*input
3
4
ACGT
ACGTGCGT
ACCGTGC
ACGCCGT
3
CGCGCGCGCGCGCCCCGCCCGCGC
CGCGCGCGCGCGCCCCGCCCGCAC
CGCGCGCGCGCGCCCCGCCCGCTC
2
CGCGCCGCGCGCGCGCGCGC
GGCGCCGCGCGCGCGCGCTC
 
*/
#include <bits/stdc++.h>
using namespace std;
#define MaxN 2500005
int sz = 0;
int nexti[MaxN][4];
 
int endi[MaxN];
int len[MaxN];
int fun(char ch)
{
    if(ch=='G') return 1;
    if(ch=='T') return 3;
    return ch - 'A';
}
void insert (string &s)
{
    int v = 0;
    int length = 0;
    for(int i = 0; i<s.size(); i++)
    {
        int c = fun(s[i]);
        if(nexti[v][c] == -1){
            nexti[v][c] = ++sz;
        }
        v = nexti[v][c];
        len[v] = ++length;
        endi[v]++;
    }
}
long long ans = 0;
bool search ( string P )
{
    int v = 0;
    for(int i = 0; i<P.size(); i++)
    {
        int c = fun(P[i]);
        if(nexti[v][c]==-1)
            return 0;
        v = nexti[v][c];
    }
    return endi[v] > 0;
}
 
void traverse()
{
    ans = 0;
    for(int i = 1; i<=sz; i++)
        ans = max(ans, 1ll * endi[i]*len[i]);
}
 
void clear()
{
    memset(nexti, -1, sizeof nexti);
    memset(endi, 0, sizeof endi);
}
 
int main()
{
    int t, tst = 1;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        string st;
        sz = 0;
        clear();
        for(int i = 0; i<n; i++)
        {
            cin >> st;
            insert(st);
        }
        traverse();
        printf("Case %d: %lld\n", tst++, ans);
    }
    return 0;
}