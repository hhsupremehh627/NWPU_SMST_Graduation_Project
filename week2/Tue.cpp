#include<iostream>
#include"MyArray.hpp"
 using namespace std;


void test01()
{
    MyArray<int> arr1(5);
    MyArray<int> arr2(arr1);
    MyArray<int> arr3(100);
    arr3 =arr1;
    for(int i=0;i<5;i++)
    {
        arr1.PushBack(i);
    }
    cout<<arr1[2];
}


 int main()
 {
     test01();
    system("pause");
    return 0;
 }
