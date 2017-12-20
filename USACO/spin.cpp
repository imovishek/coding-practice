/*
ID: ovishek1
LANG: C++11
PROB: spin
*/
#include <bits/stdc++.h>
using namespace std;
int speed[5];
vector<pair<int, int> > wedges[5];
bool isInside(int x, int a, int b)
{
    if(a <= b){
//        cout << "hi" << endl;
        return a <= x && x <= b;
    }
//    cout << "ih" << endl;
//    cout << a << " " << x << " " << b << endl;
    return a <= x || x <= b;
}
bool isok(int t)
{
    vector<pair<int, int> > tempWedges[5];
    for(int i = 0; i<5; i++){
        for(auto x : wedges[i])
        {
            int first = x.first + speed[i] * t;
            int second = x.second + speed[i] * t;
            tempWedges[i].push_back({first%360, second%360});
        }
    }
    for(int i = 0; i<=365; i++)
    {
        int F = 0;
        for(int j = 0; j<5; j++)
        {
            int f = 0;
            for(auto x : tempWedges[j])
            {
                if(isInside(i, x.first, x.second)) {
                    f = 1;
                    break;
                }
            }
            if(f==0) {
                F = 1;
                break;
            }
        }
        if(F==0) return 1;
    }
    return 0;
}
int main()
{
    freopen("spin.in", "r", stdin);
    freopen("spin.out", "w", stdout);
    int n = 5;
    for(int i = 0; i<5; i++)
    {
        scanf("%d", &speed[i]);
        int w;
        scanf("%d", &w);
        while(w--)
        {
            int x, y;
            scanf("%d %d", &x, &y);
            y += x;
            wedges[i].push_back({x, y});
        }
    }

    for(int i = 0; i<10005 ; i++)
    {
        if(isok(i)) cout << i << endl, exit(0);
    }
    cout << "none" << endl;

    return 0;
}
