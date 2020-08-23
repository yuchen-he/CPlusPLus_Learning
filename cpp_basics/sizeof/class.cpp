/*
Size of char : 1
Size of int : 4
Size of short int : 2
Size of long int : 4
Size of float : 4
Size of double : 8
Size of wchar_t : 4
*/

#include<iostream>
using namespace std;

class A{};
class B{
    public:
        char b;   //由于字节对齐原则（与虚指针vptr），占8个字节
        virtual void func_1(){};  //占8个字节
        virtual void func_2(){};
        virtual void func_3(){};
        static int c;    //静态数据成员不占用类对象的存储空间
        static int d;
        static int e;
        void func_4(){};   // 成员函数（包括静态与非静态）不占用类对象的存储空间
};

int main(){
    cout<<sizeof(A)<<endl;    //空类的大小为1字节
    cout<<sizeof(B)<<endl;    //对于包含虚函数的类，不管有多少个虚函数，只有一个虚指针,vptr的大小=8字节。
    return 0;
}