#include <iostream>
#include "sup1.h"
#include "sub2.h"
#include "sub1.h"
#include "sub2.h"
 
using namespace std;
 
int main(){
    /*
    生成子类的实例时：先调用父类的构造函数，再调用子类的构造函数
    */
    CSup1 *s1 = new CSub1();  //用new会生成一个指向该实例的指针
    CSup2 *s2 = new CSub2();

    /*
    消除子类的实例时：
    1. 析构函数不加virtual的情况：只调用父类析构函数（因为s1的基类型是CSup1）
                             -> 子类析构函数里面释放内存的操作将无法启动，造成内存泄漏
    2. 析构函数加virtual的情况：子类析构函数也会被调用（并且是先调用子类析构函数，然后因为子类的释放，从而调用父类析构）
                             -> 因为多态，虽然s2基类型为Csup2，但是它指向的实例为子类型，从而可以调用子类的虚析构函数
    */
    delete s1;
    delete s2;
    return 0;
}