#pragma once
#include<iostream>
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
#include<fstream>

#define FILENAME "empFile.txt"
using namespace std;

class workerManger
{
private:
    /* data */
public:
    //成员函数
    workerManger(/* args */);
    ~workerManger();
    void ShowMenu(); //展示菜单
    void ExitMenu(); //退出
    void Add_Emp(); //添加员工
    void save(); //保存文件
    void read(); //读文件
    int get_EmpNum(); //获取人数
    void init_Emp(); //如果文件中有数据 初始化数组
    void show_Emp(); //显示所有成员
    void Del_Emp();  //删除成员 
    int IsExit(int id); //查找是否存在
    void Change_Emp(); //修改职工信息
    void Find_Emp(); //查找职工信息（按照姓名）
    void Sort_Emp(); //排序
    void Clean_Emp(); //删库跑路
    //成员变量
    int m_EmpNum;
    worker** m_EmpArray;//指针的指针 解引用第一个指针得到worker*对象，可以使用多态对三种工种进行访问
    bool m_FileIsEmpty;
};
