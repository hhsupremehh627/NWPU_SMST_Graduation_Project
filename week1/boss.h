#pragma once
#include<iostream>
using namespace std;
#include"worker.h"

class boss:public worker
{
private:
    /* data */
public:
    boss(int id,string name,int dID);
    ~boss();
    virtual void showInfo();
    virtual string getDeptName();
};

