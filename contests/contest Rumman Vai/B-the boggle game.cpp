#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>

using namespace std;
bool isvowel(char ch)
{

    return ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U'||ch=='Y';
}
vector<char> res;
vector <string> vt;
string str;
char ara[2][4][5];
int flag[4][4]= {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
map<string,int>mp;
bool is_leg(string a)
{
    int v=0;
    for(int i=0;i<4;i++)
    {
        if(isvowel(a[i]))v++;
    }
    if(v==2)return 1;
    return 0;
}
void letterNext(int a, int b, int k)
{
    if(a<0 || a>3 || b<0 || b>3)return;


    for(int i=-1; i<2; i++)
    {
        for(int j=-1; j<2; j++)
        {
            if(flag[a][b]==0)
            {
                if(i==0 && j==0)continue;
                res.push_back(ara[k][a][b]);
                flag[a][b]=1;
                if(res.size()==4)
                {
                    str+=res[0];
                    str+=res[1];
                    str+=res[2];
                    str+=res[3];
                    if(k==0){mp[str]=1;}
                    else if(mp[str]!=0 && is_leg(str)){vt.push_back(str);mp[str]=0;}
                    str.clear();
                    flag[a][b]=0;
                    res.pop_back();
                    return;
                }
                letterNext(a+i,b+j,k);
                flag[a][b]=0;
                res.pop_back();
            }
        }
    }



}

int main()
{
    char ch,l=0;
    while(1)
    {
        int flagi=0;
        for(int i=0; i<4; i++)
        {
            for(int j=0, k=0; j<8;)
            {
                scanf("%c",&ch);
                if(isalpha(ch))
                {
                    ara[k][i][j%4]=ch;
                    if(j==3)
                    {
                        ara[0][i][4]=0;
                        k=1;
                    }
                    else if(j==7)
                    {
                        ara[1][i][4]=0;
                        k=0;
                    }
                    j++;
                }
                else if(ch=='#')
                {
                    flagi=1;
                    break;
                }
            }
            if(flagi)break;
        }
        if(flagi)break;
        if(l!=0)printf("\n");
        l=1;
        for(int i=0; i<4; i++)
            for(int j=0; j<4; j++)
            {
                letterNext(i,j,0);
            }
        for(int i=0; i<4; i++)
            for(int j=0; j<4; j++)
            {
                letterNext(i,j,1);
            }
        int j=0;
        sort(vt.begin(),vt.end());
        for(j=0;j<vt.size();j++){
            cout<<vt[j]<<endl;
        }
        vt.clear();
        mp.clear();
        if(j==0)printf("There are no common words for this pair of boggle boards.\n");

    }
    return 0;

    /*
Z W A V   G S F U
U N C O   A H F T
Y T G I   G N A L
H G P M   B O O B




D F F B   W A S U
T U G I   B R E T
O K J M   Y A P Q
K M B E   L O Y R
    */
}
