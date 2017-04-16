#include<stdio.h>
#include<vector>
using namespace std;
char ara[]="ABCDEFGHIJ";
vector <char> res;
int taken[10]={0};
void call()
{
    if(res.size()==4)
        {
            printf("%c%c%c%c\n",res[0],res[1],res[2],res[3]);
            return;
        }
    int i;
    for(i=0;i<10;i++)
    {

        if(taken[i]==0)
        {
            if(!res.empty() && res.back()>ara[i]){continue;}
            res.push_back(ara[i]);
            taken[i]=1;
//            printf("%c %d\n",ara[i],taken[i]);
            call();

            taken[i]=0;
//            printf("%c %d\n",ara[i],taken[i]);
            res.pop_back();
        }

    }
}

int main()
{
    call();

    return 0;
}
