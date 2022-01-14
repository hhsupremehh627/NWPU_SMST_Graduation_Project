//�ļ�����
// ͷ�ļ�<fstream>

// �����ļ��������ࣺ
// 1.ofstream д����
// 2.ifstream ������
// 3.fstream ��д����

#include<iostream>
#include<fstream>

using namespace std;

void write_txt()
{
    ofstream ofs;
    ofs.open("test.txt",ios::out);
    for(int i=0;i<10;i++)
    {
            ofs<<"hello world! "<<to_string(i)<<endl;
    }
    ofs.close();
}

void read_txt()
{
    ifstream ifs;
    ifs.open("test.txt",ios::in);
    if(ifs.is_open())
    {
        cout<<"�򿪳ɹ���"<<endl;
    }
    // char buf[1024] = {0};
    // while(ifs>>buf)
    // {
    //     cout<<buf<<endl;
    // }


    // char buf1[1024] = {0};
    // while(ifs.getline(buf1,sizeof(buf1)))
    // {
    //     cout<<buf1<<endl;
    // }

    // string buf;
    // while(getline(ifs,buf))
    // {
    //     cout<<buf<<endl;
    // }

    char c;
    while((c = ifs.get())!=EOF)
    {
        cout<<c;
    }

    ifs.close();
}

class Person
{
private:
    /* data */
public:
    Person(/* args */);
    ~Person();
    char name[64]="����";
    int m_Age=18;
};

Person::Person(/* args */)
{
}

Person::~Person()
{
}

void write_binary()
{
    ofstream ofs("Person.txt",ios::out|ios::binary);
    Person P;
    ofs.write((const char*)&P,sizeof(P));
    ofs.close();
}

void read_binary()
{
    ifstream ifs;
    ifs.open("Person.txt",ios::in|ios::binary);
    if(ifs.is_open()) 
    {
        cout<<"ok"<<endl;
    }
    Person p;
    ifs.read((char*)&p,sizeof(Person));
    cout<<p.m_Age<<endl;
}

int main()
{
    write_txt();
    read_txt();
    write_binary();
    read_binary();
    system("pause");
    return 0;
}