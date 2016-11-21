#include<bits/stdc++.h>
#define M 5000004
using namespace std;
bool marked[M];
void sieve(int n);
bool is_prime(int n);

vector <int> primes;

int main()
{

    int n;
    primes.push_back(2);
    sieve(M-3);

//    while(scanf("%d",&n)!=EOF)
//    {
//        if(is_prime(n))printf("prime\n");
//        else printf("not prime\n");
//    }
    return 0;
}


void sieve(int n)
{
    int i;
    for( i=3;i*i<=n;i+=2)
    {
        if(marked[i]==false){
                primes.push_back(i);
        for(int j=i*i;j<=n;j+=i+i)
            marked[j]=true;
        }
    }
    for(;i<=n;i+=2)
    {
        if(!marked[i])primes.push_back(i);
    }
}

bool is_prime(int n)
{
    if(n<2)return 0;
    else if(n==2)return 1;
    else if(n%2==0)return 0;
    else return !marked[n];
}
