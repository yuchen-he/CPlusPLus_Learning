#ifndef _CALC_H_
#define _CALC_H_

// 一般推荐把template类的具体定义写在.h里面（而非对应的calc.cpp）
template<typename T> class CCalc{  //这句话表示在这个class里面将会使用T这个类型
private:
    T m_n1;
    T m_n2;
public:
    inline void set(const T n1, const T n2) 
    { m_n1 = n1; m_n2 = n2; };  //  设定私有成员变量

    inline T add() const{
        return m_n1 + m_n2;
    }               //  計算結果
};
 
#endif // _CALC_H_