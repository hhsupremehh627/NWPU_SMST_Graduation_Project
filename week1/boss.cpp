#include<iostream>
#include"boss.h"

using namespace std;

boss::boss(int id,string name,int dID)
{
    this->m_ID = id;
    this->m_name = name;
    this->m_deptID = dID;
}

void boss::showInfo()
{
    cout<<"ְ����ţ�"<<this->m_ID<<"\tְ��������"<<this->m_name<<"\tְ����λ:"<<this->getDeptName()<<"\t��λְ�𣺸�����������"<<endl;

}

string boss::getDeptName()
{
    return string("�ϰ�");
}