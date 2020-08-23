
/*
友元类的声明在该类的声明中，而实现在该类外
*/
#include <iostream>

using namespace std;

class A
{
public:
    A(int _a):a(_a){};
    
    //类B是类A的友元，那么类B里面的成员可以直接访问A的私有成员。
    friend class B;      //声明在类A中，实现在类A外
private:
    int a;
};

class B
{
public:
    int getb(A ca) {
        return  ca.a; 
    };
};

int main() 
{
    A a(3);
    B b;
    cout<<b.getb(a)<<endl;
    return 0;
}