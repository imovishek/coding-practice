/*
	ID: ovishek1
	LANG: C++11
	TASK: combo
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("combo.in", "r", stdin);
    freopen("combo.out", "w", stdout);
	int n;
	cin >> n;
	int a, b, c;
	cin >> a >> b >> c;
	set< pair<int, pair<int, int> > > st;
	a--,b--,c--;
	for(int i = (a-2+n)%n, c1 = 0; c1<5; c1++, i = (i+1)%n)
		for(int j = (b-2+n)%n, c2 = 0; c2<5; c2++, j = (j+1)%n)
			for(int k = (c-2+n)%n, c3 = 0; c3<5; c3++, k = (k+1)%n)
				st.insert(make_pair(i, make_pair(j, k)));



	// for(int i = (a-2+n) % n + (a<2), c1 = 0; i!=(a+3)%n+1 && c1<5; i = (i+1)%n+1, c1++)
	// 	for(int  j= (b-2+n) % n + (b<2), c2 = 0; j!=(b+3)%n+1 && c2<5 ;j = (j+1)%n+1, c2++)
	// 		for(int k = (c-2+n) % n + (c<2), c3 = 0; k!=(c+3)%n+1 && c3<5; k= (k+1)%n+1, c3++){
	// 			st.insert(make_pair(i, make_pair(j, k)));
	// 			cout << i << " z" << j << " " << k << endl;
	// 		}
	// cout << st.size() << "*\n";
	cin >> a >> b >> c;
	a--,b--,c--;
	// for(int i = (a-2+n) % n + (a<2), c1 = 0; i!=(a+3)%n+1 && c1<5; i = (i+1)%n+1, c1++)
	// 	for(int  j= (b-2+n) % n + (b<2), c2 = 0; j!=(b+3)%n+1 && c2<5 ;j = (j+1)%n+1, c2++)
	// 		for(int k = (c-2+n) % n + (c<2), c3 = 0; k!=(c+3)%n+1 && c3<5; k= (k+1)%n+1, c3++){
	// 			st.insert(make_pair(i, make_pair(j, k)));
	// 			cout << i << " " << j << " " << k << endl;
	// 		}
	for(int i = (a-2+n)%n, c1 = 0; c1<5; c1++, i = (i+1)%n)
		for(int j = (b-2+n)%n, c2 = 0; c2<5; c2++, j = (j+1)%n)
			for(int k = (c-2+n)%n, c3 = 0; c3<5; c3++, k = (k+1)%n)
				st.insert(make_pair(i, make_pair(j, k)));


	cout << st.size() << endl;
	return 0;
}