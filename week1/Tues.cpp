//��̬ ��̬�Ͷ�̬
// ��̬��̬���������غ���������� ���ú�����
// ��̬��̬����������麯��ʵ������ʱ��̬ ����ʱȷ��������ַ



// #include<iostream>
// using namespace std;

// class Animal
// {
// private:
//     /* data */
// public:
//     Animal(/* args */);
//     ~Animal();
//     //��̬��̬������
//     //1.�м̳й�ϵ
//     //2.����Ҫ��д������麯����speak������
//     virtual void speak()
//     {
//         cout<<"animal is speaking"<<endl;
//     }
// };

// Animal::Animal(/* args */)
// {
// }

// Animal::~Animal()
// {
// }

// class cat:public Animal
// {
// private:
//     /* data */
// public:
//     cat(/* args */);
//     ~cat();
//     void speak()
//     {
//         cout<<"cat is speaking"<<endl;
//     }
// };

// cat::cat(/* args */)
// {
// }

// cat::~cat()
// {
// }


// //Ӳ�� �ڱ����Ǿ��Ѿ��涨��animal��
// //��̬��̬ʹ�ã������ָ��������� ��������Ķ���
// void dospeak(Animal &animal)
// {
//     animal.speak();
// }
// void test01()
// {
//     cat c;
//     dospeak(c);
// }


// int main()
// {
//     test01();
//     cat c;
//     dospeak(c);
//     system("pause");
//     return 0;
// }


// #include<iostream>
// using namespace std;

// class Calculator
// {
// private:
//     /* data */
// public:
//     int m_num1;
//     int m_num2;
//     int getResult(string oper)
//     {
//         if(oper=="+")
//         {
//             return m_num1+m_num2;
//         }
//         else if(oper=="-")
//         {
//             return m_num1-m_num2;
//         }
//     }
//     //����ԭ�򣺶���չ���п��� ���޸Ľ��йر�
//     Calculator(/* args */);
//     ~Calculator();
// };

// Calculator::Calculator(/* args */)
// {
// }

// Calculator::~Calculator()
// {
// }

// class cal
// {
// private:
//     /* data */
// public:
//     virtual int getresult()
//     {
//         return 0;
//     }
//     int m_a;
//     int m_b;
//     cal(/* args */);
//     ~cal();
// };

// cal::cal(/* args */)
// {
// }

// cal::~cal()
// {
// }

// class add:public cal
// {
// public:
//     int getresult()
//     {
//         return m_a+m_b;
//     }
// };

// void test01()
// {
//     Calculator c;
//     c.m_num1=18;
//     c.m_num2=10;
//     cout<<c.getResult("+")<<endl;
// }

// int main()
// {
//     test01();
//     system("pause");
//     return 0;
// }


// //���麯���ͳ�����
// //virtual+��������+������+�β��б�=0��
// //�������麯�������Ϊ������
// //���������������д����Ĵ��麯��
// class Base
// {
// private:
//     /* data */
// public:
//     Base(/* args */);
//     ~Base();
//     virtual int hhh()=0;
// };

// #include<iostream>

// using namespace std;

// class AbstractDringking
// {
// private:
//     /* data */
// public:
//     AbstractDringking(/* args */);
//     ~AbstractDringking();
//     //��ˮ
//     virtual void Boil()=0;
//     //����
//     virtual void Brew()=0;
//     //���뱭��
//     virtual void PourInCup()=0;
//     //���븨��
//     virtual void PutSomething()=0;
//     void makeDrink()
//     {
//         Boil();
//         Brew();
//         PourInCup();
//         PutSomething();
//     }
// };

// AbstractDringking::AbstractDringking(/* args */)
// {
// }

// AbstractDringking::~AbstractDringking()
// {
// }

// class Coffee:public AbstractDringking
// {
// private:
//     /* data */
// public:
//     Coffee(/* args */);
//     ~Coffee();
//      //��ˮ
//     virtual void Boil()
//     {
//         cout<<"boiling water!(coffee)"<<endl;
//     }
//     //����
//     virtual void Brew()
//     {
//         cout<<"chong pao coffee"<<endl;
//     }
//     //���뱭��
//     virtual void PourInCup()
//     {
//         cout<<"put in cup"<<endl;
//     }
//     //���븨��
//     virtual void PutSomething()
//     {
//         cout<<"add suger"<<endl;
//     }
// };

// Coffee::Coffee(/* args */)
// {
// }

// Coffee::~Coffee()
// {
// }

// class Tea:public AbstractDringking
// {
// private:
//     /* data */
// public:
//     Tea(/* args */);
//     ~Tea();
//     //��ˮ
//     virtual void Boil()
//     {
//         cout<<"boiling water!(tea)"<<endl;
//     }
//     //����
//     virtual void Brew()
//     {
//         cout<<"chong pao tea"<<endl;
//     }
//     //���뱭��
//     virtual void PourInCup()
//     {
//         cout<<"put in cup"<<endl;
//     }
//     //���븨��
//     virtual void PutSomething()
//     {
//         cout<<"add lemon"<<endl;
//     }
// };

// Tea::Tea(/* args */)
// {
// }

// Tea::~Tea()
// {
// }

// void doWork(AbstractDringking* abs)
// {
//     abs->makeDrink();
//     delete abs;//��ֹ�����ڴ�й¶
//     abs = NULL;
// }

// void test01()
// {
//     doWork(new Coffee);
//     doWork(new Tea);
// }


// int main()
// {
//     test01();
//     system("pause");
//     return 0;
// }



//�������봿������
//���new���Ķ��������ͷ�����
// #include<iostream>

// using namespace std;



// int main()
// {
//     system("pause");
//     return 0;
// }



//������װʵ��
#include<iostream>
using namespace std;

//Step 1.��д���Ե�������� CPU GPU MEM
//ʹ������
class CPU
{
private:
    /* data */
public:
    CPU(/* args */);
    ~CPU();
    virtual void cpu()=0;
};

CPU::CPU(/* args */)
{
}

CPU::~CPU()
{
}

class GPU
{
private:
    /* data */
public:
    GPU(/* args */);
    ~GPU();
    virtual void gpu()=0;
};

GPU::GPU(/* args */)
{
}

GPU::~GPU()
{
}

class MEM
{
private:
    /* data */
public:
    MEM(/* args */);
    ~MEM();
    virtual void mem()=0;
};

MEM::MEM(/* args */)
{
}

MEM::~MEM()
{
}


//Step2���������� 
class Computer
{
private:
    /* data */
    CPU* a;
    GPU* b;
    MEM* c;
public:
    Computer(CPU*,GPU*,MEM*);
    virtual ~Computer();
    void work()
    {
        a->cpu();
        b->gpu();
        c->mem();
    }
};

Computer::Computer(CPU* a,GPU* b, MEM* c)
{
    cout<<"��ʼ��װ���ԣ� "<<endl;
    this->a = a;
    this->b = b;
    this->c = c;
}

Computer::~Computer()
{
    if(a!=NULL)
    {
        delete a;
        a = NULL;
    }
    if(b!=NULL)
    {
        delete b;
        b = NULL;
    }
    if(c!=NULL)
    {
        delete c;
        c = NULL;
    }
}

//Step3.�Ծ���ĳ��̽���ʵ��
class IntelCPU:public CPU
{
private:
    /* data */
public:
    IntelCPU(/* args */);
    ~IntelCPU();
    void cpu()
    {
        cout<<"using Intel CPU!"<<endl;
    }
};

IntelCPU::IntelCPU(/* args */)
{
}

IntelCPU::~IntelCPU()
{
}

class IntelGPU:public GPU
{
private:
    /* data */
public:
    IntelGPU(/* args */);
    ~IntelGPU();
    void gpu()
    {
        cout<<"using Intel GPU!"<<endl;
    }
};

IntelGPU::IntelGPU(/* args */)
{
}

IntelGPU::~IntelGPU()
{
}

class IntelMEM:public MEM
{
private:
    /* data */
public:
    IntelMEM(/* args */);
    ~IntelMEM();
    void mem()
    {
        cout<<"using Intel MEM!"<<endl;
    }
};

IntelMEM::IntelMEM(/* args */)
{
}

IntelMEM::~IntelMEM()
{
}

class LenovoCPU:public CPU
{
private:
    /* data */
public:
    void cpu()
    {
        cout<<"using Lenovo CPU"<<endl;
    }
};

class LenovoGPU:public GPU
{
private:
    /* data */
public:
    void cpu()
    {
        cout<<"using Lenovo GPU"<<endl;
    }
};

class LenovoMEM:public MEM
{
private:
    /* data */
public:
    void mem()
    {
        cout<<"using Lenovo MEM"<<endl;
    }
};

void test01()
{
    CPU* intelcpu = new IntelCPU;
    GPU* intelgpu = new IntelGPU;
    MEM* intelmem = new IntelMEM;
    Computer* com = new Computer(intelcpu,intelgpu,intelmem);
    com->work();
    delete com;
}


int main()
{
    test01();
    system("pause");
    return 0;
}
