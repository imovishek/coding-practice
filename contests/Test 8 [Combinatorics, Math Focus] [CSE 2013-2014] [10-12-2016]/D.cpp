/*
OVISHEK PAUL, CSE - 15, SUST

*/

#include<bits/stdc++.h>
#define pf printf
#define sf scanf
int main()
{
    int t, tst = 1;
    int n, m;
    while(sf("%d %d",&n, &m)){
        if(n==0 && m==0) return 0;
        double ans = 0, a = n, b = m;
        if(n<m) a = n;
        if(n>m) ans = 0;
        else ans = (b-a+1)/(b+1);
        pf("%.6lf\n", ans);
    }
    return 0;
}
