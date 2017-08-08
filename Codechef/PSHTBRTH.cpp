/*input
1
3 6
0110
0000
0000
0001

0000
0000
0000
0000

1000
1000
0000
0000

1 1 1
1 2 2
1 3 3
1 1 3
2 2
0001
0010
0100
1000
1 1 3
*/

#include<bits/stdc++.h>
using namespace std;

int gg[70000];
int tree[100007 * 4];
bool allone(int pos, int i, int j, int k, int l)
{
	for(; i<=j; i++)
	{
		int num = (pos & (((1<<4) - 1 ) << (i * 4)))/(1<<(i*4));
		int seg = ((1<<(l-k+1)) - 1) << k;
		// cout << bitset<4> ((seg & num)/(1<<k)) << endl;
		if((num & seg)!= seg) return false;
	}
	return true;
}

int setzero(int pos, int i, int j, int k, int l)
{
	for(; i<=j; i++)
	{
		int num = (pos & (((1<<4) - 1 ) << (i * 4)))/(1<<(i*4));
		int seg = ((1<<(l-k+1)) - 1) << k;
		pos &= ~(seg << (i*4));
		// cout << bitset<16>(seg) << " *" << endl;
		// cout << bitset<16> (pos) << endl;
	}

	return pos;
}

int fun(int pos)
{
	if(pos==0) return 0;
	int fl[260];
	int &ret = gg[pos];
	if(ret != -1) return ret;
	memset(fl, 0, sizeof fl);
	for(int i = 0; i<4; i++)
		for(int j = i; j<4; j++)
			for(int k = 0; k<4; k++)
				for(int l = k; l<4; l++)
				{
					if(allone(pos, i, j, k, l)){
						fl[fun(setzero(pos, i, j, k, l))] = 1;
					}
				}
	int ans = 0;
	while(fl[ans]==1) ans++;
	return ret = ans;
}
int getnum()
{
	int num = 0, a;
	for(int j = 0; j<4; j++)
		for(int k = 0; k<4; k++){
			scanf("%1d", &a);
			num = num*2 + a;
		}
   	return num;
}

void update(int node, int b, int e, int i, int val)
{
	if(e<i || i<b) return;
	if(b==e && b==i){
		tree[node] = val;
		return;
	}
	int lson = node*2, rson = lson+1, mid = (b+e)/2;
	update(lson, b, mid, i, val);
	update(rson, mid+1, e, i, val);
	tree[node] = tree[lson] ^ tree[rson];
}

int query(int node, int b, int e, int i, int j)
{
	if(e<i || j<b) return 0;
	if(i<=b && e<=j){
		return tree[node];
	}
	int lson = node*2, rson = lson+1, mid = (b+e)/2;
	int x = query(lson, b, mid, i, j);
	int y = query(rson, mid+1, e, i, j);
	return x ^ y;
}

int main()
{
    memset(gg, -1, sizeof gg);
    int t;
    scanf("%d", &t);
    while(t--)
    {
    	int n, m;
    	scanf("%d %d", &n, &m);
    	int ara[n];
    	for(int i = 0; i<n; i++){
    		update(1, 0, n-1, i, fun(getnum()));
    	}
    	for(int i = 0; i<m; i++)
    	{
    		int sig , l, r;
    		scanf("%d %d", &sig, &l);
    		if(sig==2){
    			update(1, 0, n-1, l-1, fun(getnum()));
    		}
    		else{
    			scanf("%d", &r);
    			int ans = query(1, 0, n-1, l-1, r-1);
    			if(ans) printf("Pishty\n");
    			else printf("Lotsy\n");
    		}
    	}
    	
    }
	return 0;
}