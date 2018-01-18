/*
ID: ovishek1
LANG: C++11
PROB: heritage
*/
#include <bits/stdc++.h>
#define prev prevsource
using namespace std;

string in, in_pre;
void rec(string nowpre)
{
//    cout << nowpre << endl;
    int pos = 0;
    char root = nowpre[0];
    for(int i = 0; i<in.size(); i++)
    {
        if(in[i] == root) pos = i;
    }
    string lft, rght;
    for(char ch : nowpre)
    {
        int f = 0;
        for(int i = 0; i<pos; i++)
            if(ch == in[i])
                f = 1;
        if(f) lft += ch;
        else if(ch != root) rght += ch;
    }
    if(lft.size()) rec(lft);
    if(rght.size()) rec(rght);
    printf("%c", root);
}

int main()
{
    freopen("heritage.in", "r", stdin);
    freopen("heritage.out", "w", stdout);
    cin >> in >> in_pre;
    rec(in_pre);
    cout << endl;
    return 0;
}
