// #define NDEBUG          // 在include之前加上这行，则表示忽略断言，即assert不可用
#include <assert.h>     //assert 宏的原型定义在 <assert.h>
#include <stdio.h> 
#include <iostream>

using namespace std;

int main() 
{ 
    int x = 7; 
    x = 9; 

    // 使用方式：void assert(int expression)
    // 如果条件不成立，则程序终止执行
    assert(x==7);    //与python写法一样
    return 0; 
} 