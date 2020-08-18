#ifndef _CROW_H_
#define _CROW_H_
 
#include "bird.h"
 
//  カラスクラス
class CCrow : public CBird{
public:
    // 虚函数的override
    void sing(){ cout << "カーカー" << endl; }
    void fly(){ cout << "カラスが飛びます" << endl; }
};
 
#endif // _CROW_H_