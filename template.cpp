/*
Author: Satish Akhade(satish.sva@gmail.com)
Below code provide the use of template functionality between class and functions
*/

#include <iostream>
#include "string.h"

template <class T1, class T2>
class MATH
{
    int a, b;

    public:
    MATH(T1 a , T2 b){
        std::cout << "value of a, b: "<<a<<","<<b<<std::endl;
    }
    void add(T1 a, T2 b)
    {
        std::cout<<"addition: " <<(a+b)<< std::endl;
    }
    void sub(T1 a, T2 b)
    {
        std::cout<<"Sub: " <<(a-b)<< std::endl;
    }
    void char_var(T1 a, T2 b)
    {
        std::cout<< "Char a: " << a <<" " << "char b: " << b <<std::endl;
    }
};

int main(void)
{
    MATH<int, int> math(1,2);
    math.add(10,20); //Random value
    MATH<char, char> math0('A','B');
    math0.char_var('P','Q');
    MATH<float,float> math1(0.5,0.5); //Random value
    math1.add(50.223,695.2566); //Random value
    math1.sub(356.25,25.985); //Random value
    return 0;
}

//-------------------------------Output of Above code------------------------------
/*
value of a, b: 1,2
addition: 30
value of a, b: A,B
Char a: P char b: Q
value of a, b: 0.5,0.5
addition: 745.48
Sub: 330.265
*/
