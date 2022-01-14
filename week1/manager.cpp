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
    cout<<"职工编号："<<this->m_ID<<"\t职工姓名："<<this->m_name<<"\t职工岗位:"<<this->getDeptName()<<"\t岗位职责：完成老板安排的任务并下发任务给员工"<<endl;
}

string manager::getDeptName()
{
    return string("经理");
}