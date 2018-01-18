
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

int main()
{
//    freopen("camelot.in", "r", stdin);
//    freopen("camelot.out", "w", stdout);
    scanf("%d %d", &n, &m);
    char ch;
    int y;
    scanf(" %c %d", &ch, &y);
    int qnx = ch - 'A', qny = y - 1;
    swap(qnx, qny);
    vector<pair<int, int> > knights;
    vector<int> knight_king;
    while(scanf(" %c %d", &ch, &y) != EOF)
    {
        int x = ch - 'A';
        y--;
        swap(x, y);
        knights.push_back({x, y});
    }
    for(int i = 0; i<n; i++)
    for(int j = 0; j<m; j++){
            bfs(i, j);
            for(int k = 0; k<n; k++)
                for(int l = 0; l<m; l++)
                    ara[i][j][k][l] = dist[k][l];
    }
    bfs(qnx, qny);
    for(int i = 0; i<n; i++)
        for(int j = 0; j<m; j++)
            qn_dist[i][j] = dist[i][j];
    vector<pair<int, int> > qn;
    vector<int> qDist;
    for(auto x : knights)
    {
        int X, Y, mini = INT_MAX;
        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j<m; j++)
            {
                int qdist = max(abs(i - qnx), abs(j - qny)) + ara[i][j][x.first][x.second];
                if(qdist < mini)
                {
                    mini = qdist;
                    X = i, Y = j;
                }
            }
        }
        qn.push_back({X, Y});
        qDist.push_back(mini);
    }
    int mini = INT_MAX;
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<m; j++)
        {
            bfs(i, j);
            int sum = 0;
            for(auto x : knights)
                sum += dist[x.first][x.second];
            int distx = abs(i - qnx), disty = abs(j - qny);
            sum += max(distx, disty);
            mini = min(mini, sum);
            sum -= max(distx, disty);
            for(int k = 0; k<knights.size(); k++)
            {
                int qX = qn[k].first;
                int qY = qn[k].second;
                cout << qX << " " << qY << endl;
                mini = min(mini, sum - dist[knights[k].first][knights[k].second] + qDist[k] + dist[qX][qY]);
            }

        }
    }
    printf("%d\n", mini);
    return 0;
}
