// //加号运算符重载
// #include<iostream>
// using namespace std;
// class Person
// {
// private:
//     /* data */
// public:
//     int m_a;
//     int m_b;
//     Person();
//     Person(int,int);
//     ~Person();
//     //类内成员函数运算符重载 
//     Person operator+(Person &p)
//     {
//         Person temp;
//         temp.m_a = this->m_a + p.m_a;
//         temp.m_b = this->m_b + p.m_b;
//         return temp;
//     }
// };
// //类外构造函数
// Person::Person()
// {

// }

// Person::Person(int a,int b)
// {
//     this->m_a = a;
//     this->m_b = b;
// }
// //类外析构函数
// Person::~Person()
// {}
// //类外全局函数重载
// // Person operator+(Person &p1,Person &p2)
// // {
// //     Person temp;
// //     temp.m_a = p1.m_a+p2.m_a;
// //     temp.m_b = p1.m_b + p2.m_b;
// //     return temp;
// // }
// int main()
// {
//     Person temp;
//     Person a(10,20);
//     Person b(20,30);
//     temp = a+b;
//     cout<<"temp.m_a:  "<<temp.m_a<<endl;
//     system("pause");
//     return 0;
// }

//**左移运算符
//不使用成员函数进行左移运算符重载 因为输出格式是p<<cout
// #include<iostream>

// using namespace std;
// class Person
// {
//     friend ostream & operator<<(ostream &cout,Person p);
// private:
//     /* data */
//     int m_a;
//     int m_b;
// public:
//     Person(/* args */);
//     Person(int, int);
//     ~Person();
    
// };

// Person::Person(/* args */)
// {
// }
// Person::Person(int a,int b)
// {
//     this->m_a = a;
//     this->m_b = b;
// }
// Person::~Person()
// {
// }

// //链式编程 返回cout数据类型ostream
// ostream & operator<<(ostream &cout,Person p)
// {
//     cout<<"m_A="<<p.m_a;
//     return cout;
// }

// int main()
// {
//     Person p(10,20);
//     cout<<p<<"hxj"<<p<<endl;
//     system("pause");
//     return 0;
// }


//递增运算符重载  
// #include<iostream>
// using namespace std;

// class Myinter
// {
// private:
//     /* data */
//     int m_num;
// public:

//     Myinter(/* args */);
//     ~Myinter();
//     //前置递增++
//     Myinter& operator++()
//     {
//         ++m_num;
//         return *this;
//     }
//     //后置递增++ 必须用Int占位
//     Myinter operator++(int)
//     {
//         Myinter temp = *this;
//         m_num++;
//         return temp; //注意，返回的是栈区变量（没有进行操作的） 不能返回引用 使用完就会释放
//     }
// };

// Myinter::Myinter(/* args */)
// {
//     this->m_num=0;
// }

// Myinter::~Myinter()
// {
// }



// int main()
// {
//     Myinter num;
//     ++num;
//     system("pause");
//     return 0;
// }



//赋值运算符重载
// C++编译器至少给一个类添加四个函数：
// 1.默认构造函数
// 2.默认析构函数
// 3.默认构造拷贝函数
// 4.赋值运算符operator=对属性进行值拷贝

// #include<iostream>
// using namespace std;
// class Person
// {
// private:
//     /* data */
// public:
//     Person(/* args */);
//     Person(int);
//     ~Person();
//     int* m_age;
//     Person& operator=(Person &p)
//     {
//         if (m_age!=NULL)
//         {
//             delete m_age;
//             m_age = NULL;
//         }
//         m_age = new int(*p.m_age);
//         return *this;
//     }

// };

// Person::Person(/* args */)
// {
// }
// Person::Person(int age)
// {
//     m_age = new int(age);
// }
// Person::~Person()
// {
// }

// int main()
// {
//     Person p1(18);
//     Person p2(20);
//     cout<<*(p1.m_age)<<endl;
//     system("pause");
//     return 0;
// }


//关系运算符重载

// #include<iostream>

// using namespace std;

// class Person
// {
// private:
//     /* data */
// public:
//     Person(/* args */);
//     Person(string,int);
//     ~Person();
//     string m_name;
//     int m_age;
//     bool operator==(Person &p)
//     {
//         if(this->m_name==p.m_name)
//         {
//             return true;
//         }
//         else{
//             return false;
//         }
//     }
// };

// Person::Person(/* args */)
// {
// }
// Person::Person(string m_name,int m_age)
// {
//     this->m_name = m_name;
//     this->m_age = m_age;
// }

// Person::~Person()
// {
// }


// int main()

// {
//     Person P1("Tom",18);
//     Person P2("Tom",19);
//     bool a = (P1==P2);
//     cout<<a;
//     system("pause");
//     return 0;
// }


//函数调用运算符重载
//仿函数()

// #include<iostream>
// using namespace std;

// class MyPrint
// {
// private:
//     /* data */
    
// public:
//     MyPrint(/* args */);
//     ~MyPrint();
//     string test;
//     void operator()(string test)
//     {
//         cout<<test<<endl;
//     }
// };

// MyPrint::MyPrint(/* args */)
// {
//     test="hello world";
// }

// MyPrint::~MyPrint()
// {
// }

// int main()
// {
//     MyPrint a;
//     a("hxj");
//     cout<<a.test<<endl;
//     system("pause");
//     return 0;
// }



//继承！！！
//class 子类（派生类）：继承方式 父类（基类）

//继承方式：公共继承 保护继承 私有继承

#include<iostream>
using namespace std;

class Base
{
private:
    /* data */
    int m_c;
public:
    int m_a;
    static int m_s;
    Base(/* args */);
    ~Base();
protected:
    int m_b;
};

Base::Base(/* args */)
{
    cout<<"Base's构造函数"<<endl;
    m_a = 100;
}

Base::~Base()
{
    cout<<"Base's析构函数"<<endl;
}

class son :public Base
{
private:
    /* data */
public:
    son(/* args */);
    ~son();
    int m_d;
    int m_a;
    static int m_s;
};

son::son(/* args */)
{
    cout<<"son's构造函数"<<endl;
    m_a = 200;
}

son::~son()
{
    cout<<"son's析构函数"<<endl;
}

int Base::m_s=100;
int son::m_s=200;

class dad
{
private:
    /* data */
public:
    dad(/* args */);
    ~dad();
};

dad::dad(/* args */)
{
}

dad::~dad()
{
}


class sonson :public Base,public dad
{
private:
    /* data */
public:
    sonson(/* args */);
    ~sonson();
};

sonson::sonson(/* args */)
{
}

sonson::~sonson()
{
}


int main()
{
    son Son1;
    cout<<sizeof(Son1)<<endl;
    cout<<Son1.son::m_a<<endl;
    cout<<Son1.Base::m_a<<endl;
    cout<<Son1.m_s<<endl;
    cout<<Son1.son::m_s<<endl;
    cout<<Son1.Base::m_s<<endl;
    sonson sonson1;
    cout<<sizeof(sonson1)<<endl;
    system("pause");
    return 0;
}
//使用继承时，一定注意是否父类 子类是否有相同命名的成员变量或者成员函数，使用作用域：：加以区分。另外注意菱形继承问题
//使用虚继承可以解决菱形继承问题 virtual