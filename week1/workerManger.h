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
    //��Ա����
    workerManger(/* args */);
    ~workerManger();
    void ShowMenu(); //չʾ�˵�
    void ExitMenu(); //�˳�
    void Add_Emp(); //���Ա��
    void save(); //�����ļ�
    void read(); //���ļ�
    int get_EmpNum(); //��ȡ����
    void init_Emp(); //����ļ��������� ��ʼ������
    void show_Emp(); //��ʾ���г�Ա
    void Del_Emp();  //ɾ����Ա 
    int IsExit(int id); //�����Ƿ����
    void Change_Emp(); //�޸�ְ����Ϣ
    void Find_Emp(); //����ְ����Ϣ������������
    void Sort_Emp(); //����
    void Clean_Emp(); //ɾ����·
    //��Ա����
    int m_EmpNum;
    worker** m_EmpArray;//ָ���ָ�� �����õ�һ��ָ��õ�worker*���󣬿���ʹ�ö�̬�����ֹ��ֽ��з���
    bool m_FileIsEmpty;
};
