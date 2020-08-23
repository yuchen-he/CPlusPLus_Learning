#include <iostream>
#include<iomanip>
using namespace std;

int main(){
    enum weekday {MON, TUS, WED=10, THU, FRI, SAT, SUN};
    weekday w1;
    w1 = THU;           //THU对应的整数值为WED+1
    cout << w1 << endl;

    int i = FRI;        //FRI这个枚举常量是有意义的，它对应的数值为12，因此可以赋值给i
    cout << i << endl;

    if (i==w1) cout << "Equal" << endl;
    else {cout << "Not Equal" << endl;}
    return 0;
}