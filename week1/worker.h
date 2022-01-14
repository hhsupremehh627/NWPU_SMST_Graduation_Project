#pragma once
#include<iostream>
using namespace std;

class worker
{
private:
    /* data */
public:
    int m_ID;//职工编号
    string m_name;//职工姓名
    int m_deptID;//部门编号
    virtual void showInfo()=0;
    virtual string getDeptName()=0;
};
