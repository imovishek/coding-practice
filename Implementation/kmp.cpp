#include<bits/stdc++.h>
using namespace std;
#define mx 100005
char a[mx];
int faila[mx];
int main()
{
    gets(a+1);
    int n = strlen(a+1);
    int cur = 1;
    faila[0] = -1;
    faila[1] = 0;
    for(int i = 2; i<=n; i++)
    {
        while(cur != 0 && a[cur] != a[i])
            cur = faila[cur-1] + 1;
        faila[i] = cur++;
    }
}
