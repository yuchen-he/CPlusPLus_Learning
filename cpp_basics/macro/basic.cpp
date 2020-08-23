#include <iostream>
#define exp(s) printf("test s is: %s\n",s)
#define exp1(s) printf("test s is: %s\n",#s)
#define exp2(s) #s 

#define expA(s) printf("前缀加上后的字符串为:%s\n",gc_##s)  //gc_s必须存在，否则报错
// 连接后的实际参数名，必须为实际存在的参数名或是编译器已知的宏定义。
#define expB(s) printf("前缀加上后的字符串为:%s\n",gc_  ##  s)  //gc_s必须存在，否则报错
// 当用##连接形参时，##前后的空格可有可无。
#define gc_hello1 "I am gc_hello1"

using namespace std;
int main() {
    exp("hello");
    exp1(hello);  //exp1中的#s会把hello字符串化

    string str = exp2(   bac );
    cout<<str<<" "<<str.size()<<endl;
    /**
     * 忽略传入参数名前面和后面的空格。
     */
    string str1 = exp2( asda  bac );
    /**
     * 当传入参数名之间存在空格时，编译器将会自动连接各个子字符串，
     * 用每个子字符串之间以一个空格连接，忽略剩余空格。
     */
    cout<<str1<<" "<<str1.size()<<endl;

    const char * gc_hello = "I am gc_hello";   //传进去之后变成了gc_hello，从而变为printf(gc_hello)
    expA(hello);
    expB(hello1);      //传进去之后变成了gc_hello1，而宏定义了gc_hello1 = "I am gc_hello1"
    return 0;
}