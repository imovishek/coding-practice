/*
ID: ovishek1
LANG: C++11
PROB: lgame
*/
#include <bits/stdc++.h>
#define ll long long
#define mx 105
using namespace std;

map<string, int> mp;
int val[] = {2,5,4,4,1,6,5,5,1,7,6,3,5,2,3,5,7,2,1,2,4,6,6,7,5,7};
int getValue(string st)
{
    int ret = 0;
    for(char ch : st)
        ret += val[ ch - 'a' ];
    return ret;
}
int hvalue[35000];
vector<string> ara[35000];
vector<char> a, b;
vector<pair<string, string> > ans;
string st;
int n, maxi = 0;
int getId(string st)
{
    if(mp.find(st) == mp.end()) return -1;
    return mp[st];
}
int cnt = 0;
int rec(int pos)
{
    if(pos == n) {
        string x, y;
        for(char ch : a) x += ch;
        for(char ch : b) y += ch;
        int idA = getId(x), idB = getId(y);
        if(idA != -1 && idB != -1){
//        if(cnt++ < 10)cout << x << " " << y << " " << hvalue[idA] + hvalue[idB]<< endl;
            if(hvalue[idA] + hvalue[idB] > maxi){
                maxi = hvalue[idA] + hvalue[idB];
                ans = vector<pair<string, string> >();
                if(idA == idB){
                    for(string ax : ara[idA]) ans.push_back({ax, ax});
                    return 0;
                }
                for(string ax : ara[idA])
                    for(string by : ara[idB])
                        ans.push_back({ax, by});
            }
            else if(hvalue[idA] + hvalue[idB] == maxi){
                if(idA == idB){
                    for(string ax : ara[idA]) ans.push_back({ax, ax});
                    return 0;
                }
                for(string ax : ara[idA])
                    for(string by : ara[idB])
                        ans.push_back({ax, by});
            }
        }
        return 0;
    }
    a.push_back(st[pos]);
    rec(pos+1);
    a.pop_back();

    b.push_back(st[pos]);
    rec(pos+1);
    b.pop_back();

    rec(pos+1);
    return 0;
}
int main()
{
//    cout << getValue("program") << endl;
    ifstream in("lgame.dict");
    int cnt = 1;
    while(in >> st){
        string main_st = st;
        sort(st.begin(), st.end());
        if(mp.find(st) == mp.end()) mp[st] = cnt++, hvalue[cnt-1] = getValue(st);
        ara[mp[st]].push_back(main_st);
    }
    mp[""] = 0;
    ara[0].push_back("");
    freopen("lgame.in", "r", stdin);
    freopen("lgame.out", "w", stdout);
    cin >> st;
    n = st.length();
    sort(st.begin(), st.end());
    rec(0);
    map< pair<string, string>, bool > map_ans;
    for(auto x : ans){
        if(x.first > x.second) swap(x.first, x.second);
        if(x.first == "") swap(x.first, x.second);
        map_ans[x] = 1;
    }
    printf("%d\n", maxi);
    for(auto x : map_ans){
        cout << x.first.first;
        if(x.first.second != "") cout << " " << x.first.second;
        cout << endl;
    }
    return 0;
}


