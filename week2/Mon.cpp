//泛型编程--利用模板 
//函数模板和类 模板 
#include<iostream>
using namespace std;
//#include"Person.hpp"

// void swapInt(int &a,int &b)
// {
//     int temp =a;
//     a =b;
//     b = temp;
// }

// void swapFloat(float &a,float &b)
// {
//     float temp = a;
//     a = b;
//     b = temp;
// }
//template<class T>

// template<typename T> //声明一个模板 T是 一个通用数据类型
// void mySwap(T &a,T &b)
// {
//     T temp = a;
//     a = b;
//     b = temp;
// }

// void test01()
// {
//     int a=10;
//     int b=20;
//     swapInt(a,b);
// }

//两种方式 使用函数模板
//函数模板 自动类型推导 必须推导出一致的数据类型T才能使用
//函数模板 模板必须要确定出T的数据类型才可以使用
// void test02()
// {
//     int a=10;
//     int b=20;
//     //1.自动类型推导
//     mySwap(a,b);
//     //2.显示指定类型
//     mySwap<int>(a,b);
// }


//选择排序
// template<typename T>
// void mySort(T arr[],int len)
// {
//     for(int i=0;i<len;i++)
//     {
//         int min = i;
//         for(int j=i;j<len;j++)
//         {
//             if (arr[j]<arr[min])
//             {
//                 min = j;
//             }
//         }
//         T temp;
//         temp = arr[i];
//         arr[i] = arr[min];
//         arr[min] = temp;
//     }
// }

// void test03()
// {
//     int arr[] = {10,9,1,2,8,7,3,4,6,5};
//     int len = sizeof(arr)/sizeof(arr[0]);
//     mySort(arr,len);
//     for(int i=0;i<10;i++)
//     {
//         cout<<arr[i]<<"\t";
//     }
//     cout<<endl;
//     char arr1[] = "houxujiacd";
//     int len1 = sizeof(arr1)/sizeof(arr1[0]);
//     mySort(arr1,len1);
//     for(int i=0;i<10;i++)
//     {
//         cout<<arr1[i]<<"\t";
//     }
// }

//普通函数可以进行隐式类型转换 即形参如果数据类型和实参不对应是，实参将会转换为形参的数据类型
//函数模板使用自动类型推导时，不可以发生类型转换
//函数模板使用显示指定类型是，可以发生类型转换
//普通函数和函数模板可以重载，即允许重名。优先调用普通函数 
//可以通过空模板参数列表来强调函数模板
//函数模板的局限性 有些特定的数据类型需要具体化方式做特殊实现
// int main()
// {
//     test03();
//     system("pause");
//     return 0;
// }

//类模板
// template<class NameType,class AgeType>
// class Person
// {
// public:
//     Person(NameType name, AgeType age)
//     {
//         this->m_name = name;
//         this->m_age = age;
//     }    
//     NameType m_name;
//     AgeType m_age;
//     ~Person()
//     {

//     }
// };

// int main()
// {
//     Person<string,int> me("hxj",20);
//     return 0;
// }
//函数模板和类模板的区别：
//类模板没有自动推导的使用方式
//类模板在模板参数列表中可以有默认参数
// 类模板实例化出的对象，向函数传参的方式有三种：
// 1.指定传入类型
// 2.参数模板化
// 3.整个类模板化

//类模板函数类外实现

template<class T1,class T2>
class Person;
//友员
template<class T1,class T2>
void printPerson2(Person<T1,T2> p)
{
    cout<<p.m_age<<p.m_name<<endl;
}


template<class T1,class T2>
class Person
{
    friend void printPerson2<>(Person<T1,T2> p);
private:
    /* data */
    T1 m_name;
    T2 m_age;
public:
//类内实现
    // Person(T1 name, T2 age)
    // {
    //     this->m_age = age;
    //     this->m_name = name;
    // }
    // void showPerson()
    // {
    //     cout<<this->m_name<<"\t"<<this->m_age<<endl;
    // }
    // ~Person()
    // {

    // }
    Person(T1 name, T2 age);
    void showPerson();
};

//类外实现
template<class T1,class T2>
Person<T1,T2>::Person(T1 name, T2 age)
{
    this->m_age = age;
    this->m_name = name;
}


template<class T1,class T2>
void Person<T1,T2>::showPerson()
{
    cout<<this->m_name<<"\t"<<this->m_age<<endl;
}


void test04()
{
    //Person<string,int> P("hxj",20);
    //P.showPerson();
    Person<string,int> P("tom",1);
    printPerson2(P);
}


int main()
{
    test04();
    system("pause");
    return 0;
}