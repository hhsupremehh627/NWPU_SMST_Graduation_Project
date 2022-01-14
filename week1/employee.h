#pragma once
#include<iostream>
#include"worker.h"
using namespace std;

class employee :public worker
{
private:
    /* data */
public:
    employee(int id,string name, int dID);
    ~employee();
    virtual void showInfo();
    virtual string getDeptName();
};



