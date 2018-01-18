/*
ID: ovishek1
LANG: C++14
PROB: ratios
*/

#include <bits/stdc++.h>
#define mx 2000002
using namespace std;
int main()
{
    freopen("ratios.in", "r", stdin);
    freopen("ratios.out", "w", stdout);
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    int ara[3][3];
    for(int i = 0; i<3; i++)
        for(int j = 0; j<3; j++)
            scanf("%d", &ara[i][j]);
    int mini = INT_MAX, ii = -1, jj, kk, ll;
    for(int i = 0; i<=100; i++)
    {
        for(int j = 0; j<=100; j++)
        {
            for(int k = 0; k<=100; k++)
            {
                int x = 0;
                x = ara[0][0] * i + ara[1][0] * j + ara[2][0] * k;
                int y = 0;
                y = ara[0][1] * i + ara[1][1] * j + ara[2][1] * k;
                int z = 0;
                z = ara[0][2] * i + ara[1][2] * j + ara[2][2] * k;
//                if(i==0 && j==38 && k==7) cout << x << " " << y << " " << z << endl;
                if(a==0 && x!=0) continue;
                if(b==0 && y!=0) continue;
                if(c==0 && z!=0) continue;
                int fa = 0, fb = 0, fc = 0;
                if(!a) fa = a = 1;
                if(!b) fb = b = 1;
                if(!c) fc = c = 1;
                if(x%a == 0 && y % b == 0 && z % c == 0 && (fa || fb || x/a == y/b) && (fa || fc || x/a == z/c) && (fb || fc || y/b == z/c)){
                    int A = 0;
                    if(!fa) A = x/a;
                    if(!fb) A = y/b;
                    if(!fc) A = z/c;
                    int now = i + j + k + A;
                    if(mini > now && now)
                    {
                        mini = now;
                        ii = i, jj = j, kk = k, ll = A;
                    }
                }
                if(fa) a = 0;
                if(fb) b = 0;
                if(fc) c = 0;
            }
        }
    }
    if(ii == -1) printf("NONE\n");
    else printf("%d %d %d %d\n", ii, jj, kk, ll);
    return 0;
}

