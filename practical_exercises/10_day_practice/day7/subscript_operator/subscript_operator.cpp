/* 重载[]运算符 */
// Eg8-9.cpp
#include <cstring>
#include <iostream>
using namespace std;
struct Person { //职工基本信息的结构
  double salary;
  char *name;
};
class SalaryManaege {
  Person *employ; //存放职工信息的数组
  int max;        //数组下标上界
  int n;          //数组中的实际职工人数
public:
  SalaryManaege(int Max = 0) {
    max = Max;
    n = 0;
    employ = new Person[max];
  }
  double &operator[](char *Name) { //重载[]，返回引用
    Person *p;
    for (p = employ; p < employ + n; p++)
      //如果存在处理
      if (strcmp(p->name, Name) == 0)
        return p->salary;
    //不存在情况处理
    p = employ + n++;
    p->name = new char[strlen(Name) + 1];
    strcpy(p->name, Name);
    p->salary = 0;
    return p->salary;
  }

  void display() {
    for (int i = 0; i < n; i++)
      cout << employ[i].name << "   " << employ[i].salary << endl;
  }
};
int main() {
  SalaryManaege s(3);
  s["a"] = 2188.88;
  s["b"] = 1230.07;
  s["c"] = 3200.97;
  cout << "a\t" << s["a"] << endl;
  cout << "b\t" << s["b"] << endl;
  cout << "c\t" << s["c"] << endl;

  cout << "-------Output of display--------\n\n";
  s.display();
  
}
