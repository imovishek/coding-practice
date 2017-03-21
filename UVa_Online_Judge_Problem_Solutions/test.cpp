#include <iostream>

class MyClass
{
private:
    mutable int counter;
public:
    void Foo()
    {
        counter++;
        std::cout << "Foo" << std::endl;
    }

    void Foo() const
    {
        counter++;
        std::cout << "Foo const" << std::endl;
    }

};

int main()
{
    MyClass cc;
    const MyClass& ccc = cc;
    cc.Foo();
    ccc.Foo();
}
