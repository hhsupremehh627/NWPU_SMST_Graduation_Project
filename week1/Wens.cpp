//文件操作
// 头文件<fstream>

// 操作文件的三大类：
// 1.ofstream 写操作
// 2.ifstream 读操作
// 3.fstream 读写操作

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
        cout<<"打开成功！"<<endl;
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
    char name[64]="张三";
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