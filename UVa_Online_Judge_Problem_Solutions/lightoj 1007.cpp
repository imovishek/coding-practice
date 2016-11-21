#include<cstdio>
#include<cmath>
#include<iostream>
#include<vector>
#define M 5000004
using namespace std;


bool marked[M];
void sieve(int n);
bool is_prime(int n);

vector <int> primes;

int phi[M];

void calculatePhi() {
  for (int i = 1; i < M; i++) {
    phi[i] = i;
  }
  for (int p = 2; p < M; p++) {
    if (phi[p] == p) { // p is a prime
      for (int k = p; k < M; k += p) {
        phi[k] -= phi[k] / p;
      }
    }
  }
}



int main()
{

calculatePhi();
    //primes.push_back(2);
    //sieve(M-4);
    int t,a,b,temp,sq,j,k,rang;
    unsigned long long int sum,res;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
    sum=0;
    scanf("%d %d",&a,&b);


    for(j=a;j<=b;j++)
    {
        res=phi[j];

//printf("%lf\n",res);
sum+=(int)res*res;

}
printf("Case %d: %llu\n",i,sum);
}


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



