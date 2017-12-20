/*
ID: ovishek1
LANG: C++11
PROB: buylow
*/
#include <bits/stdc++.h>
#define ll long long
#define mx 5005
#define prev prv
using namespace std;
struct BigNum{
    string st;
    BigNum(string st) : st(st){
    }
    BigNum(){st = "0";}
    BigNum operator+=(const BigNum &P) {
        string b = P.st;
        reverse(st.begin(), st.end());
        reverse(b.begin(), b.end());
        string res(max(st.length(), b.length()), '0');
//        cout << res << endl;
        int carry = 0;
        for(int i = 0; i<max(st.length(), b.length()); i++)
        {
            int d1 = i >= st.length() ? 0 : st[i] - '0';
            int d2 = i >= b.length() ? 0 : b[i] - '0';
            int sum = d1 + d2 + carry;
            res[i] = sum%10 + '0';
            carry = sum/10;
        }
        if(carry) res += '1';
        reverse(res.begin(), res.end());
        st = res;
        return st;
    }
    void print()
    {
        cout << st << endl;
    }
};
pair<short int, BigNum> dp[mx];
vector<short int> prev[mx];
set<int> st;
int flag[mx];
pair<short int, BigNum> rec(int pos)
{
    if(pos==0) return {1, BigNum("1")};
    auto &ret = dp[pos];
    if(ret.first != -1) return ret;
    ret = {1, BigNum("1")};

    for(int x : prev[pos]){
        auto now = rec(x);
        if(now.first + 1 > ret.first){
            ret.first = now.first + 1;
            ret.second = now.second;
        }
        else if(now.first + 1 == ret.first){
            ret.second += now.second;
        }
    }
    assert(ret.second.st.size() <= 1600);
    return ret;
}
int main()
{
    freopen("buylow.in", "r", stdin);
    freopen("buylow.out", "w", stdout);
    int n;
    scanf("%d", &n);
    for(int i = 0; i<n; i++) dp[i] = {-1, BigNum("0")};
    int ara[n], cnt = 0;
    for(int i = 0; i<n; i++){
        scanf("%d", &ara[i]);
        st.insert(ara[i]);
    }
    map<int, short int> mp;
    for(auto x : st) mp[x] = cnt++;
    for(int i = 0; i<n; i++) ara[i] = mp[ara[i]];
    dp[0] = {1, BigNum("1")};
    memset(flag, 0, sizeof flag);
    for(int i = 1; i<n; i++){
        auto &ret = dp[i] = {1, BigNum("1")};
        for(int j = i-1; j>=0; j--){
            if(flag[ara[j]] != i && ara[j] > ara[i])
            {
                flag[ara[j]] = i;
                auto &now = dp[j];
                if(now.first + 1 > ret.first){
                    ret.first = now.first + 1;
                    ret.second = now.second;
                }
                else if(now.first + 1 == ret.first){
                    ret.second += now.second;
                }
            }
        }
    }
    pair<short int, BigNum> ret = {0, BigNum("0")};
//    for(int i = 0; i<n; i++)
//        cout << ara[i] << " ";
//    cout << endl;
//    cout << rec(1).first << " "  << rec(1).second << endl;
    memset(flag, 0, sizeof flag);
    for(int i = n-1; i>=0; i--)
    {
        if(flag[ara[i]] == 0){
            flag[ara[i]] = 1;
            auto now = dp[i];
//            cout << i << " -> " << now.first << " " << now.second << endl;
            if(now.first > ret.first){
                ret.first = now.first;
                ret.second = now.second;
            }
            else if(now.first == ret.first){
                ret.second += now.second;
            }
        }
    }
    printf("%d ", ret.first);
    ret.second.print();
    return 0;
}

