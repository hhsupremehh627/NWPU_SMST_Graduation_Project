#include<iostream>
#include<vector>
#include<string>
#include<deque>
#include<algorithm>
#include<ctime>
#include<stack>
#include<queue>
using namespace std;


class Person
{
private:
    /* data */
public:
    string m_name;
    int m_score;
    Person(string name,int score)
    {
        this->m_name = name;
        this->m_score = score;
    }
    ~Person()
    {

    }
};


void creatperson(vector<Person>&v)
{
    for(int i=0;i<5;i++)
    {
        string name="选手";
        name += to_string(i);
        int score = 0;
        Person p(name,score);
        v.push_back(p);
    }
}

void setscore(vector<Person>&v)
{
    for(vector<Person>::iterator it=v.begin();it!=v.end();it++)
    {
        deque<int>d;
        for(int i=0;i<10;i++)
        {
            int score=rand()%41+60;
            d.push_back(score);
        }
        sort(d.begin(),d.end());

        d.pop_back();
        d.pop_front();
        int sum=0;
        for(deque<int>::iterator did=d.begin();did!=d.end();did++)
        {
           sum+=*did;
        }
        int avg = sum/d.size();
        it->m_score = avg;
    }
}

//栈不允许遍历
void test01()
{
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    while(!s.empty())
    {
        cout<<s.top()<<endl;
        s.pop();
    }
    cout<<s.size()<<endl;
}
//queue也不允许遍历 先入先出
void test02()
{
    queue<Person>q;
    Person p1("aa",30);
    Person p2("bb",40);
    Person p3("cc",20);
    q.push(p1);
    q.push(p2);
    q.push(p3);
    while(!q.empty())
    {
        cout<<q.front().m_name<<endl;
        cout<<q.back().m_name<<endl;
        q.pop();
        cout<<q.size()<<endl;
    }
}

int main()
{
    //srand((unsigned int)time(NULL));
    //vector<Person>v;
    //creatperson(v);
    test02();
    system("pause");
    return 0;
}