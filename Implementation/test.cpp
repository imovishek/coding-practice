// vector::reserve
#include <cstdio>
#include <vector>
#define forx(x) for(int i=x;i>0;i--)
using namespace std;
int main ()
{
    int n,th,f=1;
    vector<int>vt;
    while(scanf("%d",&n) && n)
    {
        f=1;
        if(n==1){printf("Discarded cards:\nRemaining card: 1\n");continue;}
        forx(n)vt.push_back(i);

        printf("Discarded cards: ");
        while(1)
        {
            th=*(vt.end()-1);
            vt.pop_back();
            if(vt.empty())break;
            if(f) {printf("%d",th);f=0;}
            else  printf(", %d",th);


            th=*(vt.end()-1);
            vt.pop_back();
            if(vt.empty())break;
            vt.insert(vt.begin(),th);

        }
        printf("\nRemaining card: %d\n",th);
    }
    return 0;
}

/*
Discarded cards: 1, 3, 5, 7, 4, 2
Remaining card: 6
Discarded cards: 1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 4, 8, 12, 16, 2, 10, 18, 14
Remaining card: 6
Discarded cards: 1, 3, 5, 7, 9, 2, 6, 10, 8
Remaining card: 4
Discarded cards: 1, 3, 5, 2, 6
Remaining card: 4
*/




