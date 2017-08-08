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


int main()
{
#ifdef OVI
        // freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
#endif // OVI

    int t, tst = 1;
    map<string, vector< pair<int, string> > > mp;
    mp["February"].pb( mkp(13, "Pohela Falgun") );
    mp["February"].pb( mkp(14, "Valentine's Day") );
    mp["February"].pb( mkp(21, "International Mother Language Day") );
    mp["March"].pb( mkp(8, "International Women's Day") );
    mp["March"].pb( mkp(21, "International Color Day") );
    mp["March"].pb( mkp(26, "Bangladesh Independence Day") );
    mp["April"].pb( mkp(1, "April Fools Day") );
    mp["April"].pb( mkp(14, "Pohela Boishakh") );
    mp["May"].pb( mkp( 1, "May Day") );
    mp["June"].pb( mkp( 19, "Father's Day") );
    mp["July"].pb( mkp( 18, "Mandela Day") );
    mp["August"].pb( mkp( 20, "World Mosquito Day") );
    mp["October"].pb( mkp( 31, "Halloween") );
    mp["November"].pb( mkp( 19, "World Toilet Day") );
    mp["December"].pb( mkp( 10, "Human Rights Day") );
    mp["December"].pb( mkp( 16, "Victory Day of Bangladesh") );
    mp["December"].pb( mkp( 25, "Christmas Day") );

    map<string, string> mp2;
    mp2["February"] = "March";
    mp2["March"] = "April";
    mp2["April"] = "May";
    mp2["May"] = "June";
    mp2["June"] = "July";
    mp2["July"] = "August";
    mp2["August"] = "September";
    mp2["September"] = "October";
    mp2["October"] = "November";
    mp2["November"] = "December";
    mp2["December"] = "January";
    mp2["January"] = "February";

    sf1(t);
    while(t--)
    {
        string m;
        int d;
        cin >> m >> d;
        int f = 0, paisi = 0;
        string ans;
        while(1){
//            cout << m << endl;
            if(f){
                while(mp[m].size()==0) m = mp2[m];
                ans = mp[m][0].sc;
                break;
            }
            if(f==0){
                FOR(i, mp[m].size()){
                    if(mp[m][i].fs>d){
                        ans = mp[m][i].sc;
                        paisi = 1;
                        break;
                    }
                }
                f = 1;
                m = mp2[m];
            }
            if(paisi) break;
        }
        pcase(tst++);
        cout << ans << endl;
    }
    return 0;
}














