#include <iostream>
#include <string>

using namespace std;

// 多态

class Animal
{
public:
    string name;
    int age;
    Animal(string n, int a) : name(n), age(a) {}
    virtual void speak() = 0;
};

class Dog : public Animal
{
public:
    Dog(string n, int a) : Animal(n, a) {}
    void speak()
    {
        std::cout << "Woof!" << std::endl;
    }
};


class Cat : public Animal
{
public:
    Cat(string n, int a) : Animal(n, a) {}
    void speak()
    {
        std::cout << "Meow!" << std::endl;
    }
};

class ctest1
{
public:
    ctest1()
    {
        cout << "ctest1 constructor" << endl;
    }
    ~ctest1()
    {
        cout << "ctest1 destructor" << endl;
    }
    int value;
};

class ctest2
{
public:
    ctest2()
    {
        cout << "ctest2 constructor" << endl;
    }
    ~ctest2()
    {
        cout << "ctest2 destructor" << endl;
    }
    ctest1 c1_friend;
};
