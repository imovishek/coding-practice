
/*
ID: ovishek1
LANG: C++11
PROB: camelot
*/


#include <bits/stdc++.h>
using namespace std;
#define mx 805
int ara[30][26][30][26];
int dist[30][26];
int qn_dist[30][26];
int fx[] = {-1,-1,1,1,-2,-2,2,2};
int fy[] = {2,-2,2,-2,1,-1,1,-1};
int n, m;
int isvali(int x, int y)
{
    return x > -1 && y > -1 && x < n && y < m;
}
void bfs(int x, int y)
{
    memset(dist, -1, sizeof dist);
    queue<pair<int, int> > Q;
    Q.push({x, y});
    dist[x][y] = 0;
    while(!Q.empty())
    {
        auto top = Q.front(); Q.pop();
        x = top.first, y = top.second;
        for(int i = 0; i<8; i++)
        {
            int a = x + fx[i];
            int b = y + fy[i];
            if(isvali(a, b) && dist[a][b]==-1)
            {
                dist[a][b] = dist[x][y] + 1;
                Q.push({a, b});
            }
        }
    }
}
int qnx, qny;
int bara[30][26][30][26];
int disti[30][26][2];
struct data{
    int val, x, y, state;
    data(){}
    data(int val, int x, int y, int state) : val(val), x(x), y(y), state(state) {}
    bool operator<(const data &a) const{
        return val > a.val;
    }
};
int queen_distance(int x, int y)
{
    int distx = abs(x - qnx), disty = abs(y - qny);
    return max(distx, disty);
}
void dijkstra(int x, int y)
{
    for(int i = 0; i<30; i++)
        for(int j = 0; j<26; j++)
            for(int k = 0; k<2; k++)
                disti[i][j][k] = INT_MAX;
    disti[x][y][0] = 0;
    priority_queue< data > pQ;
    pQ.push(data(0, x, y, 0));
    int ax = x, ay = y;
    while(!pQ.empty())
    {
        data top = pQ.top(); pQ.pop();
        x = top.x, y = top.y;
        int d = top.val, state = top.state;
        if(state == 1){
            bara[ax][ay][x][y] = disti[x][y][1];
        }
        for(int i = 0; i<8; i++)
        {
            int a = x + fx[i];
            int b = y + fy[i];
            if(isvali(a, b) && d + 1 < disti[a][b][state])
            {
                disti[a][b][state] = d + 1;
                pQ.push(data(d+1, a, b, state));
            }
        }
        if(state == 0 && disti[x][y][1] > d + queen_distance(x, y)){
            disti[x][y][1] = d + queen_distance(x, y);
            pQ.push(data(disti[x][y][1], x, y, 1));
        }
    }
}

int main()
{
    freopen("camelot.in", "r", stdin);
    freopen("camelot.out", "w", stdout);
    scanf("%d %d", &n, &m);
    char ch;
    int y;
    scanf(" %c %d", &ch, &y);
    qnx = ch - 'A', qny = y - 1;
    swap(qnx, qny);
    vector<pair<int, int> > knights;
    vector<int> knight_king;
    while(scanf(" %c %d", &ch, &y) != EOF)
    {
        int x = ch - 'A';
        y--;
        swap(x, y);
        knights.push_back({x, y});
        dijkstra(x, y);
    }
    for(int i = 0; i<n; i++)
        for(int j = 0; j<m; j++){
                bfs(i, j);
                for(int k = 0; k<n; k++)
                    for(int l = 0; l<m; l++)
                        ara[i][j][k][l] = dist[k][l] == -1 ? 1000007 : dist[k][l];
        }
    int mini = INT_MAX;
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<m; j++)
        {
            int sum = 0;
            for(auto x : knights)
                sum += ara[i][j][x.first][x.second];
            sum += queen_distance(i, j);
            mini = min(mini, sum);
//            cout << i << " " << j << " " << sum << endl;
            sum -= queen_distance(i, j);
            for(int k = 0; k<knights.size(); k++)
            {
                int X = knights[k].first;
                int Y = knights[k].second;
                if(ara[X][Y][i][j] == 1000007 || bara[X][Y][i][j] == INT_MAX) continue;
                mini = min(mini, sum - ara[X][Y][i][j] + bara[X][Y][i][j]);
            }

        }
    }
    printf("%d\n", mini);
    return 0;
}
/*
2 26
        A 1
        Y 1
*/
