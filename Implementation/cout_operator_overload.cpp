#include <bits/stdc++.h>
#include <bits/stdc++.h>

using namespace std;


// print out a container
template<class Os, class K>
Os& operator<<(Os& os, const multiset<K>& v)
{
    os << '[' << v.size() << "] {";
    bool o{};
    for (const auto& e : v)
        os << (o ? ", " : (o = 1, " ")) << e;
    return os << " }\n";
}

template<class Os, class K>
Os& operator<<(Os& os, const vector<K>& v)
{
    os << '[' << v.size() << "] {";
    bool o{};
    for (const auto& e : v)
        os << (o ? ", " : (o = 1, " ")) << e;
    return os << " }\n";
}

int main() {
    // faster i/o
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);   

    vector<int> m{1, 2, 2, 3};


    cout << m << endl;

    return 0;
}