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
vector <int> vt(1,1);
int maxi=1;
const string GET = "getMin";
const string REM = "removeMin";
const string INS = "insert";
struct comp{
    bool operator()(const int &a,const int &b)
    {
        return a>b;
    }
};
priority_queue< int ,vector<int>, comp> Q;
int main()
{
    #ifdef OVI
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    #endif
    string cmd;
    int n,a;
    sf1(n);
    vector < pii > vt;
    while(n--)
    {
        cin >> cmd;
        if(cmd==INS){
            sf1(a);
            Q.push(a);
            vt.pb(pii(INS, a));
        }
        else if(cmd==REM){
            if(!Q.size()){Q.push(13);vt.pb( pii(INS, 13));}
            Q.pop();
            vt.pb(pii(REM, inf));
        }
        else if(cmd==GET){
            sf1(a);
            if(!Q.size()){
                Q.push(a);
                vt.pb(pii(INS, a));
                vt.pb(pii(GET, a));
            }
            else if(a==Q.top())
                vt.pb(pii(GET, a));
            else if(a>Q.top()){
                while(Q.size() && a>Q.top()){
                    vt.pb(pii(REM, inf));
                    Q.pop();
                }
                if(!Q.size() || Q.top()!=a){Q.push(a);
                vt.pb(pii(INS, a));}
                vt.pb(pii(GET, Q.top()));
            }
            else if(a<Q.top()){
                Q.push(a);
                vt.pb(pii(INS, a));
                vt.pb(pii(GET, Q.top()));
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
