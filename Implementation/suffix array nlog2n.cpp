/*input
ababab
*/
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstring>
#include <deque>
using namespace std;

#define mx 100005
#define ll long long
#define MOD 1000000007
#define fs first
#define sc second
/*
5 : a 0
3 : aba 1
1 : ababa 3
4 : ba 0
2 : baba 2
0 : bababa 4
*/
struct tup{
	int x, y, indx;
	bool operator<(const tup a) { return make_pair(x, y) < make_pair(a.x, a.y);}
} ara[mx];
char text[mx];
int step, Rank[18][mx], LCP[mx], n;
void printSALCP(){
    for(int i = 0; i<n; i++)
    {
        cout << ara[i].indx << " : " ;
        for(int j = ara[i].indx; j<n; j++) cout << text[j];
        cout << " " << LCP[i] << endl;
    }
}
void buildSuffixArray()
{
	n = strlen(text);
	for(int i = 0; i<n; i++)
		Rank[0][i] = text[i];
    int now;
	for(step = 1, now = 1; now <= n; now<<=1, step++)
	{
		for(int i = 0; i<n; i++)
		{
			ara[i].x = Rank[step-1][i];
			ara[i].y = i + now >= n ? -1 : Rank[step-1][i+now];
			ara[i].indx = i;
		}
		sort(ara, ara+n);
		Rank[step][ara[0].indx] = 0;
		for(int i = 1; i<n; i++)
		{
            Rank[step][ara[i].indx] = ara[i].x==ara[i-1].x && ara[i].y==ara[i-1].y ? Rank[step][ara[i-1].indx] : i;
		}
	}
}

ll ans = 0;
void buildLcpArray()
{
    LCP[0] = 0;
    for(int i = 1; i<n; i++){
        int id1 = ara[i-1].indx;
        int id2 = ara[i].indx;
        LCP[i] = 0;
        for(int j = step; j>=0; j--)
        {
            if(Rank[j][id1] == Rank[j][id2] && id1 + (1<<j) <= n && id2 + (1<<j) <= n)
            {
                id1 += (1<<j);
                id2 += (1<<j);
                LCP[i] += (1<<j);
            }
        }
        ans -= LCP[i];
    }
}

int main()
{
    scanf("%s", text);
    buildSuffixArray();
    buildLcpArray();
    printSALCP();
	return 0;
}
