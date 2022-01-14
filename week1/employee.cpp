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
    cout<<"职工编号："<<this->m_ID<<"\t职工姓名："<<this->m_name<<"\t职工岗位:"<<this->getDeptName()<<"\t岗位职责：完成经理安排的任务"<<endl;
}

string employee::getDeptName()
{
    return string("普通员工");
}