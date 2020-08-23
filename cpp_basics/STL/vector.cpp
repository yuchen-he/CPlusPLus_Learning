#include <vector>
#include <iostream>
#include <string>

using namespace std;

int main(){
    vector<int> v1;    //vector是一个template类，所以与/template/template_class.cpp一样使用
    vector<string> v2;
    for (int i=0; i<3; i++){
        v1.push_back(i*2);
        string j = to_string(i*3);   //to_string在std库中，用于强制类型转换
        v2.push_back(j);
    }

    cout << "v1_orig: " << endl;
    for (int k=0; k<v1.size(); k++){    //.size()用于取得vector的长度，因为它是动态size的
        cout << v1[k] << endl;
    }
    cout << "v2_orig: " << endl;
    for (int k=0; k<v1.size(); k++){
        cout << v2[k] << endl;
    }

    cout << "v1_capacity: " << v1.capacity() << endl;
    return 0;
}