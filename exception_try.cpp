#include<iostream>
using namespace std;

int main(void){
    int a=100;
    int b=100;
    try{
        if(a>b){
            std::cout << "a>b"<<std::endl;
            throw 1;
        }else if(a<b){
            std::cout << "a<b"<<std::endl;
            throw 1.0;
        }
        else{
            throw 'p';
        }
    }
    catch(int i){
        std::cout << "Execption error at int"<<std::endl;
    }
    catch(double i){
        std::cout << "Execption error at double"<<std::endl;
    }
    catch(char i){
        std::cout << "Execption error at char"<<std::endl;
    }

    return 0;
}

//--------------------Output-------------
/*
//input a=1400, b=200 
a>b
Execption error at int
------------------------------------
//input a=100, b=200 
a<b
Execption error at double
------------------------------
//input a=100, b=100 
Execption error at char
-----------------------------------
*/