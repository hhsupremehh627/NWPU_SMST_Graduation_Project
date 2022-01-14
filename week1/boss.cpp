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
    cout<<"职工编号："<<this->m_ID<<"\t职工姓名："<<this->m_name<<"\t职工岗位:"<<this->getDeptName()<<"\t岗位职责：给经理安排任务"<<endl;

}

string boss::getDeptName()
{
    return string("老板");
}