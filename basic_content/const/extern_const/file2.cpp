#include<iostream>
/**
 * 未被 const 修饰的变量在不同文件的访问 
 * 
 * by 光城
 * compile: g++ -o file file2.cpp file1.cpp
 * execute: ./file
 */
extern int ext;
int main(){

    std::cout<<(ext+10)<<std::endl;
}
