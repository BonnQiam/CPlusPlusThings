#include<iostream>
/**
 * 未被 const 修饰的变量在不同文件的访问
 * 
 * by 光城
 * compile: g++ -o file const_file2.cpp const_file1.cpp
 * execute: ./file
 */
extern const int ext;

//const int ext;
int main(){

    std::cout<<ext<<std::endl;
}
