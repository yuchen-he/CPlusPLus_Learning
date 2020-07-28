// 内联的作用：以代码膨胀(复制)为代价，仅仅省去了函数调用的开销，从而提高函数的执行效率。
// -> 如果执行函数体内代码的时间相比于函数调用的开销较大，那么效率的收货会更少！
// -> 另一方面，每一处内联函数的调用都要复制代码，将使程序的总代码量增大，消耗更多的内存空间。
// 因此，如果函数体内出现循环，那么执行函数体内代码的时间要比函数调用的开销大。不应用内联

// 内联的编程方式：inline是一种“用于实现的关键字,而不是用于声明的关键字”
// -> 因此，不是在.h文件中定义，而是在实现文件.cpp中

/** 编译器对 inline 函数的处理步骤
 * 将 inline 函数体复制到 inline 函数调用点处；
 * 为所用 inline 函数中的局部变量分配内存空间；
 * 将 inline 函数的的输入参数和返回值映射到调用方法的局部变量空间中；
 * 如果 inline 函数有多个返回点，将其转变为 inline 函数代码块末尾的分支（使用 GOTO）。
 */

#include <iostream>  
using namespace std;
class Base
{
public:
    inline virtual void who()
    {
        cout << "I am Base\n";
    }
    virtual ~Base() {}
};
class Derived : public Base
{
public:
    inline void who()  // 不写inline时隐式内联
    {
        cout << "I am Derived\n";
    }
};

int main()
{
    // 此处的虚函数 who()，是通过类（Base）的具体对象（b）来调用的，编译期间就能确定了，所以它可以是内联的，但最终是否内联取决于编译器。 
    Base b;
    b.who();

    // 此处的虚函数是通过指针调用的，呈现多态性，需要在运行时期间才能确定，所以不能为内联。  
    Base *ptr = new Derived();
    ptr->who();

    // 因为Base有虚析构函数（virtual ~Base() {}），所以 delete 时，会先调用派生类（Derived）析构函数，再调用基类（Base）析构函数，防止内存泄漏。
    delete ptr;
    ptr = nullptr;

    system("pause");
    return 0;
} 