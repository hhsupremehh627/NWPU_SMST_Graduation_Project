#include<iostream>
#include<fstream>
#include"workerManger.h"
#include<fstream>
using namespace std;

//ʹ�ù�����workerManger

int main()
{
    workerManger Mune;
    int choice=0;
    while (true)
    {
        Mune.ShowMenu();
        cout<<"����������ѡ��"<<endl;
        cin>>choice;
        switch (choice)
        {
        case 0:
            Mune.ExitMenu();
            break;
        case 1:
            Mune.Add_Emp();
            break;
        case 2:
            Mune.show_Emp();
            break;
        case 3:
            Mune.Del_Emp();
            break;
        case 4:
            Mune.Change_Emp();
            break;
        case 5:
            Mune.Find_Emp();
            break;
        case 6:
            Mune.Sort_Emp();
            break;
        case 7:
            Mune.Clean_Emp();
            break;
        default:
            cout<<"�������� ������0-7����"<<endl;
            break;
        }
    }
    
    system("pause");
    return 0;
}