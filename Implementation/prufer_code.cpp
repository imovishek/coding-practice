#include <bits/stdc++.h>
#define mx 100005
using namespace std;
vector<int> edge[mx];
int deg[mx];
vector<int> prufer_encode(int n){
    vector<int> code;
    for(int i = 1; i<=n; i++)
        deg[i] = edge[i].size();
    int leaf = 1;
    while(deg[leaf] != 1) leaf++;
    int ptr = leaf;
    for(int i = 0; i<n-2; i++){
        int p = 0;
        for(int v : edge[leaf])
            if(deg[v] != 1)
                p = v;
        
        if(--deg[p] == 1 && p < ptr)
            leaf = p;
        else {
            ptr++;
             while(deg[ptr] != 1) ptr++;
             leaf = ptr;
        }
        code.push_back(p);
    }
    return code;
}

vector<pair<int, int> > prufer_decode(vector<int> code){
    int n = code.size() + 2;
    vector<pair<int, int> > tree;
    for(int i = 1; i<=n; i++){
        deg[i] = 1;
    }
    for(int x : code) deg[x]++;
    int ptr = 1;
    while(deg[ptr] != 1) ptr++;
    int leaf = ptr;
    for(int i = 0; i<n-2; i++){
        int p = code[i];
        tree.push_back({leaf, p});
        if(--deg[p] == 1 && p < ptr) leaf = p;
        else{
            ptr ++;
            while(deg[ptr] != 1) ptr++;
            leaf = ptr;
        }
    }
    tree.push_back({leaf, n});
    return tree;
}

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i<n; i++){
        int u, v;
        scanf("%d %d", &u, &v);
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    cout << "Encode:\n";
    auto code = prufer_encode(n);
    for(int x : code){
        cout << x << " ";
    }
    cout << endl;

    cout << "Decode:\n";

    auto tree = prufer_decode(code);
    for(auto p : tree) cout << p.first << " " << p.second << endl;
    return 0;
}


