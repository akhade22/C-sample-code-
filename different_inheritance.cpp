/*
Author: Satish Akhade(satish.sva@gmail.com)
Below code provide the different way of inheritance with nested conditional compilation
*/

#include <iostream>
#include "string.h"
/*
#define INHERITANCE MULTIPLE // MULTILEVEL 
#ifdef OTHER
    #define INHERITANCE MULTIPLE
    #define INHERITANCE HIERARCHICAL
    #define INHERITANCE HYBRID 
#endif
*/
#define INHERITANCE_MULTILEVEL 
#define INHERITANCE_MULTIPLE
#define INHERITANCE_HIERARCHICAL
#define INHERITANCE_HYBRID 

int multilevel(void);
int multiple(void);
int hierarchical(void);
int hybrid(void);

// Multilevel inheritance
class ABC_MULTILEVEL
{
    public:
    ABC_MULTILEVEL(){
        std::cout<< "ABC_MULTILEVEL constuctor called" <<std::endl;        
    }
    ~ABC_MULTILEVEL(){
        std::cout<< "ABC_MULTILEVEL destructors called" <<std::endl;
    }
    void func_abc(void){
        std::cout << "abc_fuction" << std::endl;
    }
};

class PQR_MULTILEVEL : public ABC_MULTILEVEL
{
    
    public:
    PQR_MULTILEVEL(){
        std::cout<< "PQR_MULTILEVEL constuctor called" <<std::endl;        
    }
    ~PQR_MULTILEVEL(){
        std::cout<< "PQR_MULTILEVEL destructors called" <<std::endl;
    }
    void func_pqr(void){
        std::cout << "pqr_function" << std::endl;
    }
};

class XYZ_MULTILEVEL :public PQR_MULTILEVEL
{
    public:
    XYZ_MULTILEVEL(){
        std::cout<< "XYZ_MULTILEVEL constuctor called" <<std::endl;        
    }
    ~XYZ_MULTILEVEL(){
        std::cout<< "XYZ_MULTILEVEL destructors called" <<std::endl;
    }
    void func_xyz(void){
        std::cout << "xyz_function" << std::endl;
    }
};

int multilevel(void)
{
    XYZ_MULTILEVEL xyz;
    xyz.func_abc();
    xyz.func_pqr();
    xyz.func_xyz();
    PQR_MULTILEVEL pqr;
    pqr.func_pqr();
    pqr.func_abc();
    ABC_MULTILEVEL abc;
    abc.func_abc();
    return 0;
}

//Multiple Inheritance
class ABC_MULTIPLE
{
    public:
    ABC_MULTIPLE(){
        std::cout<< "ABC_MULTIPLE constuctor called" <<std::endl;        
    }
    ~ABC_MULTIPLE(){
        std::cout<< "ABC_MULTIPLE destructors called" <<std::endl;
    }
    void func_abc(void){
        std::cout << "abc_fuction" << std::endl;
    }
};

class RST_MULTIPLE
{
    public:
    RST_MULTIPLE(){
        std::cout<< "RST_MULTIPLE constuctor called" <<std::endl;        
    }
    ~RST_MULTIPLE(){
        std::cout<< "RST_MULTIPLE destructors called" <<std::endl;
    }
    void func_rst(void){
        std::cout << "rst_function" << std::endl;
    }
};

class PQR_MULTIPLE
{
    public:
    PQR_MULTIPLE(){
        std::cout<< "PQR_MULTIPLE constuctor called" <<std::endl;        
    }
    ~PQR_MULTIPLE(){
        std::cout<< "PQR_MULTIPLE destructors called" <<std::endl;
    }
    void func_pqr(void){
        std::cout << "pqr_function" << std::endl;
    }
};

class XYZ_MULTIPLE :public PQR_MULTIPLE , public RST_MULTIPLE, public ABC_MULTIPLE
{
    public:
    XYZ_MULTIPLE(){
        std::cout<< "XYZ_MULTIPLE constuctor called" <<std::endl;        
    }
    ~XYZ_MULTIPLE(){
        std::cout<< "XYZ_MULTIPLE destructors called" <<std::endl;
    }
    void func_xyz(void){
        std::cout << "xyz_function" << std::endl;
    }
};

int multiple(void)
{
    XYZ_MULTIPLE xyz;
    xyz.func_abc();
    xyz.func_pqr();
    xyz.func_xyz();
    xyz.func_rst();
    ABC_MULTIPLE abc;
    abc.func_abc();
    return 0;
}

//Hierarchical inheritnace 
class ABC_HIERARCHICAL 
{
    public:
    ABC_HIERARCHICAL(){
        std::cout<< "ABC_HIERARCHICAL constuctor called" <<std::endl;        
    }
    ~ABC_HIERARCHICAL(){
        std::cout<< "ABC_HIERARCHICAL destructors called" <<std::endl;
    }
    void func_abc(void){
        std::cout << "abc_fuction" << std::endl;
    }
};

class RST_HIERARCHICAL : public ABC_HIERARCHICAL
{
    public:
    RST_HIERARCHICAL(){
        std::cout<< "RST_HIERARCHICAL constuctor called" <<std::endl;        
    }
    ~RST_HIERARCHICAL(){
        std::cout<< "RST_HIERARCHICAL destructors called" <<std::endl;
    }
    void func_rst(void){
        std::cout << "rst_function" << std::endl;
    }
};

class PQR_HIERARCHICAL : public ABC_HIERARCHICAL
{
    public:
    PQR_HIERARCHICAL(){
        std::cout<< "PQR_HIERARCHICAL constuctor called" <<std::endl;        
    }
    ~PQR_HIERARCHICAL(){
        std::cout<< "PQR_HIERARCHICAL destructors called" <<std::endl;
    }
    void func_pqr(void){
        std::cout << "pqr_function" << std::endl;
    }
};

class MNO_HIERARCHICAL :public PQR_HIERARCHICAL
{
    public:
    MNO_HIERARCHICAL(){
        std::cout<< "MNO_HIERARCHICAL constuctor called" <<std::endl;        
    }
    ~MNO_HIERARCHICAL(){
        std::cout<< "MNO_HIERARCHICAL destructors called" <<std::endl;
    }
    void func_mno(void){
        std::cout << "MNO_HIERARCHICAL_function" << std::endl;
    }
};

class XYZ_HIERARCHICAL :public PQR_HIERARCHICAL
{
    public:
    XYZ_HIERARCHICAL(){
        std::cout<< "XYZ_HIERARCHICAL constuctor called" <<std::endl;        
    }
    ~XYZ_HIERARCHICAL(){
        std::cout<< "XYZ_HIERARCHICAL destructors called" <<std::endl;
    }
    void func_xyz(void){
        std::cout << "xyz_function" << std::endl;
    }
};

int hierarchical(void)
{
   MNO_HIERARCHICAL mno;
   mno.func_abc();
   mno.func_mno();
   mno.func_pqr();
   XYZ_HIERARCHICAL xyz;
   xyz.func_abc();
   xyz.func_pqr();
   xyz.func_xyz();
   RST_HIERARCHICAL rst;
   rst.func_abc();
   rst.func_rst();
    return 0;
}

//HYBRID
class ABC_HYBRID
{
    public:
    ABC_HYBRID(){
        std::cout<< "ABC_HYBRID constuctor called" <<std::endl;        
    }
    ~ABC_HYBRID(){
        std::cout<< "ABC_HYBRID destructors called" <<std::endl;
    }
    void func_abc(void){
        std::cout << "abc_fuction" << std::endl;
    }
};

class RST_HYBRID : public ABC_HYBRID
{
    public:
    RST_HYBRID(){
        std::cout<< "RST_HYBRID constuctor called" <<std::endl;        
    }
    ~RST_HYBRID(){
        std::cout<< "RST_HYBRID destructors called" <<std::endl;
    }
    void func_rst(void){
        std::cout << "rst_function" << std::endl;
    }
};

class PQR_HYBRID : public RST_HYBRID
{
    public:
    PQR_HYBRID(){
        std::cout<< "PQR_HYBRID constuctor called" <<std::endl;        
    }
    ~PQR_HYBRID(){
        std::cout<< "PQR_HYBRID destructors called" <<std::endl;
    }
    void func_pqr(void){
        std::cout << "pqr_function" << std::endl;
    }
};

class MNO_HYBRID
{
    public:
    MNO_HYBRID(){
        std::cout<< "MNO_HYBRID constuctor called" <<std::endl;        
    }
    ~MNO_HYBRID(){
        std::cout<< "MNO_HYBRID destructors called" <<std::endl;
    }
    void func_mno(void){
        std::cout << "mno_function" << std::endl;
    }
};

class XYZ_HYBRID :public PQR_HYBRID, public MNO_HYBRID
{
    public:
    XYZ_HYBRID(){
        std::cout<< "XYZ_HYBRID constuctor called" <<std::endl;        
    }
    ~XYZ_HYBRID(){
        std::cout<< "XYZ_HYBRID destructors called" <<std::endl;
    }
    void func_xyz(void){
        std::cout << "xyz_function" << std::endl;
    }
};

int hybrid(void)
{
    XYZ_HYBRID xyz;
    xyz.func_abc();
    xyz.func_rst();
    xyz.func_pqr();
    xyz.func_mno();
    xyz.func_xyz();
    MNO_HYBRID mno;
    mno.func_mno();
    PQR_HYBRID pqr;
    pqr.func_abc();
    pqr.func_pqr();
    pqr.func_rst();
    RST_HYBRID rst;
    rst.func_abc();
    rst.func_rst();
    return 0;
}

int main(void)
{
#ifdef INHERITANCE_MULTILEVEL // Multilevel inheritance
    std::cout << "<-------------------Multiplevel-------------------------->"<<std::endl;
    multilevel();
#endif

#ifdef INHERITANCE_MULTIPLE //Multiple Inheritance
    std::cout << "<-------------------Multiple-------------------------->"<<std::endl;
    multiple();
#endif

#ifdef INHERITANCE_HIERARCHICAL //Hierarchical inheritnace 
    std::cout << "<-------------------Hierarchical-------------------------->"<<std::endl;
    hierarchical();
#endif

#ifdef INHERITANCE_HYBRID  //Hybrid inheritance 
    std::cout << "<-------------------Hybrid-------------------------->"<<std::endl;
    hybrid();
#endif
}

//---------------------------------OutPut: of above code ------------------------------------------
/*
<-------------------Multiplevel-------------------------->
ABC_MULTILEVEL constuctor called
PQR_MULTILEVEL constuctor called
XYZ_MULTILEVEL constuctor called
abc_fuction
pqr_function
xyz_function
ABC_MULTILEVEL constuctor called
PQR_MULTILEVEL constuctor called
pqr_function
abc_fuction
ABC_MULTILEVEL constuctor called
abc_fuction
ABC_MULTILEVEL destructors called
PQR_MULTILEVEL destructors called
ABC_MULTILEVEL destructors called
XYZ_MULTILEVEL destructors called
PQR_MULTILEVEL destructors called
ABC_MULTILEVEL destructors called
<-------------------Multiple-------------------------->
PQR_MULTIPLE constuctor called
RST_MULTIPLE constuctor called
ABC_MULTIPLE constuctor called
XYZ_MULTIPLE constuctor called
abc_fuction
pqr_function
xyz_function
rst_function
ABC_MULTIPLE constuctor called
abc_fuction
ABC_MULTIPLE destructors called
XYZ_MULTIPLE destructors called
ABC_MULTIPLE destructors called
RST_MULTIPLE destructors called
PQR_MULTIPLE destructors called
<-------------------Hierarchical-------------------------->
ABC_HIERARCHICAL constuctor called
PQR_HIERARCHICAL constuctor called
MNO_HIERARCHICAL constuctor called
abc_fuction
MNO_HIERARCHICAL_function
pqr_function
ABC_HIERARCHICAL constuctor called
PQR_HIERARCHICAL constuctor called
XYZ_HIERARCHICAL constuctor called
abc_fuction
pqr_function
xyz_function
ABC_HIERARCHICAL constuctor called
RST_HIERARCHICAL constuctor called
abc_fuction
rst_function
RST_HIERARCHICAL destructors called
ABC_HIERARCHICAL destructors called
XYZ_HIERARCHICAL destructors called
PQR_HIERARCHICAL destructors called
ABC_HIERARCHICAL destructors called
MNO_HIERARCHICAL destructors called
PQR_HIERARCHICAL destructors called
ABC_HIERARCHICAL destructors called
<-------------------Hybrid-------------------------->
ABC_HYBRID constuctor called
RST_HYBRID constuctor called
PQR_HYBRID constuctor called
MNO_HYBRID constuctor called
XYZ_HYBRID constuctor called
abc_fuction
rst_function
pqr_function
mno_function
xyz_function
MNO_HYBRID constuctor called
mno_function
ABC_HYBRID constuctor called
RST_HYBRID constuctor called
PQR_HYBRID constuctor called
abc_fuction
pqr_function
rst_function
ABC_HYBRID constuctor called
RST_HYBRID constuctor called
abc_fuction
rst_function
RST_HYBRID destructors called
ABC_HYBRID destructors called
PQR_HYBRID destructors called
RST_HYBRID destructors called
ABC_HYBRID destructors called
MNO_HYBRID destructors called
XYZ_HYBRID destructors called
MNO_HYBRID destructors called
PQR_HYBRID destructors called
RST_HYBRID destructors called
ABC_HYBRID destructors called
*/