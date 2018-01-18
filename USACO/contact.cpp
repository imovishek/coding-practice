/*
ID: ovishek1
LANG: C++11
PROB: contact
*/
#include <bits/stdc++.h>
using namespace std;

int cnt[1000006];
string st;
int fun(int n)
{
    if(n==0) return 0;
    fun(n/3);
    printf("%d", (n%3) - 1);
}
int main()
{
    freopen("contact.in", "r", stdin);
    freopen("contact.out", "w", stdout);
    int a, b, n;
    scanf("%d %d %d", &a, &b, &n);
    string ast;
    while(cin >> ast){st += ast;}

    int len = st.length();
    for(int i = 0; i<len; i++){
        int num = 0;
        for(int j = i; j<len; j++)
        {
            if(j - i + 1 > b) break;
            num = num * 3 + (st[j] - '0' + 1);
            if(j - i + 1 >= a)
                cnt[num]++;
        }
    }
    priority_queue<pair<int, int> > pQ;
    for(int i = 0; i<1000006; i++)
    {
        if(cnt[i]){
            pQ.push({cnt[i], -i});
        }
    }
    //cout << "hi" << endl;
    int now = -1, f = 0, cnt = 0;
    while(!pQ.empty())
    {
        auto top = pQ.top(); pQ.pop();
        top.second*=-1;
        if(top.first != now) {
                if(n==0) break;
                if(f && cnt) printf("\n");
                f = 1;
                printf("%d\n", top.first), fun(top.second), n--;
                cnt = 1;
        }
        else {
            if(cnt) printf(" ");
            fun(top.second);
            cnt++;
            if(cnt == 6) printf("\n"), cnt = 0;

        }
        now = top.first;
    }
    if(cnt) printf("\n");
    return 0;
}
