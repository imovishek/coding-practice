#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#define pf printf
#define sf scanf
#define pcase(x) printf("Case %d: ",x)
using namespace std;
typedef long long int lint;
typedef double dbl;
typedef pair<int, int> pii;
#define x first
#define y second

pii extendedEuclid(int a, int b) { // returns x, y | ax + by = gcd(a,b)
  if(b == 0) return pii(1, 0);
  else {
    pii d = extendedEuclid(b, a % b);
    return pii(d.y, d.x - d.y * (a / b));
  }
}
int main()
{
    pii p=extendedEuclid(6,5);
    printf("%d %d\n",p.x,p.y);
    return 0;
}
