#include<iostream>
#include"manager.h"

using namespace std;

manager::manager(int id,string name,int dID)
{
    this->m_ID = id;
    this->m_name = name;
    this->m_deptID = dID;
}

void manager::showInfo()
{
    cout<<"ְ����ţ�"<<this->m_ID<<"\tְ��������"<<this->m_name<<"\tְ����λ:"<<this->getDeptName()<<"\t��λְ������ϰ尲�ŵ������·������Ա��"<<endl;
}

string manager::getDeptName()
{
    return string("����");
}