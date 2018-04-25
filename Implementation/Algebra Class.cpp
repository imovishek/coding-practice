#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define mx 100005

struct data{
    int a, b, k, c; // c.a^xb^yk^z
    data(){a = b = c = k = 0;}
    data(int _a, int _b, int _c, int _k){
        a = _a;
        b = _b;
        c = _c;
        k = _k;
    }
    bool operator<(const data &p)const{
        return make_pair(make_pair(a, b), make_pair(k, c)) < make_pair(make_pair(p.a, p.b), make_pair(p.k, p.c));
    }
    bool operator==(const data &p) const{
       return make_pair(make_pair(a, b), make_pair(k, 0)) == make_pair(make_pair(p.a, p.b), make_pair(p.k, 0));
    }
    data operator+(const data &p) const{
        assert(*this == p);
        return data(a, b, c+p.c, k);
    }
    data operator*(const data &p) const{
        return data(a+p.a, b+p.b, c*p.c, k + p.k);
    }
    void print(){
        printf("%d.a^%d.b^%d,k^%d", c, a, b, k);
    }
};

struct Algebra{
    vector<data> vt;
    int size(){
        return vt.size();
    }
    data operator[](const int a) const{
        return vt[a];
    }
    Algebra operator+(Algebra a)const {
        Algebra ret;
        bool mark[vt.size()+1];
        memset(mark, 0, sizeof mark);
        for(int i = 0; i<a.size(); i++)
        {
            int j;
            for(j = 0; j<vt.size(); j++)
            {
//                cout << "hi" << endl;
                if(a[i]==vt[j]){
                    ret.vt.push_back(a[i]+vt[j]);
                    mark[j] = 1;
                    break;
                }
            }
            if(j == vt.size()){
                ret.vt.push_back(a[i]);
            }
        }
        for(int i = 0; i<vt.size(); i++)
            if(!mark[i])
                ret.vt.push_back(vt[i]);
        //sort(ret.vt.begin(), ret.vt.end());
        return ret;
    }
    Algebra operator*(Algebra a)const {
        Algebra ret;
        for(int i = 0; i<a.size(); i++)
        {
            for(int j = 0; j<vt.size(); j++)
            {
                data tmp = a[i] * vt[j];
                Algebra temp;
                temp.vt.push_back(tmp);
                ret = ret + temp;
            }
        }
        return ret;
    }

    void print(){
        for(int i = 0; i<vt.size(); i++)
        {
            vt[i].print();
            if(i==vt.size()-1) printf("\n");
            else printf(" + ");
        }
    }
};

int main()
{
    int n, k, a, b;
    scanf("%d", &n);
    Algebra dp[n+1], A, B;
    A.vt.push_back(data(1, 0, 1, 0));
    B.vt.push_back(data(0, 1, 1, 0));
    dp[1].vt.push_back(data(0,0,1,1));
//    printf("1 %d\n", k);
    for(int i = 2; i<=n; i++)
    {
//        cout << A.size() << " " << dp[i-1].size() << endl;
        dp[i] = A * dp[i-1];
//        dp[i].print();
//        return 0;
        for(int j = 1; j<i; j++)
            dp[i] = dp[i] + B * dp[j] * dp[i-j];
        dp[i].print();
    }
//    printf("%d\n", dp[n]);
    return 0;
}

