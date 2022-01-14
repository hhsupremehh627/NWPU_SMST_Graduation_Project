//多态 静态和动态
// 静态多态：函数重载和运算符重载 复用函数名
// 动态多态：派生类和虚函数实现运行时多态 运行时确定函数地址



// #include<iostream>
// using namespace std;

// class Animal
// {
// private:
//     /* data */
// public:
//     Animal(/* args */);
//     ~Animal();
//     //动态多态条件：
//     //1.有继承关系
//     //2.子类要重写父类的虚函数（speak函数）
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


// //硬绑定 在编译是就已经规定是animal类
// //动态多态使用：父类的指针或者引用 调用子类的对象
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
//     //开闭原则：对扩展进行开放 对修改进行关闭
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


// //纯虚函数和抽象类
// //virtual+数据类型+函数名+形参列表=0；
// //包含纯虚函数的类称为抽象类
// //抽象类子类必须重写父类的纯虚函数
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
//     //煮水
//     virtual void Boil()=0;
//     //冲泡
//     virtual void Brew()=0;
//     //倒入杯中
//     virtual void PourInCup()=0;
//     //加入辅料
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
//      //煮水
//     virtual void Boil()
//     {
//         cout<<"boiling water!(coffee)"<<endl;
//     }
//     //冲泡
//     virtual void Brew()
//     {
//         cout<<"chong pao coffee"<<endl;
//     }
//     //倒入杯中
//     virtual void PourInCup()
//     {
//         cout<<"put in cup"<<endl;
//     }
//     //加入辅料
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
//     //煮水
//     virtual void Boil()
//     {
//         cout<<"boiling water!(tea)"<<endl;
//     }
//     //冲泡
//     virtual void Brew()
//     {
//         cout<<"chong pao tea"<<endl;
//     }
//     //倒入杯中
//     virtual void PourInCup()
//     {
//         cout<<"put in cup"<<endl;
//     }
//     //加入辅料
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
//     delete abs;//防止堆区内存泄露
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



//虚析构与纯虚析构
//解决new出的堆区数据释放问题
// #include<iostream>

// using namespace std;



// int main()
// {
//     system("pause");
//     return 0;
// }



//电脑组装实践
#include<iostream>
using namespace std;

//Step 1.编写电脑的零件基类 CPU GPU MEM
//使用虚类
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


//Step2构建电脑类 
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
    cout<<"开始组装电脑： "<<endl;
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

//Step3.对具体的厂商进行实现
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
