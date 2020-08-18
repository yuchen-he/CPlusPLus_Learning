#ifndef _CHICKEN_H_
#define _CHICKEN_H_  
 
#include "bird.h"
 
//  ニワトリクラス
class CChicken : public CBird{
public:
    // 虚函数的override
    void sing(){ cout << "コケコッコー" << endl; }
    void fly(){ cout << "にわとりは飛べません" << endl; }
};
 
#endif // _CHICKEN_H_