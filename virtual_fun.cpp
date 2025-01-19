/*
Author: Satish Akhade(satish.sva@gmail.com)
Below code provide the use of virtual function between Base class and drive class
*/

#include<iostream>
#include"string.h"

class ABC 
{
    public:
    void show(void){
        std::cout<<"Show abc func" <<std::endl;
    }
    virtual void display(void)
    {
        std::cout<<"display abc func" <<std::endl;
    }
};

class XYZ: public ABC  
{
    public:
    void show(void)
    {
    std::cout<<"Show xyz func" <<std::endl;
    }
    void display(void)
    {
        std::cout<<"display xyz func" <<std::endl;
    }
};

int main(void){

    ABC *abc;
    XYZ xyz;
    ABC abc1;
    abc=&abc1;
    abc->display(); //base class
    abc->show(); //base class
    abc = &xyz;
    abc->display(); //drive class
    abc->show();  //base class
    return 0;
}

//-----------------------------------OutPut Function-------------------
/*
display abc func
Show abc func
display abc func
Show xyz func
*/
