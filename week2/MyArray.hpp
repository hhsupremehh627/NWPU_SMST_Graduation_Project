//����������
#pragma once
#include<iostream>
using namespace std;

template<class T>
class MyArray
{
private:
    T* pAddress; //ָ��������ٵ�����
    int m_Cap; //����
    int m_Size; //����
public:
    MyArray(int cap)
    {
        this->m_Cap = cap;
        this->m_Size = 0;
        this->pAddress = new T[this->m_Cap];
        //cout<<"�вй���"<<endl;
    }
    ~MyArray()
    {
        if(this->pAddress!=NULL)
        {
            delete[] this->pAddress;
        }
        //cout<<"����"<<endl;
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
        //cout<<"��������"<<endl;
    }

    MyArray& operator=(const MyArray &arr)
    {
        //cout<<"=����"<<endl;
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

    void PushBack(const T &value)//β��
    {
        //�ж�����
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

