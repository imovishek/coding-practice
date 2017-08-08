#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <sstream>
using namespace std;
#define inf 1000000007

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    ios :: sync_with_stdio(false);
    int t, tst = 1;
    cin >> t;
    while(t--)
    {
      	int L, T, N;
      	cin >> L >> T >> N;
      	map<int, pair<int, char> > ara;
      	pair<int, int> seq[N];
      	vector<stringstream*> ss;
      	for(int i = 0; i<N; i++) ss.push_back(new stringstream);
      	int left_zero = 0, right_zero = 0;
      	for(int i = 0; i<N; i++)
      	{
      		int val;
      		char ch;
      		cin >> val >> ch ;
      		int now;
      		seq[i] = make_pair(val, i);
      		if(ch=='R') {
      			now = val + T;
      		}
      		else now = val - T;
      		if(now<0) left_zero++;
      		else if(now>L) right_zero++;
      		else {
      			ara[ now ].first++;
      			ara[ now ].second = ch;
      		}
      	}
      	sort(seq, seq+N);
      	int pos = 0;
      	while(left_zero--) *ss[seq[pos++].second] << "Fell off" << endl;
      	for(pair< int, pair<int, char> > a : ara) {
      		if(a.second.first>1){
      			while(a.second.first--)
      				*ss[seq[pos++].second] << a.first << " Turning\n" ; 
      		}
      		else if(a.second.first==1){
      			*ss[seq[pos++].second] << a.first << " " << a.second.second << endl;
      		}
      	}
      	while(right_zero--) *ss[seq[pos++].second] << "Fell off" << endl;
      	cout << "Case #" << tst++ << ":" << endl;
    	for(int i = 0; i<N; i++)
    		cout << ss[i]->str();
    	cout << endl;
    }

    return 0;
}
