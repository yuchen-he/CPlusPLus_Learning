#include <iostream>
#include <string>
#include "calc.h"

using namespace std;

int main(){
    CCalc<int> i1;   //实例化class的时候，指定template的具体类型
    CCalc<string> i2;
    i1.set(1, 2);
    i2.set("ABC", "DEF");
    cout << i1.add() << endl << i2.add() << endl;
    return 0;
}
