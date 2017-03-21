#include<iostream>
using namespace std;
struct data {

char name[20];
    int number, email_num;

};
struct worklist{

    string work_description;

};

struct day {

    data new_people[100];
    int total_new_people;
    worklist todo;

void charm_your_miss(){
    do_math();
    smile();
}

void do_math(){
    int a,b;
    cin>>a>>b;
    cout<<a+b<<endl;
}

void smile()
{
    cout<<" :) \n";
}
};



int main()
{
    day ara;
    ara.todo.work_description="Onek code korbo";

    cout <<  ara.todo.work_description << endl;
    return 0;
}
