#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
using namespace std;
bool is_prime(int n)
{
    int sq=sqrt(n);
    if(n==2)return true;
    if(n&1){
        for(int i=3;i<=sq;i+=2)
            if(n%i==0)return false;
        return true;
    }
    return false;


}
int main()
{
    int i;
    for(i=3;i<100;i+=2)
    {
        if(is_prime(i))printf("%d, ",i);
    }
    return 0;
}
