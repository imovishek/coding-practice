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
#define mx              100007

using namespace std;
typedef long long int lint;
typedef double dbl;

struct Node{
    int val;
    Node *left = NULL, *right = NULL;
};

Node *root[55];
void insert(int val, int i)
{
    Node *x = new Node();
    x->val = val;
    if(root[i]==NULL) {root[i] = x;}
    else{
        Node *cur = root[i], *prev;
        int f = 0;
        while(1){
//            pf("root na\n");
            prev = cur;
            if(cur->val > val) cur = cur->left, f = 0;
            else cur = cur->right, f = 1;
            if(cur==NULL){
                if(f) prev->right = x;
                else prev->left = x;
//                pf("%d boshailam\n", x->val);
                break;
            }
        }
    }
}
vector<int> vt;
void dfs(Node *u)
{
    int ans = 1;
    if(u==NULL) {vt.pb(0); return;}
//    pf("%d\n", *u);
    if(u->left!=NULL) ans++;
    if(u->right!=NULL) ans++;
    vt.pb(ans);
    dfs(u->left);
    dfs(u->right);
}

int main()
{
#ifdef OVI
        // freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
#endif // OVI

    int t, tst = 1;
    FOR(i, 55) root[i] = NULL;

    int n, k;
    sf2(n, k);
    set< vector<int> > st;
    FOR(i, n)
    {
        FOR(j, k)
        {
            int a;
            sf1(a);
            insert(a, i);
        }
        vt.clear();
        dfs(root[i]);
//        FOR(j, vt.size()) pf("%d ", vt[j]);
//        pf("\n");
        st.insert(vt);
    }
    pf1(st.size());
    return 0;
}














