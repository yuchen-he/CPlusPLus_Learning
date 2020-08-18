#include <list>
#include <iostream>
#include <string>

using namespace std;

// list相当于python的list (vector相当于功能残缺版的list)

int main(){
    list<int> li;
    li.push_back(1);
    li.push_back(2);
    li.push_front(3);
    list<int>::iterator itr;   //list不能用index来取里面的值，需要用iterator(类似于一个指针)
                               //重要区别：vector也同样可以用iterator,但list只能用iterator

    //  データの挿入
    itr = li.begin();   //  イテレータを先頭に設定
    itr++;              //  一つ移動
    li.insert(itr,4);   //  値の挿入

    //  データの表示
    for (itr = li.begin(); itr != li.end(); itr++){   //list.begin()和end()都是返回指针，因此可以复制给itr
        cout << *itr << " ";     //输出指向位置的值时，用*
    }
    cout << endl;

    // remove (只有list才有这个函数)
    list<int>::iterator i2;
    i2 = li.begin();
    li.remove(*i2);   //用remove时，参数需要给到pointer的对应数值，所以用*
    for (i2 = li.begin(); i2 != li.end(); i2++){
        cout << *i2 << " ";
    }
    cout << endl;
    return 0;
}