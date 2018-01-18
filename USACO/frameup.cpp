/*
ID: ovishek1
LANG: C++11
PROB: frameup
*/

#include <bits/stdc++.h>
using namespace std;
char grid[35][35];
char tmp[35][35];
int n, m;
int getMinX(char ch)
{
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<m; j++)
        {
            if(grid[i][j] == ch) return i;
        }
    }
    return -1;
}

int getMaxX(char ch)
{
    for(int i = n-1; i>=0; i--)
    {
        for(int j = 0; j<m; j++)
        {
            if(grid[i][j] == ch) return i;
        }
    }
}

int getMinY(char ch)
{
    for(int j = 0; j<m; j++)
    {
        for(int i = 0; i<n; i++)
        {
            if(grid[i][j] == ch) return j;
        }
    }
}

int getMaxY(char ch)
{
    for(int j = m-1; j>=0; j--)
    {
        for(int i = 0; i<n; i++)
        {
            if(grid[i][j] == ch) return j;
        }
    }
}
struct data{
    int x1, y1, x2, y2;
    data(int a, int b, int c, int d){
        x1 = a, y1 = b, x2 = c, y2 = d;
    }
    data(){}
};

vector<char> st;
data vt[200];
vector<char> now;
int vis[26];
void rec(int pos, int sig)
{
    if(pos==st.size()){
//        for(int i = 0; i<n; i++)
//            for(int j = 0; j<m; j++)
//                tmp[i][j] = '.';
////        string sst = "";
//        for(int i = 0; i<now.size(); i++)
//        {
//            data x = vt[now[i]];
////            sst += now[i];
//            for(int j = x.x1; j <= x.x2; j++)
//                tmp[j][x.y1] = tmp[j][x.y2] = now[i];
//            for(int k = x.y1; k <= x.y2; k++)
//                tmp[x.x1][k] = tmp[x.x2][k] = now[i];
//        }
//        if(sst == "EDABC"){
//            for(int i = 0; i<n; i++)
//                for(int j = 0; j<m; j++, (j==m?printf("\n"):1))
//                    printf("%c", tmp[i][j]);
//        }
//        int f = 0;
//        for(int i = 0; i<n; i++)
//            for(int j = 0; j<m; j++)
//                if(grid[i][j] != tmp[i][j]) f = 1;
//        if(!f){
            for(char ch : now)
                printf("%c", ch);
            printf("\n");
//        }
        return;
    }
    for(int i = 0; i<st.size(); i++)
    {
        if(vis[i] == 0){
            vis[i] = 1;
            now.push_back(st[i]);
            rec(pos+1);
            now.pop_back();
            vis[i] = 0;
        }

    }
}
int in[200];
vector<char> edge[200];
void top_order()
{
    vector<char> order;
    int f = 0;
    while(1){
        f = 0;
        for(int i = 0; i<st.size(); i++)
        {
            if(in[st[i]] == 0) {
                f = 1;
                for(char ch : edge[st[i]])
                {
                    in[ch] --;
                }
                in[st[i]] = -1;
                order.push_back(st[i]);
                break;
            }
        }
        if(f==0) break;
    }
    st = order;
//    for(char ch : st) cout << ch << endl;
}
/*input
6 9
AAABBBCCC
AQAQQQCQC
AAABBBCCC
XQXYYYZQZ
XQQYQYQQZ
XXXYYYZZZ
*/
int main()
{
//    freopen("frameup.in", "r", stdin);
//    freopen("frameup.out", "w", stdout);
    scanf("%d %d", &n, &m);
    for(int i = 0; i<n; i++)
        scanf("%s", grid[i]);
    for(char ch  = 'A'; ch <= 'Z'; ch++)
    {
        if(getMinX(ch) == -1) continue;
        st.push_back(ch);
        vt[ch] = data(getMinX(ch), getMinY(ch), getMaxX(ch), getMaxY(ch));
//        printf("%d %d %d %d\n", vt[ch].x1, vt[ch].y1, vt[ch].x2, vt[ch].y2);
    }
    for(int i = 0; i<st.size(); i++)
    {
        data x = vt[st[i]];
        for(int j = x.x1; j <= x.x2; j++){
            if(grid[j][x.y1] != st[i]) {
                edge[st[i]].push_back(grid[j][x.y1]);
                in[grid[j][x.y1]]++;
            }
            if(grid[j][x.y2] != st[i]){
                edge[st[i]].push_back(grid[j][x.y2]);
                in[grid[j][x.y2]]++;
            }
        }
        for(int j = x.y1; j <= x.y2; j++){
            if(grid[x.x1][j] != st[i]) {
                edge[st[i]].push_back(grid[x.x1][j]);
                in[grid[x.x1][j]]++;
            }
            if(grid[x.x2][j] != st[i]) {
                edge[st[i]].push_back(grid[x.x2][j]);
                in[grid[x.x2][j]]++;
            }
        }
    }
    top_order();
//    for(char ch : st)
//        cout << ch;
    rec(0);
    return 0;
}
