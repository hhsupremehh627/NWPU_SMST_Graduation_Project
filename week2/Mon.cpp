//���ͱ��--����ģ�� 
//����ģ����� ģ�� 
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

// template<typename T> //����һ��ģ�� T�� һ��ͨ����������
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

//���ַ�ʽ ʹ�ú���ģ��
//����ģ�� �Զ������Ƶ� �����Ƶ���һ�µ���������T����ʹ��
//����ģ�� ģ�����Ҫȷ����T���������Ͳſ���ʹ��
// void test02()
// {
//     int a=10;
//     int b=20;
//     //1.�Զ������Ƶ�
//     mySwap(a,b);
//     //2.��ʾָ������
//     mySwap<int>(a,b);
// }


//ѡ������
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

//��ͨ�������Խ�����ʽ����ת�� ���β�����������ͺ�ʵ�β���Ӧ�ǣ�ʵ�ν���ת��Ϊ�βε���������
//����ģ��ʹ���Զ������Ƶ�ʱ�������Է�������ת��
//����ģ��ʹ����ʾָ�������ǣ����Է�������ת��
//��ͨ�����ͺ���ģ��������أ����������������ȵ�����ͨ���� 
//����ͨ����ģ������б���ǿ������ģ��
//����ģ��ľ����� ��Щ�ض�������������Ҫ���廯��ʽ������ʵ��
// int main()
// {
//     test03();
//     system("pause");
//     return 0;
// }

//��ģ��
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
//����ģ�����ģ�������
//��ģ��û���Զ��Ƶ���ʹ�÷�ʽ
//��ģ����ģ������б��п�����Ĭ�ϲ���
// ��ģ��ʵ�������Ķ����������εķ�ʽ�����֣�
// 1.ָ����������
// 2.����ģ�廯
// 3.������ģ�廯

//��ģ�庯������ʵ��

template<class T1,class T2>
class Person;
//��Ա
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
//����ʵ��
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

//����ʵ��
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