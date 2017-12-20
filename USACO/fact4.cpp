/*
ID: ovishek1
LANG: C++14
PROB: fact4
*/

#include <bits/stdc++.h>
#define mx 2000002
using namespace std;

int main()
{
    freopen("fact4.in", "r", stdin);
    freopen("fact4.out", "w", stdout);
    int n;
    scanf("%d", &n);
    int fives = 0, mult = 5;
    while(mult <= n)
    {
        fives += n/mult;
        mult *= 5;
    }
    int ans = 1;
    for(int i = 1; i<=n; i++)
    {
        int N = i;
        while(N % 5 == 0) N /= 5;
        while(N%2==0 && fives){
            fives--;
            N /= 2;
        }
        ans = 1ll * ans * N % 10;
    }
    printf("%d\n", ans);
    return 0;
}

