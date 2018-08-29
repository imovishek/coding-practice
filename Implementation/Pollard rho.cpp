#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll PollardRho(ll n)
{
    srand (time(NULL));
    if (n==1) return n;
    if (n % 2 == 0) return 2;
    ll x = (rand()%(n-2))+2;
    ll y = x;
    ll c = (rand()%(n-1))+1;
    ll d = 1;

    while(d==1)
    {
        x = (x*x%n + c)%n;
        y = (y*y%n + c)%n;
        y = (y*y%n + c)%n;
        d = __gcd(abs(x-y), n);
        if(d==n) return PollardRho(n);
    }
    return d;
}

int main()
{
    int n;
    while(cin >> n)
    cout << PollardRho(n) << endl;
    return 0;
}
