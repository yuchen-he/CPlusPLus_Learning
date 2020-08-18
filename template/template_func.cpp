#include <iostream>
#include <string>

using namespace std;

template <typename T>
T add(T x, T y){
    return x+y;
}

template <typename T, typename S>
void add_1(T x, S y){
    cout << x << "," << y << endl;
}

int main(){
    cout << add<int>(4, 5) << endl;   //利用<>来指定template中的T类型
    cout << add<string>("demon", "stration") << endl;
    // cout << add<string>("love", 4) << endl;   //两个参数类型不一致的话，无法使用

    //使用不同参数类型
    add_1<int, string>(5, "new");
    return 0;
}