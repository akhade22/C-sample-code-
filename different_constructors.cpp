/*
Author: Satish Akhade(satish.sva@gmail.com)
Below code provide the details of differet type of constructors
and usages 
*/

#include<iostream>
#include"string.h"
using namespace std;

class TS
{
    private:
        string name;
        int age;
    public:
        TS():name("Dog"), age(60)
        {
            std::cout << "First constructor"<<std::endl;
            std::cout << "Name :" << TS::name <<std::endl;
            std::cout << "Age :" << TS::age <<std::endl;
        }
        ~TS(){
            std::cout << "First destructor"<< std::endl;
        }
        TS(string name, int age); //: name("Dog"), age(60){}
        TS(TS &ts);
};

TS::TS(string name, int age )
{
    this->age= age;

    string name2 = "End";
    this ->name = name + " " + name2 ;
    std::cout<< "Second constructor called "<< std::endl;
    std::cout << "Full Name: " << this->name <<std::endl;
    std::cout << "Age: " << this->age <<std::endl;
}

TS::TS(TS &ts){
    ts.age=50;
    ts.name=" Master Mind";
    std::cout << "Name :" << ts.name <<std::endl;
    std::cout << "Age :" << ts.age <<std::endl;
}

int main(void)
{
    TS ts1; //First 
    TS ts2("Master", 30); //Second
    TS ts3(ts2);  // Third
    return 0;
}

//--------------------OutPut Of Above code ----------
/*
First constructor
Name :Dog
Age :60
Second constructor called
Full Name: Master End
Age: 30
Name : Master Mind
Age :50
First destructor
First destructor
First destructor
*/