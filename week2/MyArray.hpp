//自制数组类
#pragma once
#include<iostream>
using namespace std;

template<class T>
class MyArray
{
private:
    T* pAddress; //指向堆区开辟的数组
    int m_Cap; //容量
    int m_Size; //个数
public:
    MyArray(int cap)
    {
        this->m_Cap = cap;
        this->m_Size = 0;
        this->pAddress = new T[this->m_Cap];
        //cout<<"有残构造"<<endl;
    }
    ~MyArray()
    {
        if(this->pAddress!=NULL)
        {
            delete[] this->pAddress;
        }
        //cout<<"析构"<<endl;
    }
    
    MyArray(const MyArray& arr)
    {
        this->m_Cap = arr.m_Cap;
        this->m_Size = arr.m_Size;
        this->pAddress = new T[arr.m_Cap];
        for(int i=0;i<this->m_Size;i++)
        {
            this->pAddress[i] = arr.pAddress[i];
        }
        //cout<<"拷贝构造"<<endl;
    }

    MyArray& operator=(const MyArray &arr)
    {
        //cout<<"=重载"<<endl;
        if(this->pAddress!=NULL)
        {
            delete [] this->pAddress;
            this->pAddress = NULL;
            this->m_Cap = 0;
            this->m_Size = 0;
        }
        this->m_Cap = arr.m_Cap;
        this->m_Size = arr.m_Size;
        this->pAddress = new T[arr.m_Cap];
        for(int i=0;i<this->m_Size;i++)
        {
            this->pAddress[i] = arr.pAddress[i];
        }
        return *this;
    }

    void PushBack(const T &value)//尾插
    {
        //判断容量
        if(this->m_Cap==this->m_Size)
        {
            cout<<"error"<<endl;
            return;
        }
        this->pAddress[this->m_Size] = value;
        this->m_Size++;
    }

    void DelBack()
    {
        if(this->m_Size==0)
        {
            return;
        }
        this->m_Size--;
    }

    T& operator[](int index)
    {
        if(index<this->m_Size&&index>-1)
        {
            return this->pAddress[index];
        }
    }

};

