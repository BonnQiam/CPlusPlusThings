#include <iostream>
using namespace std;
void temperature(int t) {

  if (t == 100)
    throw "100 degree";
  else if (t == 0)
    throw "0 degree";
  else {
    cout << "temperatore=" << t << endl;
  }
}
int main() {
  try {
    temperature(0);   // L1
    temperature(10);  // L2
    temperature(100); // L3
  } catch (char const *s) {
    cout << s << endl;
  }
  
  return 0;
}
