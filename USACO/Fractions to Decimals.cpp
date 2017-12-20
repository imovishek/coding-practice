/*
ID: ovishek1
LANG: C++11
PROB: fracdec
*/
#include <bits/stdc++.h>
#define prev prevsource
using namespace std;
int prev[1000005];
int ans[100005];
int printed = 0;
void print(char ch)
{
    if(printed == 76) cout << endl, printed = 0;
    cout << ch;
    printed++;
}
int main()
{
    freopen("fracdec.in", "r", stdin);
    freopen("fracdec.out", "w", stdout);
    int n, d;
    scanf("%d %d", &n, &d);
    if(n%d == 0){
        printf("%d.0\n", n/d);
        return 0;
    }
    int loopST = -1, loopEN = -1;
    char st[100];
    sprintf(st, "%d.", n/d);
    printf("%d.", n/d);
    printed = strlen(st);
    n %= d;
    int pos = 1;
    for(int i = 1; n ; i++)  //982 4885
    {
        int f = 0;
        int cnt = 0;
        prev[n] = pos;
        n *= 10;
        while(n < d) {
            if(prev[n]){
                f = 1;
                loopST = prev[n];
                loopEN = pos;
                break;
            }
            prev[n/10] = pos;
            ans[pos++] = 0;
            n *= 10;
        }
        //cout << n << endl;
        if(f) break;
        if(prev[n]){
            loopST = prev[n];
            loopEN = pos - 1;
            break;
        }
        prev[n/10] = pos;
        ans[pos++] = n/d;
        n %= d;
        if(prev[n]){
            loopST = prev[n];
            loopEN = pos - 1;
            break;
        }
    }
    if(loopST != -1){
        for(int i = 1; i<loopST; i++){
            print(ans[i] + '0');
        }

        print('(');

        for(int i = loopST; i <= loopEN; i++)
            print(ans[i] + '0');
        print(')');
        cout << endl;
    }
    else{
        for(int i = 1; i<pos; i++)
            print(ans[i] + '0');
        cout << endl;
    }
    return 0;
}
