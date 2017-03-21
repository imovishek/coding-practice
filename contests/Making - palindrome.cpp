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
using namespace std;
typedef long long int lint;
typedef double dbl;
int main()
{
    int ara[26];
    string a,ans;
    int t,tst=1;
    sf("%d",&t);
    getchar();
    while(t--)
    {
        memset(ara,0,sizeof(ara));
        cin >> a;
        for(int i=0;i<a.length();i++)
            ara[a[i]-'a']++;
            cout<< a << endl;
        for(int i=0;i<26;i++){
            if(ara[i]!=0){
                while(ara[i]>1)
                {
                    ans+=i+'a';
                    ara[i]-=2;
                }
            }
        }
        int flag=0;
        for(int i=0;i<26;i++){
            if(ara[i]==1 && flag==0)flag=1;
            else if(ara[i]==1){flag=-1;break;}
        }
        pcase(tst++);
        if(flag==-1)pf("impossible");
        if(flag==0){
                cout<<ans;
                for(int i=ans.length()-1; i>=0; i--)
                    cout<<ans[i];
        }
        if(flag==1){
                cout<<ans;
                for(int i=0;i<26;i++)if(ara[i]==1)pf("%c",i+'a');
                for(int i=ans.length()-1; i>=0; i--)
                    pf("%c",ans[i]);
        }
        pf("\n");
        ans="";
    }
    return 0;
}
