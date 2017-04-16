#include<bits/stdc++.h>

using namespace std;

struct data{
    int counter;
    char letter;

    void operator=(data b)
    {
        counter=b.counter;
        letter=b.letter;
    }

    bool operator<(data b){
        return counter<b.counter;
    }
    bool operator>(data b){
        return counter>b.counter;
    }
    data operator+(data b)
    {
        data a;
        a.counter=counter+b.counter;
        a.letter=(letter+b.letter)%26+'A';
        return a;
    }
    data operator-(data b)
    {
        data a;
        a.counter=counter-b.counter;
        a.letter=abs(letter-b.letter)%26+'A';
        return a;
    }
    data operator++()
    {
        data b;
        b.counter=++counter;
        b.letter=++letter;
        return b;
    }
    data operator++(int)
    {
        data b;
        b.counter=counter++;
        b.letter=letter++;
        return b;
    }

};

int main()
{
    data a,b;
    a.counter=25;
    b.counter=12;
    a.letter='A';
    b.letter='B';
    printf("First a: %d %c    && b: %d %c\n\n",a.counter,a.letter,b.counter,b.letter);
    printf("a: %d %c\n",a.counter,a.letter);
    b++;
    printf("after a=b++ a: %d %c\n",a.counter,a.letter);
    printf("b: %d %c\n\n\n",b.counter,b.letter);

    ++b;
    printf("after a=++b a: %d %c\n",a.counter,a.letter);
    printf("b: %d %c\n",b.counter,b.letter);
    return 0;
}
