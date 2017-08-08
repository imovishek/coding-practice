/*input

*/

#include<bits/stdc++.h>
using namespace std;


struct CakeParty{
	string makeMove(vector<int> ara)
	{
		int n = ara.size();
		int xorr = 0;
		for(int i = 0; i<n; i++) xorr ^= ara[i];
		int maxi = 0, idx;
		for(int i = 0; i<n; i++)
			if(maxi < ara[i]) {
				maxi = ara[i];
				idx = i;
			}
		int LSB = 0;
		for(int i = 30; i>-1; i--)
			if(xorr & (1 << i)) {LSB = i; break;}
		int a, b = idx;
		if(xorr && (maxi & (1<<LSB))){
			int tm = maxi;
			for(int i = LSB; i>=0; i--)
				if(xorr & (1<<i)) maxi = (maxi ^ (1<<i));
			a = tm - maxi;
		}
		else a = 1, b = 0;
		stringstream ss;
		ss << "CAKE " << b << " PIECES " << a;
		return ss.str();
	}
};
int main()
{
	CakeParty x;
    cout << x.makeMove({3,3,112}) << endl;
	return 0;
}