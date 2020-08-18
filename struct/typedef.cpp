#include <iostream>
#include <string>

using namespace std;

//普通的结构体定义
struct Books{
    string name;
    int id;
}book1;        //没用typedef时，这里的book1是一个具体的实例，可以在main中直接使用的

//使用typedef的定义方式
//作用：可以用别名再去定义不同实例，并且省略原名”Books“
typedef struct{
    string name;
    int id;
}BOOK;         //这里的BOOK是一个别名，即类型名（与Books，int，float等一样）

int main(){
    book1.id = 3;
    book1.name = "CPP";
    cout << "Book1 name is: " << book1.name << endl;

    //用第一种方式时，如果要再定义book2的话，需要在main里再进行实例化
    Books book2;
    book2.id = 4;
    book2.name = "PYTHON";
    cout << "Book2 name is: " << book2.name << endl;

    //使用别名BOOK来定义新变量
    BOOK book3;
    book3.id = 5;
    book3.name = "C Language";
    cout << "Book3 name is: " << book3.name << endl;


    return 0;
}