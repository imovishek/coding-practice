/*
ID: ovishek1
LANG: C++11
PROB: job
*/

#include <bits/stdc++.h>
using namespace std;
#define mx 405


int main()
{
    freopen("job.in", "r", stdin);
    freopen("job.out", "w", stdout);
    int n, a, b;
    scanf("%d %d %d", &n, &a, &b);
    int arr[a], brr[b];
    for(int i = 0; i<a; i++)
        scanf("%d", &arr[i]);
    for(int i = 0; i<b; i++)
        scanf("%d", &brr[i]);
    sort(brr, brr+b);
    reverse(brr, brr+b);
    int l = 1, r = 100005;
    vector<pair<int, int> > ans;
    while(l <= r)
    {
        int t = (l + r)/2;
//        cout << t << endl;
        vector<int> vt;
        for(int i = 0; i<a; i++)
        {
            int cnt = t / arr[i];
            for(int j = 1; j<=cnt; j++)
            {
                vt.push_back(j * arr[i]);
            }
        }
        if(vt.size() < n) {
            l = t+1;
            continue;
        }
        int found = 0;
        sort(vt.begin(), vt.end());
        int li = 1, ri = 100005;
        while(li <= ri){
            int T = (li + ri)/2;
            vector<pair<int, int> > tm(b);
            for(int i = 0; i<b; i++)
                tm[i] = {t+T, brr[i]};
            int cannot = 0;
            for(int i = n-1; i>=0; i--)
            {
                sort(tm.begin(), tm.end());
            reverse(tm.begin(), tm.end());
//                    for(auto x : tm)
//                        cout << x.first << "," << x.second << " ";
//                    cout << endl;
//                cout << vt[i] << "**" << endl;
                int f = 0, pos = -1;
                for(int j = 0; j<b; j++)
                {
                    if( vt[i] + tm[j].second <= tm[j].first ){
                        tm[j].first = max(vt[i], tm[j].first - tm[j].second);
                        f = 1;
                        break;
                    }
                }
                if( f==0 ) {cannot = 1; li = T+1; break;}
            }
            if(cannot == 0) {
                ans.push_back({t, t+T});
                found = 1;
                r = t - 1;
                ri = T - 1;

            }
        }
        if(!found) l = t + 1;
    }
    sort(ans.begin(), ans.end());
    printf("%d %d\n", ans[0].first, ans[0].second);

    return 0;
}



