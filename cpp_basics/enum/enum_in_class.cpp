/**
 * 目的：有时我们希望某些常量只在类中有效 -> 建立在整个类中都恒定的常量
 */

/*
首先想到用const
然而，const数据成员只在某个对象生存期内是常量，
而对于整个类而言却是可变的，因为类可以创建多个对象，不同的对象其 const 数据成员的值可以不同。
下面定义declass无法通过编译

class A 
{
  const int SIZE = 100;   // 错误，企图在类声明中初始化 const 数据成员 
  int array[SIZE];  // 错误，未知的 SIZE 
}; 
*/


// 应该用类中的枚举常量来实现
class Person{
public:
    typedef enum {    //里面的枚举常量在Person类中恒定。（与static类似？？）
        BOY = 0,
        GIRL
    }SexType;
};
//访问的时候通过，Person::BOY或者Person::GIRL来进行访问。


