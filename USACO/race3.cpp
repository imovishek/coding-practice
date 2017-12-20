/*
ID: ovishek1
LANG: C++11
PROB: race3
*/
#include <bits/stdc++.h>
#define ll long long
#define mx 55
#define prev prv
using namespace std;
vector<int> dir[mx], undir[mx], revDir[mx];
int n;

bool isConDir(int u){
    int vis[mx];
    memset(vis, 0, sizeof vis);
    vis[u] = 1;
    queue<int> Q;
    Q.push(0);
    while(!Q.empty()){
        u = Q.front(); Q.pop();
        vis[u] = 1;
        if(u==n-1) return 1;
        for(int v : dir[u]){
            if(vis[v] == 0){
                vis[v] = 1;
                Q.push(v);
            }
        }
    }
    int cnt = 0;
    for(int i = 0; i<n; i++)
        cnt += vis[i];
    if(cnt == n) return 1;
    return 0;
}

bool isConUnDir(int u){
    int st = u;
    int vis[mx];
    memset(vis, 0, sizeof vis);
    vis[u] = 1;
    queue<int> Q;
    Q.push(0);
    while(!Q.empty()){
        u = Q.front(); Q.pop();
        vis[u] = 1;
        if(u==n-1) return 1;
        for(int v : undir[u]){
            if(vis[v] == 0){
                vis[v] = 1;
                Q.push(v);
            }
        }
    }
    int cnt = 0;
    for(int i = 0; i<n; i++)
        cnt += vis[i];
    if(cnt == n) return 1;
    cnt = 0;
    for(int i = 0; i<n; i++) if(vis[i] == 1) vis[i] = 0; else vis[i] = 5;
//    memset(vis, 0, sizeof vis);
    Q.push(st);
    while(!Q.empty()){
        u = Q.front(); Q.pop();
        vis[u] = 1;
        for(int v : revDir[u]){
            if(vis[v] == 0){
                vis[v] = 1;
                Q.push(v);
            }
        }
    }
    int sCnt = 0;
    for(int i = 0; i<n; i++)
        if(vis[i] != 5) cnt += vis[i];
//    if(sCnt != cnt) return 1;
    for(int i = 0; i<n; i++) if(vis[i] == 5) vis[i] = 0; else vis[i] = 5;
    memset(vis, 0, sizeof vis);

    Q.push(st);
    while(!Q.empty()){
        u = Q.front(); Q.pop();
        vis[u] = 1;
        for(int v : dir[u]){
            if(vis[v] == 0){
                vis[v] = 1;
                Q.push(v);
            }
        }
    }
    sCnt = 0;
    for(int i = 0; i<n; i++) if(vis[i] != 5) sCnt += vis[i];
    if(sCnt + cnt - 1 == n) return 0;
    return 1;
}

int main()
{
    freopen("race3.in", "r", stdin);
    freopen("race3.out", "w", stdout);
    int v;
    while(cin >> v)
    {
        if(v == -1) break;
        n++;
        int u = n-1;
        do{
            if(v == -2) break;
            dir[u].push_back(v);
            revDir[v].push_back(u);
            undir[u].push_back(v);
            undir[v].push_back(u);
        }while(cin >> v);
    }
    vector<int> a, b;
    for(int i = 1; i<n-1; i++){
        if(isConDir(i)==0) a.push_back(i);
        if(isConUnDir(i)==0) b.push_back(i);
    }
    cout << a.size() ;
    for(int x : a) cout << " " << x;
    cout << endl;
    cout << b.size();
    for(int x : b) cout << " " << x;
    cout << endl;

    return 0;
}

