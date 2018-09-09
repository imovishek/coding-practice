#include<bits/stdc++.h>
using namespace std;
#define mx 100005
char a[mx];
int lps[mx];



int main()
{
    fgets(a+1, 10000, stdin);
    int n = strlen(a+1);
    n--;
    int cur = 1;
    lps[0] = -1;
    lps[1] = 0;
    for(int i = 2; i<=n; i++)
    {
        while(cur != 0 && a[cur] != a[i])
            cur = lps[cur-1] + 1;
        lps[i] = cur++;
    }
}
