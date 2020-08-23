#include <map>
#include <iostream>
#include <string>

using namespace std;

// map相当于python的dict

int main() {
    map <string, int> score;  // map のデータ構造を用意する。<>里面需要两个类型，一个key，一个value
    string names[] = { "Tom","Bob","Mike" };  //创造一个元素类型的string的数组（与vector不同，数组是提前指定好长度的）
    score[names[0]] = 100;          //  这里的赋值与python类似
    score[names[1]] = 80;
    score[names[2]] = 120;
    int i;
    for(i = 0; i < 3; i++){
        cout << names[i] << ":" << score[names[i]]  << endl;
    }

    map <string, int>::iterator iter;   //先定义一个迭代器，注意这里<>后面::iterator为map的子类
    iter = score.find("Tom");           //.find()函数返回的是一个迭代器
    if (iter != score.end()){
        cout << "Find! The value is: " << iter->second << endl;  //iter->second表示此时iter指向位置的下一个位置的value
    }
    else{
        cout << "Not find!" << endl;
    }
    
    return 0;
}