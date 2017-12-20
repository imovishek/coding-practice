/*
ID: ovishek1
LANG: C++11
PROB: fence9
*/
#include <bits/stdc++.h>
#define prev prevsource
using namespace std;

int main()
{
    freopen("fence9.in", "r", stdin);
    freopen("fence9.out", "w", stdout);
    int m, n, p;
    scanf("%d %d %d", &n, &m, &p);
    cout << (m * p - (__gcd(n, m) + __gcd(abs(n-p), m) + p) + 2)/2 << endl;

    return 0;
}

