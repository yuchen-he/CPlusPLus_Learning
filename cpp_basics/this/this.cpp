//对于Python来说有self，类比到C++中就是this指针
#include <iostream>
#include <cstring>

using namespace std;
class Person{
public:
    typedef enum{  //自定义了一种数据类型：枚举型（可以用它来声明不同变量，就跟int，char这些一样用）
        BOY = 0,
        GIRL       //第一个成员BOY之后的成员的值会一次加1，因此GIRL=BOY+1=1
    }SexType;      //SexType是一个别名（使用typedef可以得到此效果），因此可以用SexType来实例化不同对象

    Person(char *n, int a, SexType s){
        name = new char[strlen(n)+1];
        strcpy(name, n);
        age = a;
        sex = s;
        cout<<"In constructor, sex is: "<<s<<endl;
    }

    int get_age() const{  // get_age函数会被解析成get_age(const A * const this), 相当于python的(self)
        return this->age;
    }

    Person& add_age(int a){  // add_age函数会被解析成add_age(A* const this,int a), 相当于python的(self, a)
        age += a;
        return *this;
    }
    ~Person(){
        delete [] name;
    }

private:
    char * name;
    int age;
    SexType sex;
};

int main(){
    Person p("zhangsan",20,Person::BOY);  // Person::BOY == enum Person::SexType::BOY = 0;
    // cout<<p.sex<<endl; 因为sex是私用成员变量，所以不可直接访问
    cout<<p.get_age()<<endl;
	cout<<p.add_age(10).get_age()<<endl;    //add_age()返回的是类本身，因此可以后面可接.get_age()（用*this来实现）
    return 0;
}