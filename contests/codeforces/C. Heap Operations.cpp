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
#define pii pair<string,int>
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
#define inf 2147483647
using namespace std;
typedef long long int lint;
typedef double dbl;
int heap[100007];
vector <int> vt(1,1);
int maxi=1;
const string GET = "getMin";
const string REM = "removeMin";
const string INS = "insert";
void inserti(int val)
{
    int node=maxi;
    heap[node]=val;
    maxi++;
    while( node>1 && heap[node]<heap[node/2]){
        swap(heap[node], heap[node/2]);
        node/=2;
    }
}
void remvmin()
{
    heap[1]=heap[maxi];
    int node=1;
    while( 1 )
    {
        int left=node*2;
        if(heap[node]<= heap[left] && heap[node]<= heap[left+1]) break;
        if(heap[left]<heap[left+1]) {swap(heap[node], heap[left]); node=left;}
        else {swap(heap[node], heap[left+1]); node=left+1;}
    }
    heap[maxi]=inf;
    maxi--;
}
int main()
{
    #ifdef OVI
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    #endif

    for(int i=1;i<100007;i++) heap[i]=inf;
    string cmd;
    int n,a;
    sf1(n);
    vector < pii > vt;
    while(n--)
    {
        cin >> cmd;
        if(cmd==INS){
            sf1(a);
            inserti(a);
            vt.pb(pii(INS, a));
        }
        else if(cmd==REM){
            if(heap[1]==inf){inserti(13);vt.pb( pii(INS, 13));}
            remvmin();
            vt.pb(pii(REM, inf));
        }
        else if(cmd==GET){
            sf1(a);
            if(a==heap[1])
                vt.pb(pii(GET, a));
            else if(a>heap[1]){
                while(a>=heap[1]){
                    vt.pb(pii(REM, inf));
                    remvmin();
                }
                inserti(a);
                vt.pb(pii(INS, a));
                vt.pb(pii(GET, heap[1]));
            }
            else if(a<heap[1]){
                inserti(a);
                vt.pb(pii(INS, a));
                vt.pb(pii(GET, heap[1]));
            }
        }
    }
    pf("%d\n",vt.size());
    for(int i=0;i<vt.size();i++){
        cout << vt[i].fs;
        if(vt[i].sc!=inf){
            cout << ' ' << vt[i].sc ;
        }
        puts("");
    }
    return 0;
}
