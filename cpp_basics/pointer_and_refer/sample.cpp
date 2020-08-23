#include <iostream>

using namespace std;

/* 1. 
* 引用不能为空，所以在使用时不需要测试其合法性。
* 指针可以为空，所以在使用时最好先测试其是否为空指针，否则可能引起程序崩溃
*/
void test_p(int* p)
{
  	if(p != nullptr)    //对p所指对象赋值时需先判断p是否为空指针
    	*p = 3;
    return;
}
void test_r(int& r)
{
    r = 3;    //由于引用不能为空，所以此处无需判断r的有效性就可以对r直接赋值
    return;
}

int main(){
    /* 2.
    * 引用必须进行初始化
    * 而指针可以不用
    */
    // int &ref1;   //非法
    int *pt1;       //合法


    // 3.
    // 指针可以随时改变指向，但是引用只能指向初始化时指向的对象，无法改变。
    int a = 10;
    int b = 20;

    int &ref2 = a;
    cout << "ref2 before: " << ref2 << ", " << &ref2 << endl;
    ref2 = b;                              //ref2依然会指向a，但是a的值被改成了b的值。
                                           //这也是为什么函数形参一般加const -> 变成只读参数，从而不改变指向的原值
                                           //这样既可以避免参数拷贝占用内存，还可以获得与传值参数一样的调用方式。
    cout << "ref2 after: " << ref2 << ", " << &ref2 << endl;

    int *pt2 = &a;
    cout << "pt2 before: " << pt2 << endl;
    pt2 = &b;                              //可以让pt2转为指向b的地址
    cout << "pt2 after: " << pt2 << endl;

    return 0;
}