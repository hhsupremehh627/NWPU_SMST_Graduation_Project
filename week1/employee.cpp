#include<iostream>
#include"employee.h"
using namespace std;

employee::employee(int id,string name, int dID)
{
    this->m_ID=id;
    this->m_name = name;
    this->m_deptID=dID;
}

void employee::showInfo()
{
    cout<<"ְ����ţ�"<<this->m_ID<<"\tְ��������"<<this->m_name<<"\tְ����λ:"<<this->getDeptName()<<"\t��λְ����ɾ����ŵ�����"<<endl;
}

string employee::getDeptName()
{
    return string("��ͨԱ��");
}