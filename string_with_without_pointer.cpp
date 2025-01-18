/*
Author: Satish Akhade(satish.sva@gmail.com)
Below code provide use of conditional compilation for string having pointer operation and without pointer operation.
Added Output : Pass and Failed result
*/

#include <iostream>
#include "string.h"
using namespace std;
#define WITHPOINTER

int main(void){
    string s1[] = {
        "ABC",
        "PQR",
        "MNO",
        "XYZ"
    };
    int i,var, found=0;
    string s2;
    std::cout<< "Enter the new string to check"<<std::endl;
    getline(std::cin,s2);

    #ifdef WITHPOINTER //Compare two strig using pointer 
    string *strptr;
    strptr =s1;
    std::cout<< "compilation with pointer" << std::endl;
    std::cout<< "Number of string : "<<(sizeof(s1)/sizeof(string)) <<std::endl;
    std::cout<< "Entered string s2: "<<s2<<std::endl;
    for (i=0; i< (sizeof(s1)/sizeof(string)); i++,strptr++){
        std::cout<< "String s:"<<i<<" "<<*strptr<<std::endl;
        var=strptr->compare(s2);
        if(var==0)
        {
            std::cout<< "String matach found" << std::endl;
            found=0;
            break;
        }
        else{
            found=1;
        }
    }
    if(found==1){
        std::cout<< "String matach not found" << std::endl;
    }
    #else  //Compare string without pointer
    std::cout<< "compilation without pointer" << std::endl;     
    std::cout<< "Number of string : "<<(sizeof(s1)/sizeof(string)) <<std::endl;
    std::cout<< "Entered string s2: "<<s2<<std::endl;
    for (i=0; i< (sizeof(s1)/sizeof(string)); i++){
        std::cout<< "String s:"<<i<<" "<<s1[i]<<std::endl;
        string s3=s1[i];
        var=s3.compare(s2);
        if(var==0)
        {
            std::cout<< "String matach found" << std::endl;
            found=0;
            break;
        }
        else{
            found=1;
        }
    }
    if(found==1){
        std::cout<< "String matach not found" << std::endl;
    }
    #endif
    return 0;
}

//------------------------OutPut of Above Code---------------------
/*
//-------------------------Pass Condition----------------------
    //---------------------with pointer
    Enter the new string to check
    MNO
    Number of string : 4
    Entered string s2: MNO
    String s1: ABC
    String s1: PQR
    String s1: MNO
    String matach found
    //---------------------without pointer
    Enter the new string to check
    XYZ
    compilation without pointer
    Number of string : 4
    Entered string s2: XYZ
    String s1: ABC
    String s1: PQR
    String s1: MNO
    String s1: XYZ
    String matach found
    //-------------------------------------------
//-------------------------Fail Condition----------------------
    //---------------------with pointer
    Enter the new string to check
    kgh
    Number of string : 4
    Entered string s2: kgh
    String s1: ABC
    String s1: PQR
    String s1: MNO
    String s1: XYZ
    String matach not found
    //---------------------without pointer
    Enter the new string to check
    kgh
    compilation without pointer
    Number of string : 4
    Entered string s2: kgh
    String s1: ABC
    String s1: PQR
    String s1: MNO
    String s1: XYZ
    String matach not found

*/