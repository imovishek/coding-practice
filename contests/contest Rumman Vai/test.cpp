#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

int main()
{
    map<string,int> mp;
    mp["12"]=1;
    mp["125"]=1;
    mp["126"]=1;

        cout<<distance(mp.begin(),mp.find("126"))<<endl;
    return 0;
}
