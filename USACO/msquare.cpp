/*
ID: ovishek1
LANG: C++11
PROB: msquare
*/
#include <bits/stdc++.h>
#define mx 100005
using namespace std;

struct State{
    char ara[2][4];
    string toString()
    {
        string ret = "";
        for(int i = 0; i<2; i++)
            for(int j = 0; j<4; j++)
                ret += ara[i][j];
        return ret;
    }
    void print()
    {
        for(int i = 0; i<2; i++)
        {
            for(int j = 0; j<4; j++)
                cout << ara[i][j] << " ";
            cout << endl;
        }
    }
};
map< string, int > mp;
int cnt = 0;
State states[100005];
int getIndx(State &a)
{
    string now = a.toString();
    if(mp.count(now)) return mp[now];
    else {
            mp[now] = cnt++;
            states[cnt-1] = a;
            return cnt - 1;
    }
}

int dist[mx];
State chalA(int u)
{
    State ret = states[u];
    for(int i = 0; i<4; i++)
    {
        swap(ret.ara[0][i], ret.ara[1][i]);
    }
    return ret;
}
State chalB(int u)
{
    State ret = states[u];
    int x = ret.ara[0][3], y = ret.ara[1][3];
    for(int i = 3; i>=1; i--)
        ret.ara[0][i] = ret.ara[0][i-1],
        ret.ara[1][i] = ret.ara[1][i-1];
    ret.ara[0][0] = x;
    ret.ara[1][0] = y;
    return ret;
}
State chalC(int u)
{
    State ret = states[u];
    int x = ret.ara[0][1];
    ret.ara[0][1] = ret.ara[1][1];
    ret.ara[1][1] = ret.ara[1][2];
    ret.ara[1][2] = ret.ara[0][2];
    ret.ara[0][2] = x;
    return ret;
}
State (*p[3])(int u) = {chalA, chalB, chalC};
State endi;
bool isok(State &st)
{
    for(int i = 0; i<2; i++)
        for(int j = 0; j<4; j++)
            if(st.ara[i][j] != endi.ara[i][j]) return 0;
    return 1;
}
int par[mx];
int chal[mx];
int bfs(State &from)
{
    int u = getIndx(from);
    queue<int> Q;
    Q.push(u);
    dist[u] = 0;
    while(!Q.empty())
    {
        u = Q.front();
//        states[u].print();
        if(isok(states[u])){
            return u;
        }
        Q.pop();
        for(int i = 0; i<3; i++)
        {
            State to = (*p[i])(u);
            int v = getIndx(to);
            if(dist[v] == -1){
                dist[v] = dist[u] + 1;
                par[v] = u;
                chal[v] = i;
                Q.push(v);
            }
        }
    }
}
char st[mx];
int main()
{
    freopen("msquare.in", "r", stdin);
    freopen("msquare.out", "w", stdout);
    memset(dist, -1, sizeof dist);
    State start;
    start.ara[0][0] = '1';
    start.ara[0][1] = '2';
    start.ara[0][2] = '3';
    start.ara[0][3] = '4';
    start.ara[1][3] = '5';
    start.ara[1][2] = '6';
    start.ara[1][1] = '7';
    start.ara[1][0] = '8';
//    start.print();
//    chalC(getIndx(start)).print();
    char ara[8];
    for(int i = 0; i<8; i++)
    {
        scanf(" %c", &ara[i]);
    }
    endi.ara[0][0] = ara[0];
    endi.ara[0][1] = ara[1];
    endi.ara[0][2] = ara[2];
    endi.ara[0][3] = ara[3];
    endi.ara[1][3] = ara[4];
    endi.ara[1][2] = ara[5];
    endi.ara[1][1] = ara[6];
    endi.ara[1][0] = ara[7];

    int u = bfs(start);
    int v = getIndx(start);
    int ans = 0;
    while(u != v)
    {
        st[ans++] = char('A' + chal[u]);
        u = par[u];
    }
    printf("%d\n", ans);
    int printed = 0, f = 0;
    for(int i = ans-1; i>=0; i--)
    {
        printf("%c", st[i]);
        printed++;
        f = 1;
        if(printed == 60) printf("\n"), printed = 0;
    }
    if(printed || f==0) printf("\n");
    return 0;
}
