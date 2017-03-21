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
#define pcase(x) printf("Case %d: ",x)
#define MX 1000000007
#define inf 1000000007
#define pi acos(-1.0)
#define mem(arr,x) memset((arr), (x), sizeof((arr)));
#define FOR(i,x) for(int i=0;i<(x); i++)

using namespace std;
typedef long long int lint;
typedef double dbl;
int n;
void input(int pos, stack<int> &st)
{
    if(pos==n) return;
    int x;
    sf1(x);
    input(pos+1, st);
    st.push(x);
}
int main()
{
    int t, tst = 1, p;
    while(sf1(n) && n){
        while(sf1(p) && p)
        {
            stack<int> st;
            input(1, st);
            st.push(p);
            stack<int> rail;
            stack<int> ara;
            FOR(i , n) ara.push(n-i);
            int f = 0;
            while(!st.empty())
            {
                int x = st.top();
                if(rail.empty()) {
                    rail.push(ara.top());
                    ara.pop();
                }
                else{

                    if(rail.top()==x){
                        rail.pop();
                        st.pop();
                    }
                    else {
                            if(ara.empty()){f = 1; break;}
                            rail.push(ara.top());
                            ara.pop();
                    }
                }
            }
            if(!f) pf("Yes\n");
            else pf("No\n");
        }
        pf("\n");
    }
    return 0;
}














