// //�Ӻ����������
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
//     //���ڳ�Ա������������� 
//     Person operator+(Person &p)
//     {
//         Person temp;
//         temp.m_a = this->m_a + p.m_a;
//         temp.m_b = this->m_b + p.m_b;
//         return temp;
//     }
// };
// //���⹹�캯��
// Person::Person()
// {

// }

// Person::Person(int a,int b)
// {
//     this->m_a = a;
//     this->m_b = b;
// }
// //������������
// Person::~Person()
// {}
// //����ȫ�ֺ�������
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

//**���������
//��ʹ�ó�Ա��������������������� ��Ϊ�����ʽ��p<<cout
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

// //��ʽ��� ����cout��������ostream
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


//�������������  
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
//     //ǰ�õ���++
//     Myinter& operator++()
//     {
//         ++m_num;
//         return *this;
//     }
//     //���õ���++ ������Intռλ
//     Myinter operator++(int)
//     {
//         Myinter temp = *this;
//         m_num++;
//         return temp; //ע�⣬���ص���ջ��������û�н��в����ģ� ���ܷ������� ʹ����ͻ��ͷ�
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



//��ֵ���������
// C++���������ٸ�һ��������ĸ�������
// 1.Ĭ�Ϲ��캯��
// 2.Ĭ����������
// 3.Ĭ�Ϲ��쿽������
// 4.��ֵ�����operator=�����Խ���ֵ����

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


//��ϵ���������

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


//�����������������
//�º���()

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



//�̳У�����
//class ���ࣨ�����ࣩ���̳з�ʽ ���ࣨ���ࣩ

//�̳з�ʽ�������̳� �����̳� ˽�м̳�

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
    cout<<"Base's���캯��"<<endl;
    m_a = 100;
}

Base::~Base()
{
    cout<<"Base's��������"<<endl;
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
    cout<<"son's���캯��"<<endl;
    m_a = 200;
}

son::~son()
{
    cout<<"son's��������"<<endl;
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
//ʹ�ü̳�ʱ��һ��ע���Ƿ��� �����Ƿ�����ͬ�����ĳ�Ա�������߳�Ա������ʹ�������򣺣��������֡�����ע�����μ̳�����
//ʹ����̳п��Խ�����μ̳����� virtual