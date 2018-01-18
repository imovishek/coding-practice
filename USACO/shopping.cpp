/*
ID: ovishek1
LANG: C++11
PROB: shopping
*/

#include <bits/stdc++.h>
using namespace std;
#define mx 805
int s;
int priceOffer[100];
vector< pair<int, int> > offer[100];
int n;
int howMany[5];
int price[5];
int product[5];
int lagbo[1000];
bool isok(int a[5])
{
    for(int i = 0; i<n; i++)
        if( a[i] ) return 0;
    return 1;
}
int dp[6][6][6][6][6];
int rec(int a[5])
{
    if(isok(a)) return 0;
    int &ret = dp[a[0]][a[1]][a[2]][a[3]][a[4]];
    if(ret != -1) return ret;
    ret = 0;
    for(int i = 0; i<n; i++)
        ret += price[i] * a[lagbo[ product[i] ]];
//    cout << ret << endl;
    for(int i = 0; i<s ; i++)
    {
        int f = 0;
        for(auto p : offer[i]){
            if(p.first > a[lagbo[p.second]]) {
                f = 1;
                break;
            }
        }
        if(f) continue;
        for(auto p : offer[i]){
            a[lagbo[p.second]] -= p.first;
        }
        ret = min(ret, priceOffer[i] + rec(a));
        for(auto p : offer[i]){
            a[lagbo[p.second]] += p.first;
        }
    }
    return ret;
}
int main()
{
    freopen("shopping.in", "r", stdin);
    freopen("shopping.out", "w", stdout);

    scanf("%d", &s);
    for(int i = 0; i<s; i++)
    {
        int nn;
        scanf("%d", &nn);
        for(int j = 0; j<nn; j++)
        {
            int k, c;
            scanf("%d %d", &c, &k);
            offer[i].push_back({k, c});
        }
        scanf("%d", &priceOffer[i]);
    }
    scanf("%d", &n);
    for(int i = 0; i<n; i++)
    {
        scanf("%d %d %d", &product[i], &howMany[i], &price[i]);
        lagbo[product[i]] = i;
    }
    memset(dp, -1, sizeof dp);
    int ans = rec(howMany);
    printf("%d\n", ans);
    return 0;
}
