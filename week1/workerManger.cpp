#include<iostream>
#include"workerManger.h"

using namespace std;

workerManger::workerManger()
{
    cout<<"workerManger默认构造函数"<<endl;
    ifstream ifs;
    ifs.open(FILENAME, ios::in);
    if(!ifs.is_open())
    {
        cout<<"文件不存在"<<endl;
        this->m_EmpNum=0;
        this->m_FileIsEmpty=true;
        this->m_EmpArray=NULL;
        ifs.close();
        return;
    }

    char ch;
    ifs>>ch;
    if(ifs.eof())//判断是否已经读到文件尾 end of file
    {
        cout<<"文件为空"<<endl;
        this->m_EmpArray=NULL;
        this->m_EmpNum=0;
        this->m_FileIsEmpty=true;
        ifs.close();
        return;
    }

    int num = this->get_EmpNum();
    cout<<"职工人数为： "<<num<<endl;
    this->m_EmpNum = num;
    this->m_FileIsEmpty = false;
    this->m_EmpArray = new worker*[m_EmpNum];
    init_Emp();

}

workerManger::~workerManger()
{
    if(this->m_EmpArray!=NULL)
    {
        delete[] this->m_EmpArray;
        this->m_EmpArray = NULL;
    }
}

void workerManger::ShowMenu()
{
    cout<<"***************************************"<<endl;
    cout<<"**********欢迎使用职工管理系统*********"<<endl;
    cout<<"********** 0.退出管理系统 *************"<<endl;
    cout<<"********** 1.增加职工信息 *************"<<endl;
    cout<<"********** 2.显示职工信息 *************"<<endl;
    cout<<"********** 3.删除离职职工 *************"<<endl;
    cout<<"********** 4.修改职工信息 *************"<<endl;
    cout<<"********** 5.查找职工信息 *************"<<endl;
    cout<<"********** 6.按照编号排序 *************"<<endl;
    cout<<"********** 7.清空所有文档 *************"<<endl;
    cout<<"***************************************"<<endl;
    cout<<endl;
}

void workerManger::ExitMenu()
{
    cout<<"感谢使用！ 下次再见 ！"<<endl;
    system("pause");
    exit(0);
}

void workerManger::Add_Emp()
{

    cout<<"请输入添加职工数量："<<endl;
    int addNum=0;
    cin>>addNum;
    if(addNum>0)
    {
        //添加
        //计算添加新空间的大小
        int newSize = this->m_EmpNum + addNum;
        //开辟新空间
        worker** newSpace =  new worker*[newSize];
        //将原来的数据先拷贝到新空间下
        if(this->m_EmpArray!=NULL)
        {
            for(int i=0;i<this->m_EmpNum;i++)
            {
                newSpace[i] = this->m_EmpArray[i];
            }
        }
        //添加新数据
        for(int i=0;i<addNum;i++)
        {
            int id;
            string name;
            int dSelect;
            cout<<"请输入第"<<i+1<<"个新职工编号："<<endl;
            cin>>id;
            cout<<"请输入第"<<i+1<<"个新职工姓名："<<endl;
            cin>>name;
            cout<<"请输入第"<<i+1<<"个新职工岗位："<<endl;
            cout<<"1.普通职工"<<endl;
            cout<<"2.经理"<<endl;
            cout<<"3.老板"<<endl;
            cin>>dSelect;
            worker* person = NULL;
            switch (dSelect)
            {
            case 1:
                person = new employee(id,name,1);
                break;
            case 2:
                person = new manager(id,name,2);
                break;
            case 3:
                person = new boss(id,name,3);
                break;
            default:
                cout<<"输入有误"<<endl;
                break;
            }
            newSpace[this->m_EmpNum+i]=person;

        }
        delete[] this->m_EmpArray;
        this->m_EmpArray = newSpace;
        this->m_EmpNum = newSize;
        cout<<"成功添加"<<addNum<<"名新职工"<<endl;
        this->save();
        this->m_FileIsEmpty=false;
    }
    else{
        cout<<"输入有误"<<endl;
    }
    system("pause");
    system("cls");
}

void workerManger::save()
{
    ofstream ofs;
    ofs.open(FILENAME,ios::out);
    for(int i=0;i<this->m_EmpNum;i++)
    {
        ofs<<this->m_EmpArray[i]->m_ID<<" "
           <<this->m_EmpArray[i]->m_name<<" "
           <<this->m_EmpArray[i]->m_deptID<<endl;
    }
    ofs.close();    
}

int workerManger::get_EmpNum()
{
    ifstream ifs;
    ifs.open(FILENAME,ios::in);
    int id;
    string name;
    int dID;
    int num = 0;
    while (ifs>>id && ifs>>name && ifs>>dID)
    {
        num++;
    }
    ifs.close();
    return num;   
}


void workerManger::init_Emp()
{
    ifstream ifs;
    ifs.open(FILENAME,ios::in);
    int id;
    string name;
    int dID;
    int index = 0; //flag
    while(ifs>>id && ifs>>name && ifs>>dID)
    {
        worker* person = NULL;
        //根据dID使用不同的实例
        if(dID==1)
        {
            person = new employee(id,name,1);
        }
        else if(dID==2)
        {
            person = new manager(id,name,2);
        }
        else{
            person = new boss(id,name,3);
        }
        this->m_EmpArray[index] = person;
        index++;
    }
}

void workerManger::show_Emp()
{
    if(this->m_FileIsEmpty)
    {
        cout<<"文件为空 没有人"<<endl;
    }
    else{
        for(int i=0;i<this->m_EmpNum;i++)
        {
            this->m_EmpArray[i]->showInfo();
        }
    }
    system("pause");
    system("cls");
}


int workerManger::IsExit(int id)
{
    int index=-1;
    for(int i=0;i<this->m_EmpNum;i++)
    {
        if(this->m_EmpArray[i]->m_ID==id)
        {
            index = i;
            break;
        }
    }
    return index;
}


void workerManger::Del_Emp()
{
    if(this->m_FileIsEmpty)
    {
        cout<<"文件为空"<<endl;
    }
    else{
        int input_i;
        cout<<"输入：";
        cin>>input_i;
        int ret = this->IsExit(input_i);
        if (ret!=-1)
        {
            for(int i=ret;i<this->m_EmpNum-1;i++)
            {
                this->m_EmpArray[i]=this->m_EmpArray[i+1];
            }
            this->m_EmpNum--;
            this->save();
            cout<<"删除成功"<<endl;
        }
        else{
            cout<<"职工不存在"<<endl;
        }
    }
    system("pause");
    system("cls");
}

void workerManger::Change_Emp()
{
    if(this->m_FileIsEmpty)
    {
        cout<<"文件为空"<<endl;
    }
    else{
        cout<<"请输入修改职工的编号："<<endl;
        int id;
        cin>>id;
        int ret = this->IsExit(id);
        if(ret!=-1)
        {
            delete this->m_EmpArray[ret];
            int newid;
            string newname="";
            int newdselect;
            cout<<"找到"<<id<<"号职工，请输入新职工ID"<<endl;
            cin>>newid;
            cout<<"输入姓名"<<endl;
            cin>>newname;
            cout<<"输入岗位 1 2 3"<<endl;
            cin>>newdselect;

            worker * person = NULL;
            switch (newdselect)
            {
            case 1:
                person = new employee(newid,newname,newdselect);
                break;
            case 2:
                person = new manager(newid,newname,newdselect);
                break;
            case 3:
                person = new boss(newid,newname,newdselect);
                break;
            default:
                break;
            }
            this->m_EmpArray[ret] = person;
            cout<<"修改成功"<<endl;
            this->save();

        }
        else{
            cout<<"修改失败 查无此人"<<endl;
        }
    }
    system("pause");
    system("cls");
}

void workerManger::Find_Emp()
{
    if(this->m_FileIsEmpty)
    {
        cout<<"文件为空"<<endl;
    }
    else{
        cout<<"请输入查找职工的ID："<<endl;
        int id;
        cin>>id;
        int ret = this->IsExit(id);
        if(ret!=-1)
        {
            cout<<"找到了"<<endl;
            //cout<<this->m_EmpArray[ret]->m_ID<<endl;
            //cout<<this->m_EmpArray[ret]->m_name <<endl;
            //cout<<this->m_EmpArray[ret]->m_deptID<<endl;
            this->m_EmpArray[ret]->showInfo();
        }
        
    }

}

void workerManger::Sort_Emp()
{
    cout<<"请选择排序方式："<<endl;
    cout<<"1 按照ID升序排列"<<endl;
    cout<<"2 按照ID降序排列"<<endl;
    int flag=0;
    cin>>flag;
    if(flag==1)
    {
        for(int i=0;i<this->m_EmpNum-1;i++)
        {
            int min=i;
            for(int j=i+1;j<this->m_EmpNum;j++)
            {
                if(this->m_EmpArray[j]->m_ID<this->m_EmpArray[min]->m_ID)
                {
                    min = j;
                }
            }
            worker* temp = m_EmpArray[i];
            m_EmpArray[i] = m_EmpArray[min];
            m_EmpArray[min] = temp;
        }
    }
    else if (flag==2)
    {
        for(int i=0;i<this->m_EmpNum-1;i++)
        {
            int max=i;
            for(int j=i+1;j<this->m_EmpNum;j++)
            {
                if(this->m_EmpArray[j]->m_ID>this->m_EmpArray[max]->m_ID)
                {
                    max = j;
                }
            }
            worker* temp = m_EmpArray[i];
            m_EmpArray[i] = m_EmpArray[max];
            m_EmpArray[max] = temp;
        }
    }
    else{
        cout<<"选择错误"<<endl;
    }
    
    this->save();
}


void workerManger::Clean_Emp()
{
    char flag;
    cout<<"确认删除？（y/n)"<<endl;
    cin>>flag;
    if(flag=='y')
    {
        ofstream ofs;
        ofs.open(FILENAME,ios::trunc);
        ofs.close();
        if(this->m_EmpArray!=NULL)
        {
            for(int i=0;i<this->m_EmpNum;i++)
            {
                if(this->m_EmpArray[i]!=NULL)
                {
                    delete this->m_EmpArray[i];
                }
            }
            this->m_EmpNum=0;
            this->m_FileIsEmpty=true;
            this->m_EmpArray=NULL;
        }
        cout<<"清空 跑路！！！"<<endl;
    }
    else if (flag =='n')
    {
        /* code */
        cout<<"恭喜你活下来了"<<endl;
    }
    else{
        cout<<"输入错误"<<endl;
    }
    
}