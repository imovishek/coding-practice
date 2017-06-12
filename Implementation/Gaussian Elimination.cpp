/*input
2

14
4 42
9 30
16 8
14 77
32 12
37 58
47 26
48 73
62 19
70 89
71 67
80 98
87 24
96 76

0
*/

#include<bits/stdc++.h>
using namespace std;
int n = 100;
double mat[105][105];
void gaussian_elimination()
{
	for(int i = 0; i<n; i++)
    {
    	// cout << i << endl;
    	int id = i;
    	for(int j = i + 1; j<n; j++)
    		if(fabs(mat[j][i]) > fabs(mat[id][i])) id = j;
    	if(id != i)
    		for(int j = i; j<=n; j++)
    			swap(mat[id][j], mat[i][j]);
    	if(mat[i][i]==0.0) continue;
    	for(int j = i + 1; j<=n; j++)
    		mat[i][j] /= mat[i][i];
    	mat[i][i] = 1.0;
    	for(int j = 0; j<n; j++)
    	{
    		if(j!=i){
    			double factor = mat[j][i];
    			for(int k = i + 1; k<=n; k++)
    				mat[j][k] -= factor * mat[i][k];
                mat[j][i] = 0.0;
    		}
    	}

    }
    // for(int i = 0; i<n; i++){
    // 	for(int j = 0; j<=n; j++) {
    // 		cout << mat[i][j] << " ";
    // 	}
    // 	cout << endl;
    // }
}
int to[101];
int main()
{
    int t, tst = 1;
    scanf("%d", &t);
    while(t--)
    {
    	int obj;
    	scanf("%d", &obj);
    	for(int i = 0; i<=100; i++) to[i] = i;
    	for(int i = 1; i<=obj; i++)
    	{
    		int u, v;
    		scanf("%d %d", &u, &v);
    		to[u-1] = v-1;
    	}
    	for(int i = 0; i<=100; i++) for(int j = 0; j<=100; j++) mat[i][j] = 0.0;
    	for(int i = 0; i<94; i++)
    	{
    		mat[i][i] = 6.0;
    		for(int j = 1; j<=6; j++)
    		{
    			if(to[i+j]!=i) mat[i][to[i+j]] += -1;
                else mat[i][i] -= 1.0;
            }
            mat[i][100] = 6.0;
        }
        for(int i = 94; i<100; i++)
        {
            mat[i][i] = 99 - i;
            for(int j = 1; i+j<100; j++){
                if(to[i+j]!=i) mat[i][to[i+j]] += -1;
                else mat[i][i] -= 1.0;
    		}
    		mat[i][100] = 6.0;
    	}
    	// for(int i = 0; i<100; i++)
    	// {
    	// 	for(int j = 0; j<=100; j++)
    	// 		cout << mat[i][j] << " ";
    	// 	cout << endl;
    	// }
    	// cout << " gauss here hss! " << endl;
    	gaussian_elimination();
    	// for(int i = 0; i<100; i++)
    	// {
    	// 	for(int j = 0; j<=100; j++)
    	// 		cout << mat[i][j] << " ";
    	// 	cout << endl;
    	// }
    	printf("Case %d: %.10lf\n", tst++, mat[0][100]);
    }
    
	return 0;
}