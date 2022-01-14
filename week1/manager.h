#pragma once
#include<iostream>
using namespace std;
#include"worker.h"

class manager:public worker
{
private:
    /* data */
public:
    manager(int,string,int);
    ~manager();
    virtual void showInfo();
    virtual string getDeptName();
};
