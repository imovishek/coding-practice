/*input
2
15 12 9 10
12 6 5 5
*/

#include <bits/stdc++.h>
using namespace std;

#define mx 100005
#define ll long long
#define MOD 1000000007

int main()
{
	int t, tst = 1;
	scanf("%d", &t);
	while(t--)
	{
		double ab, bc, cd, ad;
		scanf("%lf %lf %lf %lf", &ab, &cd, &ad, &bc);
		double base = ab - cd;
		double angle1 = acos((ad*ad + base*base - bc*bc)/(2.0*ad*base));
		double angle2 = acos((bc*bc + base*base - ad*ad)/(2.0*bc*base));
		double l = 0.0, r = ad * sin(angle1);
		double area = 0.5 * (ab + cd) * (ad * sin(angle1));
		int cnt = 100;
		while(cnt--)
		{
			double mid = (l + r) / 2.0;
			double ef = ab - mid / tan(angle1) - mid / tan(angle2);
			double lowerArea = 0.5 * (ab + ef) * mid;
			if(lowerArea * 2.0 < area)
				l = mid;
			else r = mid;
		}
		double ae = l / sin(angle1), fb = l / (sin(angle2));
		printf("Land #%d: %.10lf %.10lf\n",tst++, ae, fb);
	}
	return 0;
}
