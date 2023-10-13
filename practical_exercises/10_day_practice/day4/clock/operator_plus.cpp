/* 重载++的时钟.cpp */
/*
设计一个时钟类，能够记录时、分、秒，重载它的++运算符，每执行一次++运算，加时1秒，但要使计时过程能够自动进位。
*/
#include <iostream>
using namespace std;
class Time {
public:
  Time(int h = 0, int m = 0, int s = 0) {
    hour = h;
    minute = m;
    second = s;
  }
  Time operator++();// `++` 为前置运算时，它的运算符重载函数的一般格式
  Time operator++(int);//`++` 为后置运算时，它的运算符重载函数的一般格式
  void showTime() {
    cout << "Now time:" << hour << ":" << minute << ":" << second << endl;
  }

private:
  int hour, minute, second;
};
Time Time::operator++(int nz) {
  Time tmp = *this;
  ++(*this);
  return tmp;
}
Time Time::operator++() {
  ++second;
  if (second == 60) {
    second = 0;
    ++minute;
    if (minute == 60) {
      minute = 0;
      hour++;
      if (hour == 24) {
        hour = 0;
      }
    }
  }
  return *this;
}

int main(int argc, char const *argv[]) {
  Time t(23, 59, 59);
  ++t;
  t.showTime();
  (t++).showTime();
  t.showTime();
  
  return 0;
}
