/*
ID: ovishek1
LANG: C++14
PROB: stamps
*/

#include <bits/stdc++.h>
#define mx 2000002
using namespace std;
bool dp[2000002];
unsigned char mini[2000002];
int ara[50];
int main()
{
//    mini[0] = 200;
//    cout << (int)mini[0] << endl;
    freopen("stamps.in", "r", stdin);
    freopen("stamps.out", "w", stdout);
    int k, n;
    scanf("%d %d", &k, &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &ara[i]);
    dp[0] = 1;
    mini[0] = 0;
    for(int i = 1; i<mx; i++)
        mini[i] = 201;
    for(int i = 0; i<n; i++)
    {
        for(int j = ara[i]; j<mx; j++)
        {
            dp[j] = dp[j-ara[i]] | dp[j];
            mini[j] = min(mini[j], (unsigned char)min(201, mini[j-ara[i]] + 1));
        }
    }
    for(int i = 1; i<mx; i++){
//        cout << (int)mini[i] << " ";
        if(mini[i] > k){
            printf("%d\n", i-1);
            break;
        }
    }
    return 0;
}
