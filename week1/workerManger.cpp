#include<iostream>
#include"workerManger.h"

using namespace std;

workerManger::workerManger()
{
    cout<<"workerMangerĬ�Ϲ��캯��"<<endl;
    ifstream ifs;
    ifs.open(FILENAME, ios::in);
    if(!ifs.is_open())
    {
        cout<<"�ļ�������"<<endl;
        this->m_EmpNum=0;
        this->m_FileIsEmpty=true;
        this->m_EmpArray=NULL;
        ifs.close();
        return;
    }

    char ch;
    ifs>>ch;
    if(ifs.eof())//�ж��Ƿ��Ѿ������ļ�β end of file
    {
        cout<<"�ļ�Ϊ��"<<endl;
        this->m_EmpArray=NULL;
        this->m_EmpNum=0;
        this->m_FileIsEmpty=true;
        ifs.close();
        return;
    }

    int num = this->get_EmpNum();
    cout<<"ְ������Ϊ�� "<<num<<endl;
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
    cout<<"**********��ӭʹ��ְ������ϵͳ*********"<<endl;
    cout<<"********** 0.�˳�����ϵͳ *************"<<endl;
    cout<<"********** 1.����ְ����Ϣ *************"<<endl;
    cout<<"********** 2.��ʾְ����Ϣ *************"<<endl;
    cout<<"********** 3.ɾ����ְְ�� *************"<<endl;
    cout<<"********** 4.�޸�ְ����Ϣ *************"<<endl;
    cout<<"********** 5.����ְ����Ϣ *************"<<endl;
    cout<<"********** 6.���ձ������ *************"<<endl;
    cout<<"********** 7.��������ĵ� *************"<<endl;
    cout<<"***************************************"<<endl;
    cout<<endl;
}

void workerManger::ExitMenu()
{
    cout<<"��лʹ�ã� �´��ټ� ��"<<endl;
    system("pause");
    exit(0);
}

void workerManger::Add_Emp()
{

    cout<<"���������ְ��������"<<endl;
    int addNum=0;
    cin>>addNum;
    if(addNum>0)
    {
        //���
        //��������¿ռ�Ĵ�С
        int newSize = this->m_EmpNum + addNum;
        //�����¿ռ�
        worker** newSpace =  new worker*[newSize];
        //��ԭ���������ȿ������¿ռ���
        if(this->m_EmpArray!=NULL)
        {
            for(int i=0;i<this->m_EmpNum;i++)
            {
                newSpace[i] = this->m_EmpArray[i];
            }
        }
        //���������
        for(int i=0;i<addNum;i++)
        {
            int id;
            string name;
            int dSelect;
            cout<<"�������"<<i+1<<"����ְ����ţ�"<<endl;
            cin>>id;
            cout<<"�������"<<i+1<<"����ְ��������"<<endl;
            cin>>name;
            cout<<"�������"<<i+1<<"����ְ����λ��"<<endl;
            cout<<"1.��ְͨ��"<<endl;
            cout<<"2.����"<<endl;
            cout<<"3.�ϰ�"<<endl;
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
                cout<<"��������"<<endl;
                break;
            }
            newSpace[this->m_EmpNum+i]=person;

        }
        delete[] this->m_EmpArray;
        this->m_EmpArray = newSpace;
        this->m_EmpNum = newSize;
        cout<<"�ɹ����"<<addNum<<"����ְ��"<<endl;
        this->save();
        this->m_FileIsEmpty=false;
    }
    else{
        cout<<"��������"<<endl;
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
        //����dIDʹ�ò�ͬ��ʵ��
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
        cout<<"�ļ�Ϊ�� û����"<<endl;
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
        cout<<"�ļ�Ϊ��"<<endl;
    }
    else{
        int input_i;
        cout<<"���룺";
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
            cout<<"ɾ���ɹ�"<<endl;
        }
        else{
            cout<<"ְ��������"<<endl;
        }
    }
    system("pause");
    system("cls");
}

void workerManger::Change_Emp()
{
    if(this->m_FileIsEmpty)
    {
        cout<<"�ļ�Ϊ��"<<endl;
    }
    else{
        cout<<"�������޸�ְ���ı�ţ�"<<endl;
        int id;
        cin>>id;
        int ret = this->IsExit(id);
        if(ret!=-1)
        {
            delete this->m_EmpArray[ret];
            int newid;
            string newname="";
            int newdselect;
            cout<<"�ҵ�"<<id<<"��ְ������������ְ��ID"<<endl;
            cin>>newid;
            cout<<"��������"<<endl;
            cin>>newname;
            cout<<"�����λ 1 2 3"<<endl;
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
            cout<<"�޸ĳɹ�"<<endl;
            this->save();

        }
        else{
            cout<<"�޸�ʧ�� ���޴���"<<endl;
        }
    }
    system("pause");
    system("cls");
}

void workerManger::Find_Emp()
{
    if(this->m_FileIsEmpty)
    {
        cout<<"�ļ�Ϊ��"<<endl;
    }
    else{
        cout<<"���������ְ����ID��"<<endl;
        int id;
        cin>>id;
        int ret = this->IsExit(id);
        if(ret!=-1)
        {
            cout<<"�ҵ���"<<endl;
            //cout<<this->m_EmpArray[ret]->m_ID<<endl;
            //cout<<this->m_EmpArray[ret]->m_name <<endl;
            //cout<<this->m_EmpArray[ret]->m_deptID<<endl;
            this->m_EmpArray[ret]->showInfo();
        }
        
    }

}

void workerManger::Sort_Emp()
{
    cout<<"��ѡ������ʽ��"<<endl;
    cout<<"1 ����ID��������"<<endl;
    cout<<"2 ����ID��������"<<endl;
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
        cout<<"ѡ�����"<<endl;
    }
    
    this->save();
}


void workerManger::Clean_Emp()
{
    char flag;
    cout<<"ȷ��ɾ������y/n)"<<endl;
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
        cout<<"��� ��·������"<<endl;
    }
    else if (flag =='n')
    {
        /* code */
        cout<<"��ϲ���������"<<endl;
    }
    else{
        cout<<"�������"<<endl;
    }
    
}