#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>

using namespace std;

//1. 结构体自引用 -> 多用于创建链表，树等高级结构
struct Books{
    int id;
    struct Books *next;     //不能用"struct Books next",这样成员next会无限包含下一个完整的结构体，导致内存溢出
};

//2. 使用typedef定义的结构体自引用
//   作用：可以定义别名
typedef struct Books1{
    Books1 *next;           //用typedef时，不需要加上struct了
    int id;
}books1, *books1Ptr;        //Books1的别名
            /*
            books1Ptr是一个指针基类型，可以用他来实例化不同指针（指向的类型为结构体Books1）
            */

int main(){
    // 1.
    Books book2;
    Books book3;
    book2.id = 2;
    book3.id = 3;
    book2.next = &book3;
    book3.next = NULL;      //NULL用在比如链表的末尾
    cout << "Book2 id is: " << book2.id << endl;
    cout << "Book2 ptr is: " << book2.next << endl;
    cout << "Book3 adr is: " << &book3 << endl;
    cout << "Book2 next id is: " << book2.next->id << endl;
    cout << "Book2 next ptr is: " << book2.next->next << endl;

    // 2.
    books1Ptr s1;  //用这个别名指针基类型来实例化对象。s1是个指针
    books1Ptr s2;
    /*
    从原理上，结构体指针（即s1, s2，s1->next, s2->next）若不手动分分配内存，是不能用的
    如果只去赋值s1->id, s2->id, 程序无法运行 (e.g. s1->id = 1;s2->id = 2;)
    正确做法是给所有结构体指针都分配好内存（不一定要具体赋值指向的位置）
    如下：
    */
    s1 = (books1*) malloc(sizeof(books1));  //malloc函数输入内存空间的大小，返回指针(指向该内存空间首地址)
                                            //用法：malloc(sizeof([int,float...]))
    s2 = (books1Ptr)malloc(sizeof(books1)); //效果与上面一样
    s1->next = (books1Ptr)malloc(sizeof(books1));  //结构体成员指针也同样需要分配内存
    s2->next = (books1Ptr)malloc(sizeof(books1));
    s1->id = 1;
    s2->id = 2;
    cout << "sizeof(books1) is: " << sizeof(books1) << endl;
    cout << "s1 id is: " << s1->id << endl;
    cout << "s2 next is: " << s2->next << endl;

    //如果直接使用结构体(即对成员进行赋值)的话，若成员中有结构体指针，也需要分配内存
    books1Ptr s3;
    s3->next = (books1Ptr)malloc(sizeof(books1));
    s3->id = 3;
    cout << "s3 id is: " << s3->id << endl;
    cout << "s3 next is: " << s3->next << endl;

    return 0;
}