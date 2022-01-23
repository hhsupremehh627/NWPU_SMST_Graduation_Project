//类模板分文件编写
template<class T1,class T2>
class Person
{
private:
    /* data */
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
    T1 m_name;
    T2 m_age;
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