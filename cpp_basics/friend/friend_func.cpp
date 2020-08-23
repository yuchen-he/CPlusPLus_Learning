/*
友元函数可以访问一个类的私有或保护成员
友元函数只是一个普通函数，并不是该类的类成员函数，它可以在任何地方调用，友元函数中通过对象名来访问该类的私有或保护成员
*/
#include <iostream>

using namespace std;

class A
{
public:
    A(int _a):a(_a){};
    friend int geta(A &ca);  // 友元函数
private:
    int a;
};

int geta(A &ca)              // 定义（与类A无关）
{
    return ca.a;
}

int main()
{
    A a(3);    
    cout<<geta(a)<<endl;     //可以访问类A的对象a中的私有成员变量

    return 0;
}