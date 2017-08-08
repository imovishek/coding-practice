#include<bits/stdc++.h>
using namespace std;
typedef long long int lint;
int eulerphi(int n)
{
    int tn = n;
    for(int i = 2; i*i<=tn ; i++)
        if(tn%i==0) {while(tn%i==0) tn/=i; n -= n/i;}
    if(tn>1) n-=n/tn;
    return n;
}
int main()
{
    int t, tst = 1;
    int n, k;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &n, &k);
        lint ans = 1LL * eulerphi(n) * (k-1);
        cout << ans << endl;
    }
    return 0;
}
