/*
OVISHEK PAUL, CSE - 15, SUST

*/

#include<bits/stdc++.h>
#define pii             pair<int,int>
#define mkp             make_pair
#define fs              first
#define sc              second
#define pb              push_back
#define ppb             pop_back()
#define all(vt)         vt.begin(), vt.end()
#define pf              printf
#define pf1(a)          printf("%d\n",a)
#define hi              printf("hi!\n");
#define sf              scanf
#define sf1(a)          scanf("%d",&a)
#define sf2(a,b)        scanf("%d %d",&a,&b)
#define sf3(a,b,c)      scanf("%d %d %d",&a,&b,&c)
#define sf1ll(a)        scanf("%lld",&a)
#define sf2ll(a,b)      scanf("%lld %lld",&a,&b)
#define sf3ll(a,b,c)    scanf("%lld %lld %lld",&a,&b,&c)
#define pcase(x)        printf("Case %d: ",x)
#define MOD             1000000007
#define inf             1000000007
#define pi              acos(-1.0)
#define mem(arr,x)      memset((arr), (x), sizeof((arr)));
#define FOR(i,x)        for(int i=0;i<(x); i++)
#define FOR1(i,x)       for(int i=1;i<=(x); i++)
#define repr(vt, it)    for(typeof(vt.begin()) it = vt.begin(); it!=vt.end(); it++)
#define mx              100007

using namespace std;
typedef long long int lint;
typedef double dbl;
typedef vector<int> vi;

struct data{
    int counti;
    int number;
    data *next[2];
    data(){
        next[0] = next[1] = NULL;
        counti = number = 0;
    }
} *root;

void insert(char ara[], int n)
{
    data *cur = root;
    int val = 0;
    FOR(i, n){
        int id = ara[i] - '0';
        if(cur->next[id]==NULL) {
                cur->next[id] = new data();
                cur->next[id]->number = cur->number+1;
        }
        cur->next[id]->counti++;
        cur = cur->next[id];
    }
}
void del(data *cur)
{
    FOR(i, 2) if(cur->next[i]!=NULL) del(cur->next[i]);
    delete(cur);
}
int maxi = 0;
void traverse(data *cur)
{
//    cout << cur->number << ' '  << cur->counti <<endl;
    maxi = max(maxi, cur->number * cur->counti);
    FOR(i, 2) if(cur->next[i]!=NULL) traverse(cur->next[i]);
}

int main()
{
#ifdef OVI
        // freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
#endif // OVI

    int t, tst = 1;
    sf1(t);
    while(t--){
        root = new data();
        int n;
        sf1(n);
        char ara[100];
        FOR(i, n){
            sf("%s", ara);
            insert(ara, strlen(ara));
        }
        maxi = 0;
        traverse(root);
        del(root);
        pf1(maxi);
    }
    return 0;
}















