/*
ID: ovishek1
LANG: C++14
PROB: kimbits
*/

#include <bits/stdc++.h>
#define mx 2000002
using namespace std;
int nCr[50][50];
long long fun(int n, int l)
{
    long long ans = 1;
    for(int i = 1; i<=min(l, n); i++)
        ans += nCr[n][i];
    return ans;
}
int main()
{
    for(int i = 0; i<50; i++) nCr[i][i] = nCr[i][0] = 1;
    for(int i = 1; i<50; i++)
        for(int j = 1; j<i; j++)
            nCr[i][j] = nCr[i-1][j-1] + nCr[i-1][j];
    //cout << nCr[5][3] << endl;
    freopen("kimbits.in", "r", stdin);
    freopen("kimbits.out", "w", stdout);
    long long n, l, I;
    scanf("%lld %lld %lld", &n, &l, &I);
    string st;
//    cout << fun(n-2, l) << endl;
    for(int i = n; i>=1; i--)
    {
        if(I > fun(i-1, l)){
            I -= fun(i-1, l);
            st += "1";
            l--;
        }
        else st += "0";
    }
    cout << st << endl;
    return 0;
}

