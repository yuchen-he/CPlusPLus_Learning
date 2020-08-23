#include <iostream>
#define isNs1 1
// #define isGlobal 2

using namespace std;
void func(){
    cout << "::func" << endl;
}

namespace ns1{
    void func(){
        cout << "ns1::func" << endl;
    }
}

namespace ns2{
#ifdef isNs1
    using ns1::func;   //这种情况下，ns2会包含ns1里面的func函数，从而在main中调用ns2::func()时会调用ns1的func
#elif isGlobal
    using ::func;         //注意这种写法。::func代表是全局的func函数
#else
    void func(){
        cout << "other::func" << endl;
    }
#endif
}

int main(){
    ns2::func(); // 会根据当前环境定义宏的不同来调用不同命名空间下的func()函数
    return 0;
}
