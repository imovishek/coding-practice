/*input
6
1 1 2 1 90 2
*/

/*input

*/

#include <bits/stdc++.h>
using namespace std;

#define mx 100005
#define ll long long
#define MOD 1000000007

void counting_sort(int *a, int *b, int pos)
{
	int n = b - a;
	int mult = round(pow(10, pos));
	int cnt[10] = {0};
	for(int i = 1; i<10; i++) cnt[i] = 0;
	for(int i = 0; i<n; i++)
	{
		int val = *(a + i);
		cnt[(val/mult) % 10]++;
	}
	for(int i = 1; i<10; i++) cnt[i] += cnt[i-1];

	int temp[n];
	for(int i = n-1; i>=0; i--)
	{
		int val = *(a+i);
		temp[cnt[(val/mult) % 10]-1] = val;
		cnt[(val/mult) % 10]--;
	}
	for(int i = 0; i<n; i++)
		a[i] = temp[i];
}


void radsort(int *a, int *b)
{
	int n = b - a;
	int maxi = INT_MIN;
	for(int i = 0; i<n; i++)
		maxi = max(maxi, *(a + i));
	int pos = 0;
	while(maxi){
		counting_sort(a, b, pos++);
		maxi /= 10;
	}
}


int main()
{
	int n;
	scanf("%d", &n);
	int ara[n];
	for(int i = 0; i<n; i++)
		scanf("%d", &ara[i]);
	radsort(ara, ara+n);
	for(int i = 0; i<n; i++)
		printf("%d ", ara[i]);
	return 0;
}
