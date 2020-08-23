#ifndef _BIRD_H_
#define _BIRD_H_
 
#include <iostream>
#include <string>
 
using namespace std;
 
class CBird{
public:
    // 虚函数的virtual关键字只需要在父类中定义时加上，在子类以及bird.cpp实现时都不用
    virtual void sing(){ cout << "鳥が鳴きます" << endl; }
    // 纯虚函数。父类中无具体内容，在子类中实现具体功能。
    // virtual void sing()=0;
    
    void fly(){ cout << "鳥が飛びます" << endl; }
};
 
#endif // _BIRD_H_