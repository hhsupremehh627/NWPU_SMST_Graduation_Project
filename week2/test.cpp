#include<iostream>
#include<string>

using namespace std;

template<class NameType>
class Person
{
public:
    Person(NameType name)
    {
        this->m_name = name;
    }    
    NameType m_name;
    ~Person()
    {
        
    }
};

int main()
{
    Person<string> me("hxj");
    return 0;
}