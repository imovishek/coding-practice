#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<long long> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];

        for(int i = 0; i < n-1; i++){
            if(a[i+1] > a[i]){
                a[i+1] = a[i];
            }
        }

        long long sum = 0;
        for(int i = 0; i < n; i++) sum += a[i];

        cout << sum << "\n";
    }
    return 0;
}
