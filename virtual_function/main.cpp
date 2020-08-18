#include <iostream>
#include <string>
#include "bird.h"
#include "chicken.h"
#include "crow.h"
 
using namespace std;
 
int main(){
    CBird* b1, *b2;     //为了运用多态，定义的指针的基类型需要是父类
    b1 = new CCrow();   //父类指针 指向 子类对象 （实现多态的关键）
    b2 = new CChicken();
    b1->sing();         //虽然b1是基类型为父类的指针，但因为它指向对象为子类，所以调用的同名虚函数为子类的。
    b1->fly();
    b2->sing();
    b2->fly();
    return 0;
}