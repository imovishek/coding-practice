#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

int main()
{
int test1 = 100;
int test2 = 200;

vector<stringstream*> ssv;

for(int i=0; i<10; i++)
ssv.push_back(new stringstream);

cout << "test1: " << test1 << endl;
cout << "test2: " << test2 << endl;

for(int i=0; i<10; i++) {
*ssv[i] << "testing " << i << endl;
}

cout << "test1: " << test1 << endl;
cout << "test2: " << test2 << endl;

for(int i=0; i<10; i++) {
cout << ssv[i]->str() << endl;
cout << "test1: " << test1 << endl;
cout << "test2: " << test2 << endl;
}

return 0;
}