#include <iostream>
#include "vector2.h"
 
using namespace std;

//  +演算子のオーバーロード
Vector2 operator+(const Vector2& v1,const Vector2& v2)
{
    Vector2 v;
    // v1.x = 3;          // error. 传入的v1在main中不需要是const，但传进来之后就不能变了
    v.x = v1.x + v2.x;
    v.y = v1.y + v2.y;
    return v;
}
//  -演算子のオーバーロード
Vector2 operator-(const Vector2& v1,const Vector2& v2)
{
    Vector2 v;
    v.x = v1.x - v2.x;
    v.y = v1.y - v2.y;
    return v;
}
//  スカラー倍
Vector2 operator*(const double d, const Vector2& v)
{
    Vector2 r;
    r.x = d * v.x;
    r.y = d * v.y;
    return r;
}
//  =演算子のオーバーロード
Vector2& Vector2::operator=(const Vector2& v)
{
    x = v.x;
    y = v.y; 
    return *this;                     // this是指向该实例v的指针，*this则为它的引用
}
//  +=演算子のオーバーロード
Vector2& Vector2::operator+=(const Vector2& v)
{
    x += v.x;
    y += v.y;
    return *this;
}
//  -=演算子のオーバーロード
Vector2& Vector2::operator-=(const Vector2& v)
{
    x -= v.x;
    y -= v.y;
    return *this;
}

void vec(string vecname, Vector2& v){
    cout << vecname << "(" << v.x << "," << v.y << ")" << endl;
}
 
int main(){
    Vector2 v1,v2,v3;
    //  ベクトルに値を代入
    v1.x = 1.0;
    v1.y = 2.0;
    v2 = v1;            //  値を代入
    v3 = 4.0 * v1;      //  ベクトルのスカラー倍
    vec("v1=", v1);
    vec("v2=", v2);
    // vec("v1 + v2=", v1 + v2);
    vec("v3=", v3);
    v3 += v1;           //  代入演算子（+=）
    vec("v3=",v3);
    v1 -= v2;           //  代入演算子（-=）
    vec("v1=", v1);
    return 0;
}