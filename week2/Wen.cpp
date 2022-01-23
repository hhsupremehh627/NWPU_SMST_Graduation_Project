//STL�ӹ����Ϸ�Ϊ ������container�����㷨��algorithm������������iterator��
//�������㷨֮��ͨ����������������
//������� ��װ �̳� ��̬
//STL����������������㷨�����������º��������������ռ�������
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<deque>
//������vector �㷨 for_each ������vector<int>::iterator
using namespace std;

// void myprint(int val)
// {
//     cout<<val<<endl;
// }

class Person
{
private:
    /* data */
public:
    Person()
    {

    }
    Person(string name,int age)
    {
        this->name=name;
        this->age =age;
    }
    ~Person()
    {

    }
    string name;
    int age;
};



void test01()
{
    vector<Person> v;
    Person p1("a",10);
    Person p2("b",20);
    Person p3("c",30);

    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);

    // vector<int>::iterator itBegin = v.begin();
    // vector<int>::iterator itEnd = v.end(); //���������� ָ���������һ��Ԫ�� ����һ��λ��
    // //��һ�ֱ���
    // while (itBegin!=itEnd)
    // {
    //     cout<<*itBegin<<endl;
    //     itBegin++;
    //     /* code */
    // }
    
    //�ڶ���
    for(vector<Person>::iterator it=v.begin();it!=v.end();it++)
    {
        cout<<(*it).name<<endl;
        cout<<it->age<<endl;
    }

    //������ ����STL�ṩ �ı����㷨
    //for_each(v.begin(),v.end(),myprint);


}

void test02()
{
    vector<Person*> v1;
    Person p1("a",10);
    Person p2("b",20);
    Person p3("c",30);

    v1.push_back(&p1);
    v1.push_back(&p2);
    v1.push_back(&p3);

    for(vector<Person*>::iterator it=v1.begin();it!=v1.end();it++)
    {
        cout<<(*it)->name<<endl;
    }
}


//Ƕ������--��ά����
void test03()
{
    vector<vector<int>>v;
    //���� С����
    vector<int>v1;
    vector<int>v2;
    vector<int>v3;
    vector<int>v4;

    for(int i=0;i<5;i++)
    {
        v1.push_back(i);
        v2.push_back(i+5);
        v3.push_back(i+10);
        v4.push_back(i+15);
    }
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    v.push_back(v4);
    for(vector<vector<int>>::iterator  it=v.begin();it!=v.end();it++)
    {
        for(vector<int>::iterator vit=(*it).begin();vit!=(*it).end();vit++)
        {
            cout<<(*vit)<<"\t";
        }
        cout<<endl;
    }
}

void test04()
{
    // string s1; //Ĭ�Ϲ���
    // const char* str = "hello world";
    // string s2(str);
    // string s3(s2);
    // string s4(10,'a');
    // s1 = "hello 2022.1.18";
    // cout<<"s1:"<<s1<<endl;
    // s2 = str;
    // s4.assign("hello C++");
    // cout<<s4;
    // s4 += "���������ĵ�һ��";
    // s4 += 'h'; //ע���ǵ����� ׷�ӵ����ַ�
    // s4 += s1;
    // s4.append("ʹ��append׷��");
    // cout<<s4<<endl;
    string str1 = "abcdefg";
    int ye = str1.find("dg");
    int ye1 = str1.rfind("de");
    //rfind�Ǵ����������
    cout<<ye<<endl;
    //str1.replace(1,3,"1111");
    cout<<str1<<endl;
    for(int i=0;i<str1.size();i++)
    {
        cout<<str1[i];
    }
    for(int i=0;i<str1.size();i++)
    {
        cout<<str1.at(i);
    }
    cout<<endl;
    str1[0] = 'x';
    str1.at(0) = 'a';
    str1.insert(2,"j");
    cout<<str1<<endl;
    str1.erase(2,1);
    cout<<str1<<endl;
    string subStr = str1.substr(1,3);
    string subStr1 = str1.substr(0,3);
    cout<<subStr<<endl;
    cout<<subStr1<<endl;

}

void printvector(vector<int>&v);
//vector������ǳ����� �ǵ������� ���������Զ�̬��չ 
void test05()
{
    vector<int>v1;
    for(int i=0;i<10;i++)
    {
        v1.push_back(i);
    }
    printvector(v1);
    vector<int>v2(v1.begin(),v1.end());
    printvector(v2);

    // vector<int>v3(10,100);
    // printvector(v3);
    // vector<int>v4(v3);
    // printvector(v3);

    // vector<int>v3;
    // v3 = v1;
    // printvector(v3);
    // vector<int>v4;
    // v4.assign(v1.begin(),v1.end());
    // printvector(v4);
    // cout<<v4.size();
    // cout<<v4.front();
    // cout<<v4.back()<<endl;
    // v4.push_back(11);
    // v4.swap(v3);
    // printvector(v4);
    vector<int>v8;
    v8.reserve(100000);
    int num=0;
    int* p = NULL;
    for(int i=0;i<100000;i++)
    {
        v8.push_back(i);
        if(p!=&v8[0])
        {
            num++;
            p = &v8[0];
        }
    }
    cout<<"num: "<<num<<endl;
    
}

void printvector(vector<int>&v)
{
    for(vector<int>::iterator it=v.begin();it!=v.end();it++)
    {
        cout<<(*it)<<" ";
    }
    cout<<endl;
}

//deque������˫������ 
// vector����ͷ���Ĳ���ɾ��Ч�ʵ�
// vector����Ԫ�����ٶȿ�

void printdeque(deque<int>&d)
{
    for(deque<int>::iterator it=d.begin();it!=d.end();it++)
    {
        //*it = 100;
        cout<<*it<<" ";
    }
    cout<<endl;
}

void test06()
{
    deque<int>d1;
    for(int i=0;i<10;i++)
    {
        d1.push_front(i);

    }
    d1.push_back(20);
    d1.push_back(17);
    printdeque(d1);
    sort(d1.begin(),d1.end());
    printdeque(d1);
    
}

int main()
{
    test06();
    system("pause");
    return 0;
}