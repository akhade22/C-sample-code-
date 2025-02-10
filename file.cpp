/*
Author: Satish Akhade(satish.sva@gmail.com)
Below simple code provide details how to use file to read and write contain/text in the cpp.
*/

#include<iostream>
#include<fstream>

using namespace std;

int main(void){
    ofstream fout;
    fout.open("File1");
    fout << "Hi/hello how are you?";
    fout.close();

    const int n=100;
    char line[n];

    ifstream fin;
    fin.open("File1");
    std::cout<<"Contain of file1" <<std::endl;
    while(fin){

        fin.getline(line, n);
        std::cout<<line <<std::endl;;
    }
    fin.close();
    return 0;
}

//------------------output-----------
//it will generate file1 file in the same directory with below text
/*
Hi/hello how are you?
*/
